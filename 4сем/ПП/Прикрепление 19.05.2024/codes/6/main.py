from module import *

pupils = []
try:
    n = int(input('Введите количество экзаменов: '))
except:
    print('Произошла ошибка Ввода. Количество экзаменов - целое число')
    exit(0)
for i in range(n):
    pupils.append(TPupil())

for i in range(n):
    print(f'Экзамен №{i+1}. ', end='')
    pupils[i].input()

max_points, max_index = get_max_points(pupils, n)
k1 = math_physics(pupils, n)

print(f'1. {k1} учеников набрало более 150 баллов по физике и математике')
print(f'2. Ученик, набравший больше всего баллов по всем предметам суммарно - это ученик {max_index}, он набрал {max_points} баллов')