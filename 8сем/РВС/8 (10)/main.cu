/*

nvcc main.cu -o program.exe -std=c++17

python generate_input_data.py

*/

#include "wb.h"

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      wbLog(ERROR, "Got CUDA error ...  ", cudaGetErrorString(err));      \
      return -1;                                                          \
    }                                                                     \
  } while (0)

#define TILE_X 8
#define TILE_Y 8
#define TILE_Z 8

#define value(arry, i, j, k) arry[((i) * width + (j)) * depth + (k)]

__device__ float clamp(float v, float lo, float hi) {
  return fmaxf(fminf(v, hi), lo);
}

__global__ void stencil(float *output, float *input, int width, int height,
                        int depth) {

  __shared__ float tile[TILE_X + 2][TILE_Y + 2][TILE_Z + 2];

  int tx = threadIdx.x;
  int ty = threadIdx.y;
  int tz = threadIdx.z;

  int i = blockIdx.x * TILE_X + tx;
  int j = blockIdx.y * TILE_Y + ty;
  int k = blockIdx.z * TILE_Z + tz;

  int li = tx + 1;
  int lj = ty + 1;
  int lk = tz + 1;

  if (i < height && j < width && k < depth)
    tile[li][lj][lk] = value(input, i, j, k);
  else
    tile[li][lj][lk] = 0.0f;

  if (tx == 0 && i > 0)
    tile[0][lj][lk] = value(input, i - 1, j, k);
  if (tx == TILE_X - 1 && i < height - 1)
    tile[TILE_X + 1][lj][lk] = value(input, i + 1, j, k);

  if (ty == 0 && j > 0)
    tile[li][0][lk] = value(input, i, j - 1, k);
  if (ty == TILE_Y - 1 && j < width - 1)
    tile[li][TILE_Y + 1][lk] = value(input, i, j + 1, k);

  if (tz == 0 && k > 0)
    tile[li][lj][0] = value(input, i, j, k - 1);
  if (tz == TILE_Z - 1 && k < depth - 1)
    tile[li][lj][TILE_Z + 1] = value(input, i, j, k + 1);

  __syncthreads();

  if (i >= 1 && i < height - 1 &&
      j >= 1 && j < width - 1 &&
      k >= 1 && k < depth - 1) {

    float res =
        tile[li][lj][lk + 1] +
        tile[li][lj][lk - 1] +
        tile[li][lj + 1][lk] +
        tile[li][lj - 1][lk] +
        tile[li + 1][lj][lk] +
        tile[li - 1][lj][lk] -
        6.0f * tile[li][lj][lk];

    value(output, i, j, k) = clamp(res, 0.0f, 255.0f);
  }
}

static void launch_stencil(float *deviceOutputData, float *deviceInputData,
                           int width, int height, int depth) {

  dim3 block(TILE_X, TILE_Y, TILE_Z);

  dim3 grid(
      (height + TILE_X - 1) / TILE_X,
      (width + TILE_Y - 1) / TILE_Y,
      (depth + TILE_Z - 1) / TILE_Z);

  stencil<<<grid, block>>>(deviceOutputData, deviceInputData,
                           width, height, depth);

  cudaDeviceSynchronize();
}

int main(int argc, char *argv[]) {
  wbArg_t arg;
  int width;
  int height;
  int depth;
  char *inputFile;
  wbImage_t input;
  wbImage_t output;
  float *hostInputData;
  float *hostOutputData;
  float *deviceInputData;
  float *deviceOutputData;

  arg = wbArg_read(argc, argv);

  inputFile = wbArg_getInputFile(arg, 0);

  input = wbImport(inputFile);

  width  = wbImage_getWidth(input);
  height = wbImage_getHeight(input);
  depth  = wbImage_getChannels(input);

  output = wbImage_new(width, height, depth);

  hostInputData  = wbImage_getData(input);
  hostOutputData = wbImage_getData(output);

  wbTime_start(GPU, "Doing GPU memory allocation");
  cudaMalloc((void **)&deviceInputData,
             width * height * depth * sizeof(float));
  cudaMalloc((void **)&deviceOutputData,
             width * height * depth * sizeof(float));
  wbTime_stop(GPU, "Doing GPU memory allocation");

  wbTime_start(Copy, "Copying data to the GPU");
  cudaMemcpy(deviceInputData, hostInputData,
             width * height * depth * sizeof(float),
             cudaMemcpyHostToDevice);
  wbTime_stop(Copy, "Copying data to the GPU");

  wbTime_start(Compute, "Doing the computation on the GPU");
  launch_stencil(deviceOutputData, deviceInputData, width, height, depth);
  wbTime_stop(Compute, "Doing the computation on the GPU");

  wbTime_start(Copy, "Copying data from the GPU");
  cudaMemcpy(hostOutputData, deviceOutputData,
             width * height * depth * sizeof(float),
             cudaMemcpyDeviceToHost);
  wbTime_stop(Copy, "Copying data from the GPU");

  wbSolution(arg, output);

  cudaFree(deviceInputData);
  cudaFree(deviceOutputData);

  wbImage_delete(output);
  wbImage_delete(input);

  return 0;
}