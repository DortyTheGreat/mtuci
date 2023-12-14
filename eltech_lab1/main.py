from sympy import *
import decimal

Variant = 16

E1 = -(10 + Variant)
E2 = 5 + Variant

J = Variant / 10
R1 = 1 + Variant
R2 = 2 + Variant
R3 = 3 + Variant
R4 = 4 + Variant



Z1 = R1
Z2 = R4
Z3 = R2 + R3


# 1. Метод Уравнений Киргофа.

#J1 - J2 - J3 = 0 # a
#-J1 + J2 + J3 = 0 # b
print('1. Метод Уравнений Кирхгофа.')
'''
Z1 * J1 - J3 * Z3 = -E1 (Контур J11)
J2 * Z2 + J3 * Z3 = E2 (Контур J11)

J2 - J1 - J3 = 0 (Узел 1)
J3 + J1 - J2 = 0 (Узел 2)
'''


J1, J2, J3 = symbols('J1 J2 J3')

eq1 = Eq(Z1 * J1 - J3 * Z3, -E1)
eq2 = Eq(J2 * Z2 + J3 * Z3, E2)

eq3 = Eq(J2 - J1 - J3, 0)
eq4 = Eq(J3 + J1 - J2, 0)

sys = [eq1, eq2, eq3, eq4]


result = solve(sys, (J1, J2, J3), precision=10)

print(result)
print("J1  : ", result[J1].evalf())
print("J2  : ", result[J2].evalf())
print("J3  : ", result[J3].evalf())


print()
print('2. Метод Контурных токов')

'''
J11 * (Z1 + Z3) - J22 * Z3 = -E1 (Контур J11)
J22 * (Z2 + Z3) - J11 * Z3 = E2  (Контур J22)
J3 = J22 - J11 (По I Закону Киргхофа)
'''

J11, J22 = symbols('J11 J22')

eq1 = Eq(J11 * (Z1 + Z3) - J22 * Z3, -E1)
eq2 = Eq(J22 * (Z2 + Z3) - J11 * Z3, E2)

sys = [eq1, eq2]


result = solve(sys, (J11, J22), precision=10)

print(result)
print("J1  : ", result[J11].evalf())
print("J2  : ", result[J22].evalf())
print("J3  : ", result[J22].evalf() - result[J11].evalf())


print()
print('3. Метод Узловых Потенциалов')

'''
Заземлим узел 1. phi_1 = 0

-phi_2 * ((1/Z1) + (1/Z2) + (1/Z3)) = E2*(1/Z2) + E1*(1/Z1) (узел 1)
phi_2 * ((1/Z1) + (1/Z2) + (1/Z3)) = -E2*(1/Z2) - E1*(1/Z1) (узел 2)
'''


phi_2 = symbols('phi_2')

phi_1 = 0


eq1 = Eq(-phi_2 * ( (1/Z1) + (1/Z2) + (1/Z3) ), E2*(1/Z2) + E1*(1/Z1))
eq2 = Eq(phi_2 * ((1/Z1) + (1/Z2) + (1/Z3)), -E2*(1/Z2) - E1*(1/Z1))

sys = [eq1, eq2]


result = solve(sys, phi_2, precision=10)
print(result)



phi_2 = result[phi_2]

# Из (1) в (2)
J1 = (phi_1 - phi_2 - E1) * (1/Z1)
print("J1  : ", J1)

# Из (1) в (2)
J2 = (phi_1 - phi_2 - E2) * (1/Z2) * (-1)
print("J2  : ", J2)

# Из (1) в (2)
J3 = (phi_1 - phi_2 + 0) * (1/Z3)
print("J3  : ", J3)

# 4
print()
print('4. Метод наложения')

'''
J1_E1 = -E1 / (Z1 + 1/(1/Z2 + 1/Z3)) (ток у J1 при E1, также ток в цепи)
J2_E2 = E2 / (Z2 + 1/(1/Z1 + 1/Z3)) (ток у J2 при E2, также ток в цепи)

J1_E2 = J2_E2 * ( Z3 / (Z1 + Z3))
J2_E1 = J1_E1 * ( Z3 / (Z2 + Z3))

J1 = J1_E1 + J1_E2
J2 = J2_E1 + J2_E2
J3 = J2 - J1
'''

# Отсавляем только 1 генератор включённым
J1_E1 = -E1 / (Z1 + 1/(1/Z2 + 1/Z3))
J2_E2 = E2 / (Z2 + 1/(1/Z1 + 1/Z3))

J1_E2 = J2_E2 * ( Z3 / (Z1 + Z3))
J2_E1 = J1_E1 * ( Z3 / (Z2 + Z3))

J1 = J1_E1 + J1_E2
J2 = J2_E1 + J2_E2
J3 = J2 - J1

print("J1  : ", J1)
print("J2  : ", J2)
print("J3  : ", J3)

print()
print('5. Метод Эквивалентного генератора')


J_R1, J_RR = symbols('JR1 JRR')

eq1 = Eq(J_R1 * (Z1 + Z3) - J_RR * Z3, -E1)
eq2 = Eq(J_RR * (Z2 + Z3) - J_R1 * Z3, E2)

sys = [eq1, eq2]


result = solve(sys, (J_R1, J_RR), precision=10)

#print(result)
print("J_R1  : ", result[J_R1].evalf())


print()
print('6. Баланс мощностей')

'''
J2^2 * Z2 + J1^2 * Z1 + J3^2 * Z3 =
= E1 * J1 + E2 * J2
'''

P_I = J2**2 * Z2 + J1**2 * Z1 + J3**2 * Z3
P_E = abs(E1 * J1) + abs(E2 * J2) # Т.к. У нас всякое происходит с направлениями, то вот так вот надобно бы сделать

print('Cумма мощностей, потребляемых приёмниками: ', P_I)
print('Cумма мощностей, отдаваемых источниками: ', P_E)
