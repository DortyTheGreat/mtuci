
from module import *
import logging
logging.basicConfig(filename='log.txt', level=logging.INFO, encoding='utf-8')




x, a, z, b, c = 0, 0, 0, 0, 0

try:
    x = float(input("Введите x: "))
    a = float(input("Введите a: "))
    z = float(input("Введите z: "))
    b = float(input("Введите b: "))
    c = float(input("Введите c: "))
except ValueError as e:
    print("Введённые значения должны быть числового типа")
    logging.error(str(e))
    quit()

result = 0

try:
    result = func(x,a,z,b,c)
except Exception as e:
    print("Произошла ошибка при вычислениях")
    logging.error(str(e))
    quit()
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

logging.info(f"Значение результирующей функции: {'%.3f' % result}")


file.close()
