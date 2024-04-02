import sys
import math
import cmath

def estima_raizes(a, b, c):
     delta = b ** 2 - 4 * a * c

     if delta == 0:
        x = (-b + math.sqrt(delta)) / (2 * a)
        return x
     elif delta > 0:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        return x1, x2

     else:
        x1 = (-b + cmath.sqrt(delta)) / (2 * a)
        x2 = (-b - cmath.sqrt(delta)) / (2 * a)
        return x1, x2

def f(x):             
	return 1e-8 * (x ** 2) - 0.8 * x + 1e-8

def f_prime(x):
	return 2e-8 - 0.8

def newtons_method(x0, e):
    k = 0

    machine_epsilon = sys.float_info.epsilon
    while True:
         fx = f(x0)
         fprime = f_prime(x0)

         if abs(fprime) < machine_epsilon:
              return None
         
         x0 = x0 - fx / fprime
         k += 1

         if abs(fx) <= e:
              break
    return x0, k



def acha_raizes(a, b, c, inicial, tolerance):
    def f(x):
        return 1e-8 * (x**2) - 0.8 * x + 1e-8
     
    def f_prime(x):
        return 2e-8 - 0.8
     
    raizes = []

    for i in inicial:
          raiz = newtons_method(i, tolerance)

          if raiz is not None and raiz not in raizes:
               raizes.append(raiz)

    return raizes

eps = sys.float_info.epsilon

# Achar raizes
a = float(input("a = "))
b = float(input("b = "))
c = float(input("c = "))

inicial = estima_raizes(a, b, c)

raizes = acha_raizes(a, b, c, inicial, 1e-8)

for i in range(len(raizes)):
     print(f"x{i+1} = {raizes[i][0]}")

