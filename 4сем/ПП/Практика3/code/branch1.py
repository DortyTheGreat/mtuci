import math

def branch(x, a, z, b, c):
    print("Ветвь x < 0 и z < 0")
    m = x
    if a > m:
        m = a
    m2 = z
    if x * a ** m < m2:
        m2 = x * a ** m
    return math.log(x * a + m2)
