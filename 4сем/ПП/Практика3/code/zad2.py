class MyClass:
    pass


MyClass.x = 100
obj1, obj2 = MyClass(), MyClass()
obj1.y = 10
obj2.y = 20

print(f'obj1.x = {obj1.x} obj1.y = {obj1.y}')
print(f'obj2.x = {obj2.x} obj2.y = {obj2.y}')
