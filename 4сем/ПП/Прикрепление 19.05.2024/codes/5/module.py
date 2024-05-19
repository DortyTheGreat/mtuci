import branch1
import branch2
import branch3

class Branches :
    def __init__(self, x, a, z, b, c):
        self.x = x # Открытый атрибут
        self.__a = a
        self.__z = z
        self.__b = b
        self.__c = c
        # a,z,b,c - закрытые атрибуты
        #print('Работает конструктор')

    def input(self):
        values = map(float, input('Введите значения (a, z, b, c), разделив их пробелами: ').split())
        self.a, self.z, self.b, self.c = values
        self.x = 0

    def __get_branch1(self):
        return branch1.branch(self.x, self.a, self.z, self.b, self.c)

    def __get_branch2(self):
        return branch2.branch(self.x, self.a, self.z, self.b, self.c)

    def __get_branch3(self):
        return branch3.branch(self.x, self.a, self.z, self.b, self.c)

    def getA(self):
        return self.a

    @property
    def valueOfA(self):
        return self.a

    def get_value(self):
        if self.x < 0 and self.z < 0:
            return self.__get_branch1()
        else:
            if 0 <= self.x and self.x < 4 and 0 <= self.z and self.z < 3:
                return self.__get_branch2()
            else:
                return self.__get_branch3()

def function(x, branching):
    branching.x = x
    return branching.get_value()
