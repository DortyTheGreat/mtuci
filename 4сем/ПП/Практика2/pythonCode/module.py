import math

def func(x, a, z, b, c):

    if x < 0 and z < 0:
        m = x
        if a > m:
            m = a
        m2 = z
        if x * a ** m < m2:
            m2 = x * a ** m
        return math.log(x * a + m2)
    else:
        if 0 <= x and x < 4 and 0 <= z and z < 3:
            m = z
            if (math.sqrt(x) > m):
                m = math.sqrt(x)
            if (abs(math.sqrt(x)) > m):
                m = abs(math.sqrt(x))
            return math.log(b ** 2) + m
        else:
            return b + c * x