/*
nvcc main.cu -o program.exe -std=c++17

python generate_input_data.py

program.exe input.txt expected.txt
program.exe small_input.txt blank_output.txt
*/

#include "wb.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_BINS 256

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

// CUDA kernel
__global__ void histogramKernel(unsigned char *input, unsigned int *bins, int length) {

  __shared__ unsigned int localBins[NUM_BINS];

  int tid = threadIdx.x;
  int gid = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;

  // Инициализация shared histogram
  for (int i = tid; i < NUM_BINS; i += blockDim.x) {
    localBins[i] = 0;
  }

  __syncthreads();

  // Построение локальной гистограммы
  for (int i = gid; i < length; i += stride) {
    unsigned char value = input[i];
    atomicAdd(&(localBins[value]), 1);
  }

  __syncthreads();

  // Слияние в глобальную гистограмму
  for (int i = tid; i < NUM_BINS; i += blockDim.x) {
    atomicAdd(&(bins[i]), localBins[i]);
  }
}

int main(int argc, char *argv[]) {
  wbArg_t args;
  int inputLength;

  unsigned int *hostBins;

  unsigned char *deviceInput;
  unsigned int *deviceBins;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");

	unsigned char *hostInput;

	FILE *f = fopen(wbArg_getInputFile(args, 0), "r");

	if (!f) {
		printf("Cannot open input file\n");
		exit(1);
	}

	// читаем количество элементов
	fscanf(f, "%d", &inputLength);

	hostInput = (unsigned char *)malloc(inputLength * sizeof(unsigned char));

	// читаем символы
	for (int i = 0; i < inputLength; i++) {
		char c;
		fscanf(f, " %c", &c);   // пробел перед %c пропускает whitespace
		hostInput[i] = (unsigned char)c;
	}

	fclose(f);
  
  
  hostBins = (unsigned int *)malloc(NUM_BINS * sizeof(unsigned int));

  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The input length is ", inputLength);
  wbLog(TRACE, "The number of bins is ", NUM_BINS);

  wbTime_start(GPU, "Allocating GPU memory.");

  CUDA_CHECK(cudaMalloc((void **)&deviceInput, inputLength * sizeof(unsigned char)));
  CUDA_CHECK(cudaMalloc((void **)&deviceBins, NUM_BINS * sizeof(unsigned int)));

  CUDA_CHECK(cudaMemset(deviceBins, 0, NUM_BINS * sizeof(unsigned int)));

  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");

  CUDA_CHECK(cudaMemcpy(deviceInput, hostInput,
                        inputLength * sizeof(unsigned char),
                        cudaMemcpyHostToDevice));

  CUDA_CHECK(cudaDeviceSynchronize());
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  // Запуск ядра
  wbLog(TRACE, "Launching kernel");
  wbTime_start(Compute, "Performing CUDA computation");

  int blockSize = 256;
  int gridSize = (inputLength + blockSize - 1) / blockSize;

  histogramKernel<<<gridSize, blockSize>>>(deviceInput, deviceBins, inputLength);

  CUDA_CHECK(cudaDeviceSynchronize());

  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");

  CUDA_CHECK(cudaMemcpy(hostBins, deviceBins,
                        NUM_BINS * sizeof(unsigned int),
                        cudaMemcpyDeviceToHost));

  CUDA_CHECK(cudaDeviceSynchronize());

  wbTime_stop(Copy, "Copying output memory to the CPU");

  wbTime_start(GPU, "Freeing GPU Memory");

  CUDA_CHECK(cudaFree(deviceInput));
  CUDA_CHECK(cudaFree(deviceBins));

  wbTime_stop(GPU, "Freeing GPU Memory");

  // Проверка корректности результатов
  wbSolution(args, hostBins, NUM_BINS);

  free(hostBins);
  free(hostInput);

  return 0;
}