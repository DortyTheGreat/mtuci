/*
nvcc main.cu -o program.exe -std=c++17

program.exe simple_input.txt simple_stud.txt
program.exe simple_input.txt simple_output.txt
*/

#include "wb.h"

#define BLOCK_SIZE 512

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      wbLog(ERROR, "Got CUDA error ...  ", cudaGetErrorString(err));      \
      return -1;                                                          \
    }                                                                     \
  } while (0)

// Ядро для локального scan внутри блока
__global__ void scanBlock(float *input, float *output, float *blockSums, int len) {
  __shared__ float temp[2 * BLOCK_SIZE];

  int tid = threadIdx.x;
  int start = 2 * blockIdx.x * blockDim.x;

  int i = start + tid;
  int j = start + tid + blockDim.x;

  temp[tid] = (i < len) ? input[i] : 0;
  temp[tid + blockDim.x] = (j < len) ? input[j] : 0;

  // Upsweep (reduce)
  int offset = 1;
  for (int d = blockDim.x; d > 0; d >>= 1) {
    __syncthreads();
    if (tid < d) {
      int ai = offset * (2 * tid + 1) - 1;
      int bi = offset * (2 * tid + 2) - 1;
      temp[bi] += temp[ai];
    }
    offset <<= 1;
  }

  // Сохраняем сумму блока
  if (tid == 0) {
    blockSums[blockIdx.x] = temp[2 * blockDim.x - 1];
    temp[2 * blockDim.x - 1] = 0;
  }

  // Downsweep
  for (int d = 1; d <= blockDim.x; d <<= 1) {
    offset >>= 1;
    __syncthreads();
    if (tid < d) {
      int ai = offset * (2 * tid + 1) - 1;
      int bi = offset * (2 * tid + 2) - 1;
      float t = temp[ai];
      temp[ai] = temp[bi];
      temp[bi] += t;
    }
  }

  __syncthreads();

  // Запись результатов (exclusive → inclusive)
  if (i < len)
    output[i] = temp[tid] + input[i];
  if (j < len)
    output[j] = temp[tid + blockDim.x] + input[j];
}

// Добавление сумм предыдущих блоков
__global__ void addBlockSums(float *output, float *blockSums, int len) {
  int tid = threadIdx.x;
  int bid = blockIdx.x;

  if (bid == 0) return;

  float addVal = blockSums[bid - 1];

  int start = 2 * bid * blockDim.x;

  int i = start + tid;
  int j = start + tid + blockDim.x;

  if (i < len)
    output[i] += addVal;
  if (j < len)
    output[j] += addVal;
}

// Рекурсивный scan для block sums
int scan(float *input, float *output, int len) {
  int threads = BLOCK_SIZE;
  int elementsPerBlock = 2 * threads;
  int blocks = (len + elementsPerBlock - 1) / elementsPerBlock;

  float *blockSums;
  wbCheck(cudaMalloc((void **)&blockSums, blocks * sizeof(float)));

  scanBlock<<<blocks, threads>>>(input, output, blockSums, len);

  if (blocks > 1) {
    float *scannedBlockSums;
    wbCheck(cudaMalloc((void **)&scannedBlockSums, blocks * sizeof(float)));

    // рекурсивный scan
    scan(blockSums, scannedBlockSums, blocks);

    addBlockSums<<<blocks, threads>>>(output, scannedBlockSums, len);

    cudaFree(scannedBlockSums);
  }

  cudaFree(blockSums);
}

int main(int argc, char **argv) {
  wbArg_t args;
  float *hostInput;
  float *hostOutput;
  float *deviceInput;
  float *deviceOutput;
  int numElements;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput = (float *)wbImport(wbArg_getInputFile(args, 0), &numElements);
  hostOutput = (float *)malloc(numElements * sizeof(float));
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The number of input elements in the input is ",
        numElements);

  wbTime_start(GPU, "Allocating GPU memory.");
  wbCheck(cudaMalloc((void **)&deviceInput, numElements * sizeof(float)));
  wbCheck(cudaMalloc((void **)&deviceOutput, numElements * sizeof(float)));
  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Clearing output memory.");
  wbCheck(cudaMemset(deviceOutput, 0, numElements * sizeof(float)));
  wbTime_stop(GPU, "Clearing output memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");
  wbCheck(cudaMemcpy(deviceInput, hostInput, numElements * sizeof(float),
                     cudaMemcpyHostToDevice));
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  wbTime_start(Compute, "Performing CUDA computation");

  scan(deviceInput, deviceOutput, numElements);

  cudaDeviceSynchronize();

  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");
  wbCheck(cudaMemcpy(hostOutput, deviceOutput, numElements * sizeof(float),
                     cudaMemcpyDeviceToHost));
  wbTime_stop(Copy, "Copying output memory to the CPU");

  wbTime_start(GPU, "Freeing GPU Memory");
  cudaFree(deviceInput);
  cudaFree(deviceOutput);
  wbTime_stop(GPU, "Freeing GPU Memory");

  wbSolution(args, hostOutput, numElements);

  free(hostInput);
  free(hostOutput);

  return 0;
}