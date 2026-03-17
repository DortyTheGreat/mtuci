/*

nvcc main.cu -o program.exe -std=c++17

program.exe example.ppm blur_matrix.txt example.ppm
program.exe example2.ppm edge_detection.txt example2.ppm
program.exe example2.ppm motion_blur.txt example2.ppm

*/

#include "wb.h"

#define wbCheck(stmt)                                                     \
  do {                                                                    \
    cudaError_t err = stmt;                                               \
    if (err != cudaSuccess) {                                             \
      wbLog(ERROR, "Failed to run stmt ", #stmt);                         \
      return -1;                                                          \
    }                                                                     \
  } while (0)

#define Mask_width 5
#define Mask_radius Mask_width / 2
#define TILE_WIDTH 16
#define w (TILE_WIDTH + Mask_width - 1)
#define clamp(x) (min(max((x), 0.0), 1.0))

//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

__constant__ float constMask[Mask_width * Mask_width];

__global__ void convolution(float *input, const float *__restrict__ M,
                            float *output, int channels,
                            int width, int height) {

  __shared__ float tile[w][w][3];

  int tx = threadIdx.x;
  int ty = threadIdx.y;

  int row_o = blockIdx.y * TILE_WIDTH + ty;
  int col_o = blockIdx.x * TILE_WIDTH + tx;

  int row_i = row_o - Mask_radius;
  int col_i = col_o - Mask_radius;

  for (int c = 0; c < channels; c++) {
    if (row_i >= 0 && row_i < height && col_i >= 0 && col_i < width) {
      tile[ty][tx][c] =
          input[(row_i * width + col_i) * channels + c];
    } else {
      tile[ty][tx][c] = 0.0f;
    }
  }

  __syncthreads();

  if (ty < TILE_WIDTH && tx < TILE_WIDTH) {

    if (row_o < height && col_o < width) {

      for (int c = 0; c < channels; c++) {

        float accum = 0.0f;

        for (int y = 0; y < Mask_width; y++) {
          for (int x = 0; x < Mask_width; x++) {
            accum += tile[ty + y][tx + x][c] *
                     constMask[y * Mask_width + x];
          }
        }

        output[(row_o * width + col_o) * channels + c] =
            clamp(accum);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  wbArg_t arg;
  int maskRows;
  int maskColumns;
  int imageChannels;
  int imageWidth;
  int imageHeight;
  char *inputImageFile;
  char *inputMaskFile;
  wbImage_t inputImage;
  wbImage_t outputImage;
  float *hostInputImageData;
  float *hostOutputImageData;
  float *hostMaskData;
  float *deviceInputImageData;
  float *deviceOutputImageData;
  float *deviceMaskData;

  arg = wbArg_read(argc, argv);

  inputImageFile = wbArg_getInputFile(arg, 0);
  inputMaskFile  = wbArg_getInputFile(arg, 1);

  inputImage   = wbImport(inputImageFile);
  hostMaskData = (float *)wbImport(inputMaskFile, &maskRows, &maskColumns);

  assert(maskRows == 5);
  assert(maskColumns == 5);

  imageWidth    = wbImage_getWidth(inputImage);
  imageHeight   = wbImage_getHeight(inputImage);
  imageChannels = wbImage_getChannels(inputImage);

  outputImage = wbImage_new(imageWidth, imageHeight, imageChannels);

  hostInputImageData  = wbImage_getData(inputImage);
  hostOutputImageData = wbImage_getData(outputImage);

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");

  wbTime_start(GPU, "Doing GPU memory allocation");
//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

  cudaMalloc((void **)&deviceInputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float));

  cudaMalloc((void **)&deviceOutputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float));

  cudaMalloc((void **)&deviceMaskData,
             Mask_width * Mask_width * sizeof(float));

  wbTime_stop(GPU, "Doing GPU memory allocation");

  wbTime_start(Copy, "Copying data to the GPU");
//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

  cudaMemcpy(deviceInputImageData,
             hostInputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float),
             cudaMemcpyHostToDevice);

  cudaMemcpy(deviceMaskData,
             hostMaskData,
             Mask_width * Mask_width * sizeof(float),
             cudaMemcpyHostToDevice);

  cudaMemcpyToSymbol(constMask,
                     hostMaskData,
                     Mask_width * Mask_width * sizeof(float));

  wbTime_stop(Copy, "Copying data to the GPU");

  wbTime_start(Compute, "Doing the computation on the GPU");
//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

  dim3 dimBlock(w, w, 1);

  dim3 dimGrid(
      (imageWidth + TILE_WIDTH - 1) / TILE_WIDTH,
      (imageHeight + TILE_WIDTH - 1) / TILE_WIDTH,
      1);

  convolution<<<dimGrid, dimBlock>>>(deviceInputImageData, deviceMaskData,
                                     deviceOutputImageData, imageChannels,
                                     imageWidth, imageHeight);

  cudaDeviceSynchronize();

  wbTime_stop(Compute, "Doing the computation on the GPU");

  wbTime_start(Copy, "Copying data from the GPU");
//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

  cudaMemcpy(hostOutputImageData, deviceOutputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float),
             cudaMemcpyDeviceToHost);

  wbTime_stop(Copy, "Copying data from the GPU");

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(arg, outputImage);

//@@ ВСТАВЬТЕ СЮДА ВАШ КОД

  cudaFree(deviceInputImageData);
  cudaFree(deviceOutputImageData);
  cudaFree(deviceMaskData);

  free(hostMaskData);
  wbImage_delete(outputImage);
  wbImage_delete(inputImage);

  return 0;
}