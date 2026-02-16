/**

x64 Native Tools Command Prompt for VS 2022

nvcc main.cu -o program.exe -std=c++17

program.exe input1.txt input2.txt expected.txt

*/

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include "wb.h"

int main(int argc, char *argv[]) {
  wbArg_t args;
  float *hostInput1 = nullptr;
  float *hostInput2 = nullptr;
  float *hostOutput = nullptr;
  int inputLength;

  args = wbArg_read(argc, argv); /* чтение входных аргументов */

  // Импорт входных данных на хост
  wbTime_start(Generic, "Importing data to host");
  hostInput1 =
      (float *)wbImport(wbArg_getInputFile(args, 0), &inputLength);
  hostInput2 =
      (float *)wbImport(wbArg_getInputFile(args, 1), &inputLength);
  wbTime_stop(Generic, "Importing data to host");

  // Объявление и выделение памяти под выходные данные
  hostOutput = (float *)malloc(inputLength * sizeof(float));
  wbTime_start(GPU, "Doing GPU Computation (memory + compute)");

  // Объявление и выделение памяти под входные и выходные данные  на устройства через thrust
  wbTime_start(GPU, "Doing GPU memory allocation");
  thrust::device_vector<float> d_input1(inputLength);
  thrust::device_vector<float> d_input2(inputLength);
  thrust::device_vector<float> d_output(inputLength);

  wbTime_stop(GPU, "Doing GPU memory allocation");

  // Копирование на устройство
  wbTime_start(Copy, "Copying data to the GPU");
  thrust::copy(hostInput1, hostInput1 + inputLength, d_input1.begin());
  thrust::copy(hostInput2, hostInput2 + inputLength, d_input2.begin());
  wbTime_stop(Copy, "Copying data to the GPU");

  // Выполнение операции сложения векторов
  wbTime_start(Compute, "Doing the computation on the GPU");
  thrust::transform(d_input1.begin(),
                  d_input1.end(),
                  d_input2.begin(),
                  d_output.begin(),
                  thrust::plus<float>());

  wbTime_stop(Compute, "Doing the computation on the GPU");
  /////////////////////////////////////////////////////////

  // Копирование данных обратно на хост
  wbTime_start(Copy, "Copying data from the GPU");
  thrust::copy(d_output.begin(), d_output.end(), hostOutput);
  wbTime_stop(Copy, "Copying data from the GPU");

  wbTime_stop(GPU, "Doing GPU Computation (memory + compute)");

  wbSolution(args, hostOutput, inputLength);

  free(hostInput1);
  free(hostInput2);
  free(hostOutput);
  return 0;
}

