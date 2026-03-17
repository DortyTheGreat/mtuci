import numpy as np


def clamp(val, start, end):
    return max(min(val, end), start)


def stencil_cpu(input_array, width, height, depth):
    output = np.zeros_like(input_array)

    for i in range(1, height - 1):
        for j in range(1, width - 1):
            for k in range(1, depth - 1):

                res = (
                    input_array[i, j, k + 1] +
                    input_array[i, j, k - 1] +
                    input_array[i, j + 1, k] +
                    input_array[i, j - 1, k] +
                    input_array[i + 1, j, k] +
                    input_array[i - 1, j, k] -
                    6 * input_array[i, j, k]
                )

                output[i, j, k] = clamp(res, 0, 255)

    return output


def save_ppm(filename, array):
    height, width, depth = array.shape
    assert depth == 3

    with open(filename, "wb") as f:
        f.write(f"P6\n{width} {height}\n255\n".encode())
        f.write(array.astype(np.uint8).tobytes())


def generate_test(width=32, height=32, depth=3):

    # случайное изображение
    input_array = np.random.randint(
        0, 256, size=(height, width, depth)
    ).astype(np.float32)

    output_array = stencil_cpu(input_array, width, height, depth)

    save_ppm("test_input.ppm", input_array)
    save_ppm("test_expected.ppm", output_array)

    print("Generated:")
    print(" test_input.ppm")
    print(" test_expected.ppm")


if __name__ == "__main__":
    generate_test()