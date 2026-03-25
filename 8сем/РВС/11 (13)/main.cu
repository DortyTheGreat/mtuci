/*
nvcc main.cu -o program.exe -std=c++17

program.exe simple_input.txt simple_output.txt
program.exe file1.txt answer.txt
*/


#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/reduce.h>
#include "wb.h"

int main(int argc, char *argv[]) {
  wbArg_t args;
  float *hostInput;
  float hostOutput;
  int inputLength;

  args = wbArg_read(argc, argv); /* чтение аргументов программы */

  // Импорт входных данных
  wbTime_start(Generic, "Importing data to host");
  hostInput = (float *)wbImport(wbArg_getInputFile(args, 0), &inputLength);
  wbTime_stop(Generic, "Importing data to host");

  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");
  
  // Объявление и выделение памяти для входного и выходного векторов на thrust
  wbTime_start(GPU, "Doing GPU memory allocation");
  //@@ Вставьте ваш код
  thrust::device_vector<float> deviceInput(inputLength);
  wbTime_stop(GPU, "Doing GPU memory allocation");

  // Копирование на устройство
  wbTime_start(Copy, "Copying data to the GPU");
  //@@ Вставьте ваш код
  thrust::copy(hostInput, hostInput + inputLength, deviceInput.begin());
  wbTime_stop(Copy, "Copying data to the GPU");

  // Выполните редукцию (суммирование)
  wbTime_start(Compute, "Doing the computation on the GPU");
  //@@ Вставьте ваш код
  hostOutput = thrust::reduce(deviceInput.begin(), deviceInput.end(), 0.0f, thrust::plus<float>());
  wbTime_stop(Compute, "Doing the computation on the GPU");
  /////////////////////////////////////////////////////////

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(args, &hostOutput, 1);

  free(hostInput);
  return 0;
}