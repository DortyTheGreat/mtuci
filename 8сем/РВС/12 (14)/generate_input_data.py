import random

def generate_array(n, min_val=1, max_val=100):
    return [random.randint(min_val, max_val) for _ in range(n)]

def prefix_sums(arr):
    pref = []
    current_sum = 0
    for x in arr:
        current_sum += x
        pref.append(current_sum)
    return pref

def write_array_to_file(filename, arr):
    with open(filename, "w") as f:
        f.write(str(len(arr)) + "\n")
        f.write(" ".join(map(str, arr)) + "\n")

def main():
    n = 800854
    
    arr = generate_array(n, 1, 1000 * 1000)
    pref = prefix_sums(arr)

    write_array_to_file("array.txt", arr)
    write_array_to_file("prefix_sums.txt", pref)

    #print("Массив:", arr)
    #print("Префиксные суммы:", pref)

if __name__ == "__main__":
    main()