import sys

def f(x):
    return x**4 - 12 * (x**3) + 47 * (x**2) - 60 * x

     
def f_prime(x):
    return 4 * (x**3) - 36 * (x**2) + 94 * x - 60

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


inicial = float(input("x0 = "))
raiz, iteracoes = newtons_method(inicial, 1e-8)

print(f"Encontrada a raiz x = {raiz:.4f} em {iteracoes} iteracoes")