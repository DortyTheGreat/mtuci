/*
nvcc main.cu -o program.exe -std=c++17

program.exe example.ppm example.ppm

program.exe example.ppm transformed_image.ppm
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

#define BLUR_SIZE 5

//@@ CUDA kernel
__global__ void blurKernel(float *input, float *output,
                           int width, int height, int channels) {

  int x = blockIdx.x * blockDim.x + threadIdx.x;
  int y = blockIdx.y * blockDim.y + threadIdx.y;

  if (x >= width || y >= height) return;

  for (int c = 0; c < channels; c++) {

    float sum = 0.0f;
    int count = 0;

    for (int dy = -BLUR_SIZE; dy <= BLUR_SIZE; dy++) {
      for (int dx = -BLUR_SIZE; dx <= BLUR_SIZE; dx++) {

        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
          int idx = (ny * width + nx) * channels + c;
          sum += input[idx];
          count++;
        }
      }
    }

    int outIdx = (y * width + x) * channels + c;
    output[outIdx] = sum / count;
  }
}

int main(int argc, char *argv[]) {

  wbArg_t args;
  int imageWidth;
  int imageHeight;
  int imageChannels;
  char *inputImageFile;
  wbImage_t inputImage;
  wbImage_t outputImage;
  float *hostInputImageData;
  float *hostOutputImageData;
  float *deviceInputImageData;
  float *deviceOutputImageData;

  args = wbArg_read(argc, argv);

  inputImageFile = wbArg_getInputFile(args, 0);
  inputImage = wbImport(inputImageFile);

  imageWidth    = wbImage_getWidth(inputImage);
  imageHeight   = wbImage_getHeight(inputImage);
  imageChannels = wbImage_getChannels(inputImage);

  outputImage = wbImage_new(imageWidth, imageHeight, imageChannels);

  hostInputImageData  = wbImage_getData(inputImage);
  hostOutputImageData = wbImage_getData(outputImage);

  int imageSize = imageWidth * imageHeight * imageChannels;

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");

  wbTime_start(GPU, "Doing GPU memory allocation");
  wbCheck(cudaMalloc((void **)&deviceInputImageData,
                     imageSize * sizeof(float)));
  wbCheck(cudaMalloc((void **)&deviceOutputImageData,
                     imageSize * sizeof(float)));
  wbTime_stop(GPU, "Doing GPU memory allocation");

  wbTime_start(Copy, "Copying data to the GPU");
  wbCheck(cudaMemcpy(deviceInputImageData, hostInputImageData,
                     imageSize * sizeof(float),
                     cudaMemcpyHostToDevice));
  wbTime_stop(Copy, "Copying data to the GPU");

  ///////////////////////////////////////////////////////
  wbTime_start(Compute, "Doing the computation on the GPU");

  dim3 blockDim(16, 16);
  dim3 gridDim((imageWidth + 15) / 16,
               (imageHeight + 15) / 16);

  blurKernel<<<gridDim, blockDim>>>(deviceInputImageData,
                                    deviceOutputImageData,
                                    imageWidth,
                                    imageHeight,
                                    imageChannels);

  wbCheck(cudaDeviceSynchronize());

  wbTime_stop(Compute, "Doing the computation on the GPU");
  ///////////////////////////////////////////////////////

  wbTime_start(Copy, "Copying data from the GPU");
  wbCheck(cudaMemcpy(hostOutputImageData, deviceOutputImageData,
                     imageSize * sizeof(float),
                     cudaMemcpyDeviceToHost));
  wbTime_stop(Copy, "Copying data from the GPU");

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(args, outputImage);

  cudaFree(deviceInputImageData);
  cudaFree(deviceOutputImageData);

  wbImage_delete(outputImage);
  wbImage_delete(inputImage);

  return 0;
}