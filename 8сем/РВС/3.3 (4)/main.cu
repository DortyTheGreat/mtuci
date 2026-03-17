/**

x64 Native Tools Command Prompt for VS 2022

nvcc main.cu -o program.exe -std=c++17

ffmpeg -i example.ppm -vf "colorchannelmixer=.21:.71:.07" -frames:v 1 ffmpeg.ppm

program.exe example.ppm

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

//@@ Ядро CUDA для преобразования RGB в grayscale
__global__ void rgb2gray(float *inputImage, float *grayImage, int width, int height, int channels) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int row = blockIdx.y * blockDim.y + threadIdx.y;

    if (col < width && row < height) {
        int idx = row * width + col;
        float r = inputImage[channels * idx + 0];
        float g = inputImage[channels * idx + 1];
        float b = inputImage[channels * idx + 2];
        grayImage[idx] = 0.21f * r + 0.71f * g + 0.07f * b;
    }
}

void saveGrayscaleToPGM(const char* filename, float* data, int width, int height) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        wbLog(ERROR, "Failed to open file for writing: ", filename);
        return;
    }
    
    // Заголовок PGM формата
    file << "P2\n";
    file << width << " " << height << "\n";
    file << "255\n";
    
    // Запись данных пикселей
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Преобразование float [0,1] в целое [0,255]
            int pixelValue = static_cast<int>(data[i * width + j] * 255.0f + 0.5f);
            pixelValue = std::min(255, std::max(0, pixelValue)); // Ограничение значений
            file << pixelValue;
            
            if (j < width - 1) {
                file << " ";
            }
        }
        file << "\n";
    }
    
    file.close();
    wbLog(INFO, "Grayscale image saved to ", filename);
}

int main(int argc, char *argv[]) {
  wbArg_t args;
  int imageChannels;
  int imageWidth;
  int imageHeight;
  char *inputImageFile;
  wbImage_t inputImage;
  wbImage_t outputImage;
  float *hostInputImageData;
  float *hostOutputImageData;
  float *deviceInputImageData;
  float *deviceOutputImageData;

  args = wbArg_read(argc, argv); /* чтение входных аргументов */

  inputImageFile = wbArg_getInputFile(args, 0);

  inputImage = wbImport(inputImageFile);

  imageWidth  = wbImage_getWidth(inputImage);
  imageHeight = wbImage_getHeight(inputImage);
  // В данной лабораторной значение равно 3
  imageChannels = wbImage_getChannels(inputImage);

  //  Так как изображение монохромное, оно содержит только 1 канал
  outputImage = wbImage_new(imageWidth, imageHeight, 1);

  hostInputImageData  = wbImage_getData(inputImage);
  hostOutputImageData = wbImage_getData(outputImage);

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");

  wbTime_start(GPU, "Doing GPU memory allocation");
  cudaMalloc((void **)&deviceInputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float));
  cudaMalloc((void **)&deviceOutputImageData,
             imageWidth * imageHeight * sizeof(float));
  wbTime_stop(GPU, "Doing GPU memory allocation");

  wbTime_start(Copy, "Copying data to the GPU");
  cudaMemcpy(deviceInputImageData, hostInputImageData,
             imageWidth * imageHeight * imageChannels * sizeof(float),
             cudaMemcpyHostToDevice);
  wbTime_stop(Copy, "Copying data to the GPU");

  ///////////////////////////////////////////////////////
  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ Настройка размеров блока и сетки
  dim3 blockSize(16, 16); // блок 16x16 нитей
  dim3 gridSize((imageWidth + blockSize.x - 1) / blockSize.x,
                (imageHeight + blockSize.y - 1) / blockSize.y);

  //@@ Запуск ядра CUDA
  rgb2gray<<<gridSize, blockSize>>>(deviceInputImageData, deviceOutputImageData, imageWidth, imageHeight, imageChannels);

  // Проверка на ошибки запуска ядра
  wbCheck(cudaDeviceSynchronize());
  wbTime_stop(Compute, "Doing the computation on the GPU");

  ///////////////////////////////////////////////////////
  wbTime_start(Copy, "Copying data from the GPU");
  cudaMemcpy(hostOutputImageData, deviceOutputImageData,
             imageWidth * imageHeight * sizeof(float),
             cudaMemcpyDeviceToHost);
  wbTime_stop(Copy, "Copying data from the GPU");

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");
	
	
  saveGrayscaleToPGM("output_gray.pgm", hostOutputImageData, imageWidth, imageHeight);

  cudaFree(deviceInputImageData);
  cudaFree(deviceOutputImageData);

  wbImage_delete(outputImage);
  wbImage_delete(inputImage);

  return 0;
}
