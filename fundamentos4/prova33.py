import math
def f(x):
    return x ** x

def D(x, h, k):
    return (f(x + ((10 ** -k) * h)) - f(x - ((10 ** -k) * h))) / (2 * ((10 ** -k) * h))

def aprox_derivada(toler, h, x):
    Dnm1 = D(x, h, 0)
    Dn = D(x, h, 1)
    k = 1
    while True:
        k += 1
        Dn1 = D(x, h, k)

        if abs(Dn1 - Dn) >= abs(Dn - Dnm1) or abs(Dn - Dnm1) < toler:
            break

        Dnm1 = Dn
        Dn = Dn1

    return Dn


def main():
    h = 1e-5
    toler = 1e-5
    x = 0.0001
    ans = aprox_derivada(toler, h, x)
    print(ans)


if __name__ == "__main__":
    main()