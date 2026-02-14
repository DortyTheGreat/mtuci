import random

def write_file(filename, data):
    with open(filename, "w") as f:
        f.write(f"{len(data)}\n")
        f.write(" ".join(f"{v:.6f}" for v in data))

# Размер массива
N = 1024

# Можно заменить random.uniform(...) на float(i) для детерминированных тестов
input1 = [random.uniform(-10, 10) for _ in range(N)]
input2 = [random.uniform(-10, 10) for _ in range(N)]

# Ожидаемая сумма
expected = [a + b for a, b in zip(input1, input2)]

write_file("input1.txt", input1)
write_file("input2.txt", input2)
write_file("expected.txt", expected)

print("Файлы input1.txt, input2.txt и expected.txt созданы.")
