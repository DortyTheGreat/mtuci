from sympy import *
import decimal

Variant = 16

E1 = 10 + Variant
E2 = 5 + Variant

J = Variant / 10
R1 = 1 + Variant
R2 = 2 + Variant
R3 = 3 + Variant
R4 = 4 + Variant

# 1. Метод Уравнений Киргофа.

#J1 - J2 - J3 = 0 # a
#-J1 + J2 + J3 = 0 # b
print('1. Метод Уравнений Киргофа.')
'''
Контур J11: J2*R1 - J3*(R2 + R3) = E1
Контур J22: J1 * R4 + J3 * (R2 + R3) = E2
'''


J1, J2, J3 = symbols('J1 J2 J3')

eq1 = Eq(J2 * R1 - J3 * (R2 + R3), E1)
eq2 = Eq(J1 * R4 + J3 * (R2 + R3), E2)

eq3 = Eq(J1 - J2 - J3, 0)
eq4 = Eq(-J1 + J2 + J3, 0)

sys = [eq1, eq2, eq3, eq4]


result = solve(sys, (J1, J2, J3), precision=10)

print(result)


result = nsolve(sys, (J1, J2, J3), (-1,-1,-1), precision=10)


list_of_names = ['J1', 'J2', 'J3']
k = 0
for i in result:
    print(list_of_names[k], " : ", i)
    k += 1

print('2. Метод Контурных токов')

'''
J11 * (R1+R3+R2) - J22 * (R2 + R3) = E1 # Контур J11
J22 * (R2+R3+R4) - J11 * (R2+R3) = E2
'''

J11, J22 = symbols('J11 J22')

eq1 = Eq(J11 * (R1+R3+R2) - J22 * (R2 + R3), E1)
eq2 = Eq(J22 * (R2+R3+R4) - J11 * (R2+R3), E2)

sys = [eq1, eq2]


result = solve(sys, (J11, J22), precision=10)

print(result)


result = nsolve(sys, (J11, J22), (-1,-1), precision=10)

# J11 = J2, J22 = J1. Так были выбраны контуры
list_of_names = ['J2', 'J1']
k = 0
for i in result:
    print(list_of_names[k], " : ", i)
    k += 1

# J3 = J1 - J2, по Киргофу, смотря на узел a
J3 = result[1] - result[0]

print("J3  : ", J3)


print('3. Метод Узловых Потенциалов')

'''
Заземлим a.

phi_a = 0

phi_a * G11 - phi_b * G12 = E2*G2 - E1*G1
- phi_a * G12 + phi_b * G22 = E1*G1 - E2*G2

phi_a * ( (1/R1) + (1/R4) + (1/(R2+R3)) ) - phi_b * ((1/R1) + (1/R4) + (1/(R2+R3))) = E2*(1/R4) - E1*(1/R1)
- phi_a * ((1/R1) + (1/R4) + (1/(R2+R3))) + phi_b * ((1/R1) + (1/R4) + (1/(R2+R3))) = E1*(1/R1) - E2*(1/R4)

'''


useless, phi_b = symbols('useless phi_b')

phi_a = 0

# В данном случае очень удобно, что любые рёбра соединяют 2 ноды, поэтому G11=G22=G33=G
G = ( (1/R1) + (1/R4) + (1/(R2+R3)) )

eq1 = Eq(- phi_b * G, E2*(1/R4) - E1*(1/R1))
eq2 = Eq(phi_b * G, E1*(1/R1) - E2*(1/R4))

sys = [eq1, eq2]


result = solve(sys, (phi_a, phi_b), precision=10)
print(result)



phi_b = result[phi_b]

# Из b в a
J1 = (phi_b - phi_a + E2) * (1/R4)
print("J1  : ", J1)

# Из a в b
J2 = (phi_a - phi_b + E1) * (1/R1)
print("J2  : ", J2)

# Из a в b
J3 = (phi_a - phi_b + 0) * (1/(R2 + R3))
print("J3  : ", J3)

# 4

print('4. Метод наложения')

'''
J2 = E1/(R1 + 1/(1/R4 + 1/(R2+R3)))
J1 = E2/(R4 + 1/(1/R1 + 1/(R2+R3)))
J3 = J1 - J2 = 0 (J1 - J2 - J3 = 0)
'''

# Отсавляем только 1 генератор включённым
J1_E2 = E2/(R4 + 1/(1/R1 + 1/(R2+R3)))
J2_E1 = E1/(R1 + 1/(1/R4 + 1/(R2+R3)))

J2_E2 = J1_E2 * ((R2+R3) / (R1 + R2 + R3)) # смотрим какя пропорция тока от J1 победит в ветвь J2
J1_E1 = J2_E1 * ((R2+R3) / (R4 + R2 + R3))

J1 = J1_E1 + J1_E2
J2 = J2_E2 + J2_E1
print("J1  : ", J1)

J2_nofirst = E1/(R1 + 1/(1/R4 + 1/(R2+R3)))
print("J2  : ", J2)


J3 = J1 - J2
print("J3  : ", J3)


## TO-DO: 5


print('6. Баланс мощностей')

P_I = J2**2 * R1 + J1**2 * R4 + J3**2 * (R2 + R3)
P_E = E1 * J2 + E2*J1
print(P_E, P_I)