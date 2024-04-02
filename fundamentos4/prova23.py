import sys
import numpy as np
def f(x):
    return x**4 
     
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


inicial = np.longdouble(input("x0 = "))
raiz, iteracoes = newtons_method(inicial, 1e-6)

print(f"Encontrada a raiz x = {raiz} em {iteracoes} iteracoes")