import math


def func(x, a, z, b, c):
    if x < 0 and z < 0:
        m = x
        if a > m:
            m = a
        m2 = z
        if x * a ** m < m2:
            m2 = x * a ** m
        return math.log(x * a + m2)
    else:
        if 0 <= x and x < 4 and 0 <= z and z < 3:
            m = z
            if (math.sqrt(x) > m):
                m = math.sqrt(x)
            if (abs(math.sqrt(x)) > m):
                m = abs(math.sqrt(x))
            return math.log(b ** 2) + m
        else:
            return b + c * x


x, a, z, b, c = 0, 0, 0, 0, 0

try:
    x = float(input("Введите x: "))
    a = float(input("Введите a: "))
    z = float(input("Введите z: "))
    b = float(input("Введите b: "))
    c = float(input("Введите c: "))
except ValueError:
    print("Введённые значения должны быть числового типа")
    quit()

result = func(x,a,z,b,c)

print()
print(f"Выходные данные:")
print(f"func(три знака после запятой): {'%.3f' % result}")
print(f"func(ceil): {math.ceil(result)}")
print(f"func(floor): {math.floor(result)}")
print(f"func(round): {round(result)}")
print(f"func(trunc): {math.trunc(result)}")

file = open("result.txt", "w", encoding="utf-8")
file.write(f'Исходные данные:\n x: {x}, a: {a}, z:{z}, b:{b}, c:{c} \n')

file.write(f"Выходные данные:\n")
file.write(f"func(три знака после запятой): {'%.3f' % result}\n")
file.write(f"func(ceil): {math.ceil(result)}\n")
file.write(f"func(floor): {math.floor(result)}\n")
file.write(f"func(round): {round(result)}\n")
file.write(f"func(trunc): {math.trunc(result)}\n")


file.close()

