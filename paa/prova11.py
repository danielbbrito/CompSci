import time

def lu_decomposition(A):
    n = len(A)
    L = [[0.0 for _ in range(n)] for _ in range(n)]
    U = [[0.0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        L[i][i] = 1.0
        for j in range(i, n):
            U[i][j] = A[i][j] - sum(L[i][k] * U[k][j] for k in range(i))
        for j in range(i + 1, n):
            L[j][i] = (A[j][i] - sum(L[j][k] * U[k][i] for k in range(i))) / U[i][i]
    
    return L, U

def forward_substitution(L, b):
    n = len(L)
    y = [0.0 for _ in range(n)]

    for i in range(n):
        y[i] = b[i] - sum(L[i][j] * y[j] for j in range(i))
    
    return y

def backward_substitution(U, y):
    n = len(U)
    x = [0.0 for _ in range(n)]

    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - sum(U[i][j] * x[j] for j in range(i + 1, n))) / U[i][i]
    
    return x

def lu(A, b):
    L, U = lu_decomposition(A)
    y = forward_substitution(L, b)
    x = backward_substitution(U, y)
    return x

def determinant(matrix):
    if len(matrix) == 1:
        return matrix[0][0]
    
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    
    det = 0
    for c in range(len(matrix)):
        det += ((-1)**c) * matrix[0][c] * determinant(minor(matrix, 0, c))
    return det

def minor(matrix, i, j):
    return [row[:j] + row[j+1:] for row in (matrix[:i] + matrix[i+1:])]

def cramer(A, b):
    n = len(A)
    det_A = determinant(A)
    if det_A == 0:
        raise ValueError("O sistema não tem solução única.")

    x = []
    for i in range(n):
        A_i = [row[:] for row in A]
        for j in range(n):
            A_i[j][i] = b[j]
        x_i = determinant(A_i) / det_A
        x.append(x_i)
    
    return x

def main():
    A = [
        [4, -1, 0, -1, 0, 0, 0, 0, 0, 0],
        [-1, 4, -1, 0, -1, 0, 0, 0, 0, 0],
        [0, -1, 4, 0, 0, -1, 0, 0, 0, 0],
        [-1, 0, 0, 4, -1, 0, -1, 0, 0, 0],
        [0, -1, 0, -1, 4, -1, 0, -1, 0, 0],
        [0, 0, -1, 0, -1, 4, 0, 0, -1, 0],
        [0, 0, 0, -1, 0, 0, 4, -1, 0, -1],
        [0, 0, 0, 0, -1, 0, -1, 4, -1, 0],
        [0, 0, 0, 0, 0, -1, 0, -1, 4, -1],
        [0, 0, 0, 0, 0, 0, -1, 0, -1, 4]
    ]
    b = [-110, -30, -40, -110, 0, -15, -90, -25, -55, -65]

    # Medir a fatoração LU
    s = time.time()
    x = lu(A, b)
    e = time.time()
    print("Solução:", x)
    print("Tempo de execução para a fatoração LU:", e - s, "segundos")

    # Medir a regra de cramer
    s = time.time()
    x = cramer(A, b)
    e = time.time()
    print("Solução:", x)
    print("Tempo de execução para a regra de cramer:", e - s, "segundos")


    if __name__ == "__main__":
        main()


