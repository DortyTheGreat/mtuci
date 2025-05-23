from sympy import *
import decimal
import cmath
import math
import sympy
import numpy as np
import matplotlib.pyplot as plt

Variant = 16
Kursovaya_number = 2

if Kursovaya_number == 1:
  E1 = -(10 + Variant)
  E2 = 5 + Variant

  J = Variant / 10
  R1 = 1 + Variant
  R2 = 2 + Variant
  R3 = 3 + Variant
  R4 = 4 + Variant

  E1_dir = -1
  E2_dir = 1

  J1_dir = 1
  J2_dir = 1
  J3_dir = -1

  Z1 = R1
  Z2 = R4
  Z3 = R2 + R3
else:
  E1 = -100
  E2 = 50 * cmath.exp(1j * 10 * Variant)

  f = 50
  omega = 2*math.pi*f
  R1 = 1 + Variant
  R2 = 2 + Variant
  R3 = 5 + Variant

  L1 = (5 + Variant) * 10**-3
  L2 = (6 + Variant) * 10**-3
  L3 = (10 + Variant) * 10**-3

  C1 = (200 + Variant) * 10**-6
  C2 = (210 + Variant) * 10**-6
  C3 = (220 + Variant) * 10**-6

  E1_dir = -1
  E2_dir = 1

  J1_dir = 1
  J2_dir = 1
  J3_dir = -1

  Z1 = R1 + 1j*omega*L1
  Z2 = R3 + 1/(1j*omega*C3)
  Z3 = R2 + 1/(1j*omega*C2)


def f_J1(t_arr):
  ret = []
  for elem in t_arr:
    ret.append(abs(J1) * sin(2*math.pi*f*elem + J1.imag))
  return ret

J1 = J2 = J3 = 1

from sympy.core.rules import Transform
def cooll(val):
  try:
    return val.evalf()
  except:
    return sympy.core.add.Add(val)

def coole(val):
  return N(cooll(val),4)

def balance():
  '''
  J2^2 * Z2 + J1^2 * Z1 + J3^2 * Z3 =
  = E1 * J1 + E2 * J2
  '''

  P_I = (J2*J2_dir)**2 * Z2 + (J1*J1_dir)**2 * Z1 + (J3*J3_dir)**2 * Z3
  P_E = (E1*E1_dir) * (J1*J1_dir) + (E2*E2_dir) * (J2*J2_dir) # Т.к. У нас всякое происходит с направлениями, то вот так вот надобно бы сделать

  print()
  print('Cумма мощностей, потребляемых приёмниками: ', coole(P_I), 'Вт')
  print('Cумма мощностей, отдаваемых источниками: ', coole(P_E), 'Вт')
  print()


def printJ():
  print("J1  : ", coole(J1), 'А')
  print("J2  : ", coole(J2), 'А')
  print("J3  : ", coole(J3), 'А')

precision = 3
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


result = solve(sys, (J1, J2, J3), precision=precision)

J1 = result[J1].evalf()
J2 = result[J2].evalf()
J3 = result[J3].evalf()

if Kursovaya_number == 2:
  plt.plot([0, complex(J1).real], [0, complex(J1).imag], marker='o', linestyle='-', color='blue', label='J1')
  plt.plot([0, complex(J2).real], [0, complex(J2).imag], marker='o', linestyle='-', color='red', label='J2')
  plt.plot([0, complex(J3).real], [0, complex(J3).imag], marker='o', linestyle='-', color='green', label='J3')
  #plt.plot(data['x'][num_iterations:], data['y'][num_iterations:], marker='o', linestyle='-', color='red', label='ГДШ')
  plt.xlabel('Действительная часть тока')
  plt.ylabel('Мнимая часть тока')


  plt.show()
  pass

print(result)

printJ()
balance()

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


result = solve(sys, (J11, J22), precision=precision)

print(result)
J3 = result[J22].evalf() - result[J11].evalf()
J1 = result[J11].evalf()
J2 = result[J22].evalf()

printJ()
balance()

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


result = solve(sys, phi_2, precision=precision)
print(result)



phi_2 = result[phi_2]

# Из (1) в (2)
J1 = (phi_1 - phi_2 - E1) * (1/Z1)


# Из (1) в (2)
J2 = (phi_1 - phi_2 - E2) * (1/Z2) * (-1)


# Из (1) в (2)
J3 = (phi_1 - phi_2 + 0) * (1/Z3)
printJ()
balance()

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

printJ()
balance()

print()
print('5. Метод Эквивалентного генератора')


J_R1, J_RR = symbols('JR1 JRR')

eq1 = Eq(J_R1 * (Z1 + Z3) - J_RR * Z3, -E1)
eq2 = Eq(J_RR * (Z2 + Z3) - J_R1 * Z3, E2)




sys = [eq1, eq2]


result = solve(sys, (J_R1, J_RR), precision=precision)
if Kursovaya_number == 2:
  t1 = np.arange(0.0, 0.1, 0.0001)
  plt.figure()
  plt.subplot(211)
  plt.plot(t1, f_J1(t1), 'bo')

  plt.xlabel('t, секунды')
  plt.ylabel('I, А')
  plt.show()
  pass
#print(result)
print("J_Z1  : ", coole(result[J_R1]), 'А')
print("J_Z2  : ", coole(result[J_RR].evalf()), 'А')
print("J_Z3  : ", coole(result[J_RR].evalf() - result[J_R1]), 'А')

balance()


