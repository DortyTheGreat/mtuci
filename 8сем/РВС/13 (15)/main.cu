/*
nvcc main.cu -o program.exe -std=c++17

program.exe simple_input.txt simple_stud.txt
program.exe simple_input.txt simple_output.txt
*/

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/scan.h>
#include "wb.h"

int main(int argc, char **argv) {
  wbArg_t args;
  float *hostInput, *hostOutput; // Входной одномерный список
  int num_elements;              // количество элементов в списке

  args = wbArg_read(argc, argv);

  wbTime_start(Generic, "Importing data and creating memory on host");
  hostInput =
      (float *)wbImport(wbArg_getInputFile(args, 0), &num_elements);
  wbTime_stop(Generic, "Importing data and creating memory on host");

  wbLog(TRACE, "The number of input elements in the input is ",
        num_elements);

  // Объявите и выделите память на хосте под выходной массив 
  //@@ Вставьте свой код
  hostOutput = (float *)malloc(num_elements * sizeof(float));

  // Объявите и выделите память на устройстве для выходного и входного 
  // массивов thrust
  wbTime_start(GPU, "Allocating GPU memory.");
  //@@ Вставьте свой код
  thrust::device_vector<float> d_input(hostInput, hostInput + num_elements);
  thrust::device_vector<float> d_output(num_elements);
  wbTime_stop(GPU, "Allocating GPU memory.");

  // Выполните сложение векторов
  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ Вставьте свой код

  // Нам нужно: y[0]=0, y[i]=sum(x[0..i-1])
  // Для этого:
  // 1. делаем inclusive_scan
  thrust::inclusive_scan(d_input.begin(), d_input.end(), d_output.begin());

  // 2. сдвигаем вправо
  // y[0] = 0
  // y[i] = scan[i-1]
  thrust::device_vector<float> d_result(num_elements);

  d_result[0] = 0.0f;
  thrust::copy(d_output.begin(), d_output.end() - 1, d_result.begin() + 1);

  // копируем обратно на хост
  thrust::copy(d_result.begin(), d_result.end(), hostOutput);

  wbTime_stop(Compute, "Doing the computation on the GPU");

  wbSolution(args, hostOutput, num_elements);

  // Освободите память хоста
  free(hostInput);
  //@@ Вставьте свой код
  free(hostOutput);

  return 0;
}