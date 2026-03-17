#include <stdio.h>
#include <cuda_runtime.h>

int main() {
    int deviceCount;

    cudaGetDeviceCount(&deviceCount);
    printf("Device count: %d\n", deviceCount);

    for (int dev = 0; dev < deviceCount; dev++) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        printf("Device %d: %s\n", dev, deviceProp.name);
    }

    return 0;
}
