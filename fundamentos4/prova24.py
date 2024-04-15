import math

# Algoritmo como descrito em "Algoritmos numéricos", Frederico Ferreira Campos
def jacobi(A, n, b, x0, e, itermax):
    iter = 0
    x = x0.copy()

    for i in range(n):
        r = 1 / A[i][i]
        for j in range(n):
            if i != j:
                A[i][j] *= r
        b[i] *= r
    
    v = x.copy()

    while True:
        iter += 1

        for i in range(n):
            soma = 0
            for j in range(n):
                if i != j:
                    soma += A[i][j] * x[j]
            v[i] = b[i] - soma
        
        norma_num = 0
        norma_den = 0

        for i in range(n):
            t = abs(v[i] - x[i])
            if t > norma_num:
                norma_num = t
            
            if abs(v[i]) >norma_den:
                norma_den = abs(v[i])

            x[i] = v[i]
        
        norma_rel = norma_num / norma_den

        if norma_rel <= e or iter > itermax:
            break
    
    return x, iter

A = [[10, 3, -2],
     [2, 8, -1],
     [1, 1, 5]]

b = [57,
     20,
     -4]

eps = 1e-5

x0 = [0,
      0,
      0]

print("Resolveremos o sistema Ax = b pelo metodo de Jacobi")

for i in range(len(A)):
    print("| ", end="")
    for j in range(len(A[i])):
        print(f"{A[i][j]} ", end="")
    
    print(" " * (i + 1) + "|" + " ", end="")
    print("| 0 |", end="")
    if i == 1:
        print("=", end="")
        print(f"| {b[i]} |")

    else:
        print(f" | {b[i]} |")

print()
print("Usaremos como ponto inical x0 = 0 e tolerancia e = 1e-5")
print("Temos o vetor solucao x=")

ans, k = jacobi(A, len(A), b, x0, eps, 1000)
print("[", end=" ")
for a in ans:
    print(f"{a} ", end="")

print("]")

print(f"Em {k} iteracoes") 