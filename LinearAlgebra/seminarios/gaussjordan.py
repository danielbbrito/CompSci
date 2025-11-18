from numpy.linalg import solve

def gauss_jordan(A):
    n = len(A)

    inv = [[0 for j in range(n)] for i in range(n)]
    for i in range(n):
        inv[i][i] = 1
    
    # Realizamos eliminação em A e em inv simultaneamente
    for i in range(n):
        # Partial pivoting
        Amax = A[i][i]
        pivot = i
        for j in range(i + 1, n):
            if abs(A[j][i]) > Amax:
                Amax = abs(A[j][i])
                pivot = j
        
        if pivot != i:
            A[i], A[pivot] = A[pivot], A[i]
            inv[i], inv[pivot] = inv[pivot], inv[i]
        
        if A[i][i] != 0:
            r = 1 / A[i][i]

            for j in range(i + 1, n):
                mult = A[j][i] * r
                A[j][i] = 0

                # Eliminamos em A
                for k in range(i + 1, n):
                    A[j][k] -= mult * A[i][k]

                # Eliminamos em inv
                for k in range(n):
                    inv[j][k] -= mult * inv[i][k]

        else:
            raise ValueError("A matriz é singular e não invertível")
    
    # Agora indo de baixo para cima 
    for i in range(n - 1, -1, -1):
        # Normalizamos a linha
        mult_norm = 1 / A[i][i]
        A[i][i] = 1
        
        for j in range(n):
            inv[i][j] = inv[i][j] * mult_norm
        
        # Agora fazemos a eliminação
        for j in range(i - 1, -1, -1):
            factor = A[j][i]
            A[j][i] = 0

            for k in range(n):
                inv[j][k] -= inv[i][k] * factor

    return inv


A = [
    [1.0, 1/2, 1/3],
    [1/2, 1/3, 1/4],
    [1/3, 1/4, 1/5]
]

A_limited = []

for i in range(len(A)):
    temp = []
    for j in range(len(A)):
        temp.append(round(A[i][j], 3))
    
    A_limited.append(temp)

print("A^-1 com computação exata:")
inv = gauss_jordan(A)
for i in range(len(inv)):
    print(inv[i])
print()
print("A^-1 com arredondamento para 3 casas decimais:")
inv2 = gauss_jordan(A_limited)
for i in range(len(inv2)):
    print(inv2[i])

print()
print("Agora a matriz de hilbert 10x10")

hilbert = []
b = []
for i in range(1, 11):
    b.append(0)
    temp = []
    for j in range(1, 11):
        temp.append(1 / (i + j - 1))
    hilbert.append(temp)

b[0] = 1

x = solve(hilbert, b)
print(f"x = {x}")

print("Com uma pequena mudança:")
b[0] = 0.8
print(f"x' = {solve(hilbert, b)}")

