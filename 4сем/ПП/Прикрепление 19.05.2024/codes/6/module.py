class TPupil:
    def input(self):
        try:
            self.number, self.history, self.english, self.math, self.physics, self.biology =\
                map(int, input('Введите номер студента и его баллы, разделив данные пробелами: ').split())
        except:
            print('Произошла ошибка Ввода. Все данные о студенте - целые числа')
            exit(0)

def math_physics(pupils, n):
    k1 = 0
    for i in range(n):
        if pupils[i].math + pupils[i].physics > 150:
            k1 += 1
    return k1

def get_max_points(pupils, n):
    max_points = -1
    max_index = -1
    for i in range(n):
        summ = pupils[i].history + pupils[i].english + pupils[i].math + pupils[i].physics + pupils[i].biology
        if summ > max_points:
            max_points = summ
            max_index = i + 1

    return max_points, max_index