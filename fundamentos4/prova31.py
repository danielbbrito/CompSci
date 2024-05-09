import math

def polinomio_lagrange(x: list, y: list, z: float) -> float:
    r = 0

    for i in range(1, 5): # Tomando apenas os n + 1 pontos mais próximos
        c = 1
        d = 1
        for j in range(1, 5):
            if i != j:
                c = c * (z - x[j])
                d = d * (x[i] - x[j])
        
        r = r + y[i] * (c / d)
    

    return r


def main():
    m = 7
    z = 1.4
    x = [0.7, 1.2, 1.3, 1.5, 2, 2.3, 2.6]
    y = [0.043, 1.928, 2.497, 3.875, 9, 13.467, 19.176]

    r = polinomio_lagrange(x, y, z)

    print(r)

if __name__ == "__main__":
    main()
