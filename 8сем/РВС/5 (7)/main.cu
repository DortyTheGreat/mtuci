/*
nvcc main.cu -o program.exe -std=c++17

python generate_test_data.py

program.exe A.txt B.txt C.txt
program.exe simpleA.txt simpleB.txt blankC.txt
program.exe bigA.txt bigB.txt bigC.txt

*/

#include "wb.h"

#define TILE_WIDTH 16

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      wbLog(ERROR, "Got CUDA error ...  ", cudaGetErrorString(err));      \
      return -1;                                                          \
    }                                                                     \
  } while (0)

// Вычисление C = A * B
__global__ void matrixMultiplyShared(float *A, float *B, float *C,
                                     int numARows, int numAColumns,
                                     int numBRows, int numBColumns,
                                     int numCRows, int numCColumns) {

  __shared__ float sA[TILE_WIDTH][TILE_WIDTH];
  __shared__ float sB[TILE_WIDTH][TILE_WIDTH];

  int bx = blockIdx.x;
  int by = blockIdx.y;
  int tx = threadIdx.x;
  int ty = threadIdx.y;

  int Row = by * TILE_WIDTH + ty;
  int Col = bx * TILE_WIDTH + tx;

  float Cvalue = 0.0f;

  for (int t = 0; t < (numAColumns + TILE_WIDTH - 1) / TILE_WIDTH; ++t) {

    // Загрузка блока A в shared memory
    if (Row < numARows && (t * TILE_WIDTH + tx) < numAColumns)
      sA[ty][tx] = A[Row * numAColumns + t * TILE_WIDTH + tx];
    else
      sA[ty][tx] = 0.0f;

    // Загрузка блока B в shared memory
    if (Col < numBColumns && (t * TILE_WIDTH + ty) < numBRows)
      sB[ty][tx] = B[(t * TILE_WIDTH + ty) * numBColumns + Col];
    else
      sB[ty][tx] = 0.0f;

    __syncthreads();

    for (int k = 0; k < TILE_WIDTH; ++k)
      Cvalue += sA[ty][k] * sB[k][tx];

    __syncthreads();
  }

  if (Row < numCRows && Col < numCColumns)
    C[Row * numCColumns + Col] = Cvalue;
}

int main(int argc, char **argv) {
  wbArg_t args;
  float *hostA;
  float *hostB;
  float *hostC;
  float *deviceA;
  float *deviceB;
  float *deviceC;
  int numARows;
  int numAColumns;
  int numBRows;
  int numBColumns;
  int numCRows;
  int numCColumns;

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostA = (float *)wbImport(wbArg_getInputFile(args, 0), &numARows,
                            &numAColumns);
  hostB = (float *)wbImport(wbArg_getInputFile(args, 1), &numBRows,
                            &numBColumns);

  // Размеры результирующей матрицы
  numCRows = numARows;
  numCColumns = numBColumns;

  // Выделение памяти под hostC
  hostC = (float *)malloc(numCRows * numCColumns * sizeof(float));

  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The dimensions of A are ", numARows, " x ", numAColumns);
  wbLog(TRACE, "The dimensions of B are ", numBRows, " x ", numBColumns);

  wbTime_start(GPU, "Allocating GPU memory.");

  wbCheck(cudaMalloc((void **)&deviceA,
                     numARows * numAColumns * sizeof(float)));
  wbCheck(cudaMalloc((void **)&deviceB,
                     numBRows * numBColumns * sizeof(float)));
  wbCheck(cudaMalloc((void **)&deviceC,
                     numCRows * numCColumns * sizeof(float)));

  wbTime_stop(GPU, "Allocating GPU memory.");

  wbTime_start(GPU, "Copying input memory to the GPU.");

  wbCheck(cudaMemcpy(deviceA, hostA,
                     numARows * numAColumns * sizeof(float),
                     cudaMemcpyHostToDevice));

  wbCheck(cudaMemcpy(deviceB, hostB,
                     numBRows * numBColumns * sizeof(float),
                     cudaMemcpyHostToDevice));

  wbTime_stop(GPU, "Copying input memory to the GPU.");

  // Инициализация размерности блоков и сетки
  dim3 dimBlock(TILE_WIDTH, TILE_WIDTH, 1);
  dim3 dimGrid((numCColumns + TILE_WIDTH - 1) / TILE_WIDTH,
               (numCRows + TILE_WIDTH - 1) / TILE_WIDTH,
               1);

  wbTime_start(Compute, "Performing CUDA computation");

  matrixMultiplyShared<<<dimGrid, dimBlock>>>(
      deviceA, deviceB, deviceC,
      numARows, numAColumns,
      numBRows, numBColumns,
      numCRows, numCColumns);

  cudaDeviceSynchronize();

  wbTime_stop(Compute, "Performing CUDA computation");

  wbTime_start(Copy, "Copying output memory to the CPU");

  wbCheck(cudaMemcpy(hostC, deviceC,
                     numCRows * numCColumns * sizeof(float),
                     cudaMemcpyDeviceToHost));

  wbTime_stop(Copy, "Copying output memory to the CPU");

  wbTime_start(GPU, "Freeing GPU Memory");

  cudaFree(deviceA);
  cudaFree(deviceB);
  cudaFree(deviceC);

  wbTime_stop(GPU, "Freeing GPU Memory");

  wbSolution(args, hostC, numCRows, numCColumns);

  free(hostA);
  free(hostB);
  free(hostC);

  return 0;
}