import random

def generate_files(n, file1_path="big_input.txt", file2_path="big_output.txt"):
    """
    n: number of elements to generate in the first file
    file1_path: output path for the first file
    file2_path: output path for the second file
    """

    # Generate N random integers smaller than 4000
    numbers = [random.randint(0, 3999) for _ in range(n)]

    # Write first file
    with open(file1_path, "w") as f1:
        f1.write(str(n) + "\n")
        f1.write(" ".join(map(str, numbers)))

    # Prepare counts array of size 4096
    counts = [0] * 4096
    for num in numbers:
        counts[num] += 1

    # Write second file (always 4096 elements)
    with open(file2_path, "w") as f2:
        f2.write("4096\n")
        f2.write(" ".join(map(str, counts)))

    print(f"Generated '{file1_path}' and '{file2_path}' successfully.")


# Example usage:
if __name__ == "__main__":
    N = 4096 * 1000 * 10  # You can change this to any amount
    generate_files(N)