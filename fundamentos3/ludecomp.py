L = [[1, 0],[0, 1]]

def main():
    '''
    Calcularemos a fatoracao LU para o sistema linear a seguir

    x + 2y = 4
    3x + 5y = 11
    '''

    # Trazendo o sistema para a forma Ax = b
    global A
    A = [
        [1, 2],
        [3, 5]
    ]
    
    b = [
        4,
        11
    ]

    x = [None, None]

    echelon()

    print("Matriz L:")
    for i in range(len(L)):
        print("| ", end="")
        for j in range(len(L[0])):
                print(f"{L[i][j]}", end=" ")
        print("|")
        
    print("Matriz U:")
    for i in range(len(A)):
        print("| ", end="")
        for j in range(len(A[0])):
                print(f"{A[i][j]}", end=" ")
        print("|")

    print("Vetor b:")
    for i in range(len(b)):
        print(f"{b[i]}", end=" ")
    print()

    # Calcula y para Ly = b
    y = []
    y.append(b[0])
    for i in range(1,len(b)):
        soma = 0
        for j in range(i):
            soma = soma + L[i][j] * y[j]
        y.append(b[i] - soma)

    print("Vetor y:")
    for i in range(len(y)):
         print(f"{y[i]}", end=" ")
    print()
    n = len(b) - 1

    x[n] = y[n] / A[n][n]

    for i in range(n,-1,-1):
        soma = 0
        for j in range(i + 1, n):
            soma = soma + A[i][j] * x[j]
        x[i] = (y[i] - soma) / A[i][i]

    print("Vetor solucao x:")
    for i in range(len(x)):
         print(f"x{i} = {x[i]}")
def echelon():
    '''
    Escalona uma matriz
    '''
    global A
    for k in range(len(A) - 1):
        for i in range(k + 1, len(A)):
            m = A[i][k]/A[k][k]
            A[i][k] = 0
            global L
            L[i][k] = m
            for j in range(k + 1, len(A)):
                A[i][j] = A[i][j] - m * A[k][j]

if __name__ == "__main__":
     main()
    