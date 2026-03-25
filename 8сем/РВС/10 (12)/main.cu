/*
nvcc main.cu -o program.exe -std=c++17

program.exe simple_input.txt simple_output.txt
program.exe file1.txt answer.txt
*/

#include "wb.h"

#define BLOCK_SIZE 512

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      return -1;                                                          \
    }                                                                     \
  } while (0)

__global__ void total(float *input, float *output, int len) {
  __shared__ float sdata[BLOCK_SIZE];

  unsigned int tid = threadIdx.x;
  unsigned int start = 2 * blockIdx.x * blockDim.x;

  float sum = 0.0f;

  // Загрузка 2 элементов на поток (уменьшаем обращения к global memory)
  if (start + tid < len)
    sum += input[start + tid];

  if (start + blockDim.x + tid < len)
    sum += input[start + blockDim.x + tid];

  // Запись в shared memory
  sdata[tid] = sum;
  __syncthreads();

  // Редукция в shared memory (дерево)
  for (unsigned int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
    if (tid < stride) {
      sdata[tid] += sdata[tid + stride];
    }
    __syncthreads();
  }

  // Запись результата блока
  if (tid == 0) {
    output[blockIdx.x] = sdata[0];
  }
}

int main(int argc, char **argv) {
  int ii;
  wbArg_t args;
  float *hostInput;
  float *hostOutput;
  float *deviceInput;
  float *deviceOutput;
  int numInputElements;
  int numOutputElements;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput =
      (float *)wbImport(wbArg_getInputFile(args, 0), &numInputElements);

  numOutputElements = numInputElements / (BLOCK_SIZE << 1);
  if (numInputElements % (BLOCK_SIZE << 1)) {
    numOutputElements++;
  }

  hostOutput = (float *)malloc(numOutputElements * sizeof(float));
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The number of input elements in the input is ",
        numInputElements);
  wbLog(TRACE, "The number of output elements in the input is ",
        numOutputElements);

  wbTime_start(GPU, "Allocating GPU memory.");
  wbCheck(cudaMalloc((void **)&deviceInput,
                     numInputElements * sizeof(float)));
  wbCheck(cudaMalloc((void **)&deviceOutput,
                     numOutputElements * sizeof(float)));
  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");
  wbCheck(cudaMemcpy(deviceInput, hostInput,
                     numInputElements * sizeof(float),
                     cudaMemcpyHostToDevice));
  wbTime_stop(GPU, "Copying input memory to the GPU.");

  // Инициализация блока и сетки
  dim3 dimBlock(BLOCK_SIZE);
  dim3 dimGrid(numOutputElements);

  wbTime_start(Compute, "Performing CUDA computation");
  total<<<dimGrid, dimBlock>>>(deviceInput, deviceOutput,
                              numInputElements);
  cudaDeviceSynchronize();
  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");
  wbCheck(cudaMemcpy(hostOutput, deviceOutput,
                     numOutputElements * sizeof(float),
                     cudaMemcpyDeviceToHost));
  wbTime_stop(Copy, "Copying output memory to the CPU");

  // Финальная редукция на CPU
  float finalSum = 0.0f;
  for (ii = 0; ii < numOutputElements; ii++) {
    finalSum += hostOutput[ii];
  }

  hostOutput[0] = finalSum;

  wbTime_start(GPU, "Freeing GPU Memory");
  cudaFree(deviceInput);
  cudaFree(deviceOutput);
  wbTime_stop(GPU, "Freeing GPU Memory");

  wbSolution(args, hostOutput, 1);

  free(hostInput);
  free(hostOutput);

  return 0;
}