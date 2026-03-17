/*
nvcc main.cu -o program.exe -std=c++17

python generate_test_data.py

program.exe input.txt output.txt
program.exe small_input.txt blank_output.txt


*/

#include "wb.h"
#include <iostream>

#define NUM_BINS 4096
#define BLOCK_SIZE 256

#define CUDA_CHECK(ans)                                                   \
  { gpuAssert((ans), __FILE__, __LINE__); }

inline void gpuAssert(cudaError_t code, const char *file, int line,
                      bool abort = true) {
  if (code != cudaSuccess) {
    fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code),
            file, line);
    if (abort)
      exit(code);
  }
}

// -----------------------------------------------------------
// Ядро вычисления гистограммы с насыщением
// -----------------------------------------------------------

// super dumb
__global__ void histogramKernel(unsigned int *input,
                                    unsigned int *bins,
                                    int inputLength) {

  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  if (idx < inputLength) {
    atomicAdd(&bins[input[idx]], 1);
  }
}


//С циклом
/*
__global__ void histogramKernel(unsigned int *input,
                                unsigned int *bins,
                                int inputLength) {

  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  for (int i = idx; i < inputLength; i += stride) {
    unsigned int value = input[i];

    // Атомарное увеличение
    unsigned int old = atomicAdd(&(bins[value]), 1);

    // Насыщение до 127
    //if (old >= 127) {
    //  bins[value] = 127;
    //}
  }
}
*/

// Optimised* (actually not?)
/*
__global__ void histogramKernel(unsigned int *input,
                                         unsigned int *globalBins,
                                         int inputLength) {

  __shared__ unsigned int localBins[NUM_BINS];

  // Инициализация shared памяти
  for (int i = threadIdx.x; i < NUM_BINS; i += blockDim.x) {
    localBins[i] = 0;
  }
  __syncthreads();

  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  // Заполнение локальной гистограммы
  for (int i = idx; i < inputLength; i += stride) {
    unsigned int value = input[i];
    atomicAdd(&localBins[value], 1);
  }

  __syncthreads();

  // Слияние в глобальную память
  for (int i = threadIdx.x; i < NUM_BINS; i += blockDim.x) {
    unsigned int val = localBins[i];
    if (val > 0) {
      unsigned int old = atomicAdd(&globalBins[i], val);

      // Насыщение
      //if (old + val > 127) {
      //  globalBins[i] = 127;
      //}
    }
  }
}
*/

// -----------------------------------------------------------

int main(int argc, char *argv[]) {
  wbArg_t args;
  int inputLength;
  unsigned int *hostInput;
  unsigned int *hostBins;
  unsigned int *deviceInput;
  unsigned int *deviceBins;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput = (unsigned int *)wbImport(wbArg_getInputFile(args, 0),
                                       &inputLength); // АТА! Что в методичку пихнули???
  hostBins = (unsigned int *)malloc(NUM_BINS * sizeof(unsigned int));
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The input length is ", inputLength);
  
  // Hello from spaghetti industries!
  for(int i = 0; i < inputLength; ++i){
	float temp;
    memcpy(&temp, &hostInput[i], sizeof(float));
	hostInput[i] = static_cast<unsigned int>(temp);
  }
  
  wbLog(TRACE, "The number of bins is ", NUM_BINS);

  wbTime_start(GPU, "Allocating GPU memory.");
  //@@ Выделите память GPU
  CUDA_CHECK(cudaMalloc((void **)&deviceInput,
                        inputLength * sizeof(unsigned int)));
  CUDA_CHECK(cudaMalloc((void **)&deviceBins,
                        NUM_BINS * sizeof(unsigned int)));

  CUDA_CHECK(cudaMemset(deviceBins, 0,
                        NUM_BINS * sizeof(unsigned int)));

  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");
  //@@ Скопируйте память с хоста на GPU
  CUDA_CHECK(cudaMemcpy(deviceInput, hostInput,
                        inputLength * sizeof(unsigned int),
                        cudaMemcpyHostToDevice));

  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  // ----------------------------------------------------------
  wbLog(TRACE, "Launching kernel");
  wbTime_start(Compute, "Performing CUDA computation");

  //@@ Выполните вычисления в ядре
  int gridSize = (inputLength + BLOCK_SIZE - 1) / BLOCK_SIZE;

  histogramKernel<<<gridSize, BLOCK_SIZE>>>(deviceInput,
                                            deviceBins,
                                            inputLength);

  CUDA_CHECK(cudaDeviceSynchronize());

  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");
  //@@ Скопируйте память обратно с GPU на хост
  CUDA_CHECK(cudaMemcpy(hostBins, deviceBins,
                        NUM_BINS * sizeof(unsigned int),
                        cudaMemcpyDeviceToHost));

  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(Copy, "Copying output memory to the CPU");

  wbTime_start(GPU, "Freeing GPU Memory");
  //@@ Освободите память GPU
  CUDA_CHECK(cudaFree(deviceInput));
  CUDA_CHECK(cudaFree(deviceBins));
  wbTime_stop(GPU, "Freeing GPU Memory");

  wbSolution(args, hostBins, NUM_BINS);

  free(hostBins);
  free(hostInput);
  return 0;
}