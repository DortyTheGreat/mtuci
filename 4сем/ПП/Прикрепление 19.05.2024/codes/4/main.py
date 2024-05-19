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
        print('Работает конструктор')

    def input(self):
        values = map(float, input('Введите значения (x, a, z, b, c), разделив их пробелами: ').split())
        self.x, self.a, self.z, self.b, self.c = values

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




choice = None
while choice!="0":
    print("Меню 0 - Выйти, 1 - Выполнить программу")
    choice = input("Сделайте выбор ")
    print()

    if choice == "0":
        print("Заканчиваем работу")
    elif choice =="1":
        print("Введите исходные данные ", end="")
        branching = Branches(0, 0, 0, 0, 0)
        try:
            branching.input()
        except:
            print("Произошла ошибка ввода")
            continue

        #print(branching.__a) - раскоментировать, для получения ошибки
        print(f'Результат ветвления: {round(branching.get_value(), 5)}')
        print(f'Значение а через @property: {branching.valueOfA}')
        print(f'Значение а через getter: {branching.getA()}')
    else:
        print("Такого пункта в меню нет:", choice)

