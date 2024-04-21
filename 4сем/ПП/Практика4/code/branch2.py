import math

def branch(x, a, z, b, c):
    print("Ветвь 0 <= x < 4 и 0 <= z < 3")
    m = z
    if (math.sqrt(x) > m):
        m = math.sqrt(x)
    if (abs(math.sqrt(x)) > m):
        m = abs(math.sqrt(x))
    return math.log(b ** 2) + m
