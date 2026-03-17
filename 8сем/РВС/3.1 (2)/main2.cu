/**

x64 Native Tools Command Prompt for VS 2022

nvcc main.cu -o program.exe

*/

#include "wb.h"
#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Простая функция генерации случайного числа
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

__global__ void vecAdd(float *in1, float *in2, float *out, int len) {
    //@@ Сложение векторов
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < len) {
        out[idx] = in1[idx] + in2[idx];
    }
}

int main(int argc, char **argv) {

    int inputLength;

    printf("Введите количество элементов векторов: ");
    scanf("%d", &inputLength);

    srand(time(NULL));

    float *hostInput1 = (float*)malloc(inputLength * sizeof(float));
    float *hostInput2 = (float*)malloc(inputLength * sizeof(float));
    float *hostOutput = (float*)malloc(inputLength * sizeof(float));

    // Генерация случайных данных
    for (int i = 0; i < inputLength; i++) {
        hostInput1[i] = static_cast<float>(randomInt(0, 100));
        hostInput2[i] = static_cast<float>(randomInt(0, 100));
    }

    float *deviceInput1;
    float *deviceInput2;
    float *deviceOutput;

    wbTime_start(GPU, "Allocating GPU memory.");
    //@@ Выделение памяти GPU
    cudaMalloc((void**)&deviceInput1, inputLength * sizeof(float));
    cudaMalloc((void**)&deviceInput2, inputLength * sizeof(float));
    cudaMalloc((void**)&deviceOutput, inputLength * sizeof(float));
    wbTime_stop(GPU, "Allocating GPU memory.");

    wbTime_start(GPU, "Copying input memory to the GPU.");
    //@@ Копирование данных на устройство
    cudaMemcpy(deviceInput1, hostInput1,
               inputLength * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(deviceInput2, hostInput2,
               inputLength * sizeof(float), cudaMemcpyHostToDevice);
    wbTime_stop(GPU, "Copying input memory to the GPU.");

    //@@ Инициализация размерностей сетки и блоков
    int blockSize = 256;
    int gridSize = (inputLength + blockSize - 1) / blockSize;

    wbTime_start(Compute, "Performing CUDA computation");
    //@@ Запуск ядра
    vecAdd<<<gridSize, blockSize>>>(deviceInput1, deviceInput2,
                                    deviceOutput, inputLength);
    cudaDeviceSynchronize();
    wbTime_stop(Compute, "Performing CUDA computation");

    wbTime_start(Copy, "Copying output memory to the CPU");
    //@@ Копирование результата обратно
    cudaMemcpy(hostOutput, deviceOutput,
               inputLength * sizeof(float), cudaMemcpyDeviceToHost);
    wbTime_stop(Copy, "Copying output memory to the CPU");

    wbTime_start(GPU, "Freeing GPU Memory");
    //@@ Освобождение памяти GPU
    cudaFree(deviceInput1);
    cudaFree(deviceInput2);
    cudaFree(deviceOutput);
    wbTime_stop(GPU, "Freeing GPU Memory");

    // Проверка (вывод первых 10 элементов)
    printf("\nПервые 10 результатов:\n");
    for (int i = 0; i < (inputLength < 10 ? inputLength : 10); i++) {
        printf("%f + %f = %f\n",
               hostInput1[i], hostInput2[i], hostOutput[i]);
    }

    free(hostInput1);
    free(hostInput2);
    free(hostOutput);

    return 0;
}
