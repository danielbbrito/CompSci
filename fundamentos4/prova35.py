import math

def gradiente(f, x, epsilon=1e-6):
    n = len(x)
    grad = [0] * n
    for i in range(n):
        x_mais = x[:]
        x_mais[i] += epsilon
        grad[i] = (f(x_mais) - f(x)) / epsilon
    return grad

def hessiana(f, x, epsilon=1e-6):
    n = len(x)
    hess = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            x_mais_i = x[:]
            x_mais_j = x[:]
            x_mais_ij = x[:]
            x_mais_i[i] += epsilon
            x_mais_j[j] += epsilon
            x_mais_ij[i] += epsilon
            x_mais_ij[j] += epsilon
            hess[i][j] = (f(x_mais_ij) - f(x_mais_i) - f(x_mais_j) + f(x)) / (epsilon**2)
    return hess

def resolver_sistema_linear(A, b):
    n = len(A)
    for i in range(n):
        max_linha = max(range(i, n), key=lambda r: abs(A[r][i]))
        A[i], A[max_linha] = A[max_linha], A[i]
        b[i], b[max_linha] = b[max_linha], b[i]

        for j in range(i + 1, n):
            razao = A[j][i] / A[i][i]
            for k in range(i, n):
                A[j][k] -= razao * A[i][k]
            b[j] -= razao * b[i]

    x = [0] * n
    for i in range(n - 1, -1, -1):
        soma_ax = sum(A[i][j] * x[j] for j in range(i + 1, n))
        x[i] = (b[i] - soma_ax) / A[i][i]
    return x

def busca_secao_aurea(f, x, d, tol=1e-4):
    phi = (1 + math.sqrt(5)) / 2
    a, b = 0, 1
    while f([x[i] + b * d[i] for i in range(len(x))]) < f([x[i] + a * d[i] for i in range(len(x))]):
        b *= 2

    c = b - (b - a) / phi
    d_b = a + (b - a) / phi

    while abs(b - a) > tol:
        if f([x[i] + c * d[i] for i in range(len(x))]) < f([x[i] + d_b * d[i] for i in range(len(x))]):
            b = d_b
        else:
            a = c

        c = b - (b - a) / phi
        d_b = a + (b - a) / phi

    return (a + b) / 2

def metodo_newton(f, x0, epsilon=1e-6):
    x = x0[:]
    k = 0
    while True:
        grad = gradiente(f, x)
        hess = hessiana(f, x)
        d = resolver_sistema_linear(hess, [-g for g in grad])
        if math.sqrt(sum(di ** 2 for di in d)) <= epsilon:
            break
        t = busca_secao_aurea(f, x, d)
        x = [x[i] + t * d[i] for i in range(len(x))]
        k += 1
    return x, k

def f_problema(x):
    return 0.5 * (x[0] - 2)**2 + (x[1] - 1)**2

def main():
    x0 = [1.0, 0.0]
    epsilon = 1e-6
    solucao, k = metodo_newton(f_problema, x0, epsilon)
    print(f"Solução: {solucao}")
    print(f"{k} iteracoes")

if __name__ == "__main__":
    main()
