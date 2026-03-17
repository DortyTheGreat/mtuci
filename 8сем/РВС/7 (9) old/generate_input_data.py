import random
import argparse

NUM_BINS = 4096


def generate_data(length, max_value):
    return [random.randint(0, max_value) for _ in range(length)]


def compute_histogram(data):
    bins = [0] * NUM_BINS
    for v in data:
        if 0 <= v < NUM_BINS:
            bins[v] += 1
    return bins


def write_input(filename, data):
    with open(filename, "w") as f:
        f.write(str(len(data)) + "\n")
        for v in data:
            f.write(str(v) + " ")


def write_expected(filename, bins):
    with open(filename, "w") as f:
        f.write(f"{len(bins)}\n")
        for b in bins:
            f.write(str(b) + "\n")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", "--length", type=int, default=100000)
    parser.add_argument("-o", "--input", default="input.txt")
    parser.add_argument("-e", "--expected", default="expected.txt")
    parser.add_argument("--max", type=int, default=4095)

    args = parser.parse_args()

    data = generate_data(args.length, args.max)
    histogram = compute_histogram(data)

    write_input(args.input, data)
    write_expected(args.expected, histogram)

    print("Input file:", args.input)
    print("Expected output:", args.expected)
    print("Elements:", args.length)


if __name__ == "__main__":
    main()