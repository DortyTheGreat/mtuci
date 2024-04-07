class MyClass:
    x = 10

    def __init__(self):
        self.y = 20


obj1, obj2 = MyClass(), MyClass()
print(f'obj1.x = {obj1.x} obj2.x = {obj2.x}')
MyClass.x = 50
print(f'obj1.x = {obj1.x} obj2.x = {obj2.x}')
print(f'obj1.y = {obj1.y} obj2.y = {obj2.y}')
obj1.y = 90
print(f'obj1.y = {obj1.y} obj2.y = {obj2.y}')
obj2.x = 60
MyClass.x = 80
print(f'obj1.x = {obj1.x} obj2.x = {obj2.x} MyClass.x = {MyClass.x}')
