from math import isqrt
from collections import defaultdict
import random

# Число гласных
def task1(s: str) -> int:
    vowels = "aeiouAEIOU"
    return sum(1 for ch in s if ch in vowels)

print("Task1:", task1("HelloWorld"))


# Уникальные символы
def task2(s: str) -> bool:
    return len(set(s)) == len(s)

print("Task2:", task2("abcd"))
print("Task2:", task2("aabc")) 


# Сколько единичных бит
def task3(n: int) -> int:
    return bin(n).count("1")

print("Task3:", task3(13))


# Почти цифровой корень
def task4(n: int) -> int:
    count = 0
    while n >= 10:
        prod = 1
        for digit in str(n):
            prod *= int(digit)
        n = prod
        count += 1
    return count

print("Task4:", task4(39))  
print("Task4:", task4(4)) 
print("Task4:", task4(999)) 


# СКО
def task5(v1: list[int], v2: list[int]) -> float:
    if len(v1) != len(v2):
        raise ValueError("Векторы должны быть одинаковой длины")
    n = len(v1)
    mse = sum((a - b) ** 2 for a, b in zip(v1, v2)) / n
    return mse ** 0.5

print("Task5:", task5([1, 2, 3], [4, 5, 6]))


# Мат ожидание + СКО
def task6(nums: list[float]) -> tuple[float, float]:
    n = len(nums)
    mean = sum(nums) / n
    variance = sum((x - mean) ** 2 for x in nums) / n
    std_dev = variance ** 0.5
    return mean, std_dev

print("Task6:", task6([1, 2, 3, 4, 5]))


# Разложение на простые множители
def task7(n: int) -> str:
    result = []
    d = 2
    while d * d <= n:
        power = 0
        while n % d == 0:
            n //= d
            power += 1
        if power:
            result.append(f"({d}**{power})" if power > 1 else f"({d})")
        d += 1
    if n > 1:
        result.append(f"({n})")
    return "".join(result)

print("Task7:", task7(86240)) 


# Ыычисление ip и широковещательный адрес
def task8(ip: str, mask: str) -> tuple[str, str]:
    ip_parts = list(map(int, ip.split(".")))
    mask_parts = list(map(int, mask.split(".")))
    network = []
    broadcast = []
    for i in range(4):
        net = ip_parts[i] & mask_parts[i]
        network.append(net)
        broad = net | (255 - mask_parts[i])
        broadcast.append(broad)
    return ".".join(map(str, network)), ".".join(map(str, broadcast))

print("Task8:", task8("192.168.1.130", "255.255.255.0"))  


# Проверка "пирамидальности"
def task9(n: int):
    total = 0
    k = 0
    while total < n:
        k += 1
        total += k * k
    return k if total == n else "It is impossible"

print("Task9:", task9(14))
print("Task9:", task9(15))


# Сбалансированные числа
def task10(n: int) -> bool:
    s = str(n)
    length = len(s)
    if length <= 2:
        return True 
    if length % 2 == 0:
        left = s[:length//2 - 1]
        right = s[length//2 + 1:]
    else:
        left = s[:length//2]
        right = s[length//2 + 1:]
    return sum(map(int, left)) == sum(map(int, right))

print("Task10:", task10(23441))
print("Task10:", task10(123456))


# Задача №11 — стратифицированное разбиение массива
def task11(M: list[list], r: float):
    if not (0 < r < 1):
        raise ValueError("r должно быть между 0 и 1")
    by_class = defaultdict(list)
    for row in M:
        by_class[row[0]].append(row)
    part1, part2 = [], []
    for cls, rows in by_class.items():
        k = round(len(rows) * r)
        random.shuffle(rows)
        part1.extend(rows[:k])
        part2.extend(rows[k:])
    return part1, part2


M = [
    ['a', 1, 2],
    ['a', 3, 4],
    ['b', 5, 6],
    ['b', 7, 8],
    ['c', 9, 10],
    ['c', 11, 12],
]

p1, p2 = task11(M, 0.5)
print("Task11 part1:", p1)
print("Task11 part2:", p2)