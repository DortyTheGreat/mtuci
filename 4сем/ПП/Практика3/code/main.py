import branch1
import branch2
import branch3


class Branches :
    def __init__(self, x, a, z, b, c):
        self.x = x
        self.a = a
        self.z = z
        self.b = b
        self.c = c
        print('Работает конструктор')

    def input(self):
        values = map(float, input('Введите значения (x, a, z, b, c), разделив их пробелами: ').split())
        self.x, self.a, self.z, self.b, self.c = values

    def get_branch1(self):
        return branch1.branch(self.x, self.a, self.z, self.b, self.c)

    def get_branch2(self):
        return branch2.branch(self.x, self.a, self.z, self.b, self.c)

    def get_branch3(self):
        return branch3.branch(self.x, self.a, self.z, self.b, self.c)


branching = Branches(0,0,0,0,0)
try:
    branching.input()
except:
    print("Произошла ошибка ввода")
    exit(-1)
res = 0

if branching.x < 0 and branching.z < 0:
    res = branching.get_branch1()
else:
    if 0 <= branching.x and branching.x < 4 and 0 <= branching.z and branching.z < 3:
        res = branching.get_branch2()
    else:
        res = branching.get_branch3()

print(f'Результат ветвления: {round(res, 5)}')