import random
import argparse

NUM_BINS = 256

ASCII_MIN = 33 # ignore space
ASCII_MAX = 126


def generate_data(length):
    return [chr(random.randint(ASCII_MIN, ASCII_MAX)) for _ in range(length)]


def compute_histogram(data):
    bins = [0] * NUM_BINS
    for c in data:
        bins[ord(c)] += 1
    return bins


def write_input(filename, data):
    with open(filename, "w", encoding="ascii") as f:
        f.write(f"{len(data)}\n")
        f.write(" ".join(data))


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

    args = parser.parse_args()

    data = generate_data(args.length)
    histogram = compute_histogram(data)

    write_input(args.input, data)
    write_expected(args.expected, histogram)

    print("Input file:", args.input)
    print("Expected output:", args.expected)
    print("Elements:", args.length)


if __name__ == "__main__":
    main()