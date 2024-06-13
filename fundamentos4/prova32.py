import math

def sub_vetor(v1: list, v2: list):
    res = []
    for i in range(len(v1)):
        res.append(v1[i] - v2[i])

    return res

def dot_product(v1:list, v2:list):
    res = 0

    for i in range(len(v1)):
        res += v1[i] * v2[i]

    return res

def quadrados_minimos(x:list, y:list, n: int, e: list):
    xmean_scalar = 0
    ymean_scalar = 0

    # Calcular xmean
    for xk in x:
        xmean_scalar += xk
    
    xmean_scalar /= n
    xmean = []
    for i in range(len(e)):
        xmean.append(xmean_scalar * e[i])
    
    # Calcular ymean
    for yk in y:
        ymean_scalar += yk

    ymean_scalar /= n

    ymean = []
    for i in range(len(e)):
        ymean.append(ymean_scalar * e[i])

    sumx2 = dot_product(sub_vetor(x, xmean), sub_vetor(x, xmean))
    sumxy = dot_product(sub_vetor(x, xmean), sub_vetor(y, ymean))

    a = sumxy / sumx2

    b = ymean_scalar - a * xmean_scalar

    return (a, b)
    



def main():
    x = [-1, 0, 1, 2, 3, 4, 5, 6]
    y = [10, 9, 7, 5, 4, 3, 0, -1]
    n = len(x)
    e = [1 for i in range(n)]
    a,b = quadrados_minimos(x,y,n,e)

    print(f"y = f(x) = {a}x + {b}")


if __name__ == "__main__":
    main()