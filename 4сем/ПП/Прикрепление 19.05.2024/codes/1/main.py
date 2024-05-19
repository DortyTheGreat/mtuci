import math

def get_Radius(L):
    return L / (2 * math.pi)

def get_Area(L):
    return math.pi * get_Radius(L)**2

def get_Area_mult(L1, L2, L3):
    return get_Area(L1), get_Area(L2), get_Area(L3)

L1, L2, L3 = 0, 0, 0

try:
    L1 = float(input("Введите длину окружности L1: "))
    L2 = float(input("Введите длину окружности L2: "))
    L3 = float(input("Введите длину окружности L3: "))
    if (L1 < 0 or L2 < 0 or L3 < 0):
        print("Введённые значения должны быть не меньше нуля")
        quit()
except ValueError:
    print("Введённое значение должно быть числом")
    quit()

S1, S2, S3 = get_Area_mult(L1, L2, L3)

print(f"Выходные данные:\nS1: {S1}, S2: {S2}, S3:{S3}")
file = open("result.txt", "w", encoding="utf-8")
file.write(f'Исходные данные:\n L1: {L1}, L2: {L2}, L3:{L3} \n')
file.write(f'Выходные данные:\n S1: {S1}, S2: {S2}, S3: {S3}')
file.close()
