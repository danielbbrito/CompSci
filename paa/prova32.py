import time
from random import randint

def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

def fib2(dp: list, n):
    if n < 2:
        return n

    if dp[n] is not None:
        return dp[n]
    
    dp[n] = fib2(dp, n - 1) + fib2(dp, n - 2)
    return dp[n]

def vetor_aleatorio(tam):
    v = []
    for i in range(tam):
        v.append(randint(0, 10000))
    
    return v

def main():

    print("Execucao para n = 10: ")
    print("Fibonnaci com programação dinâmica: ")
    ls = [None for x in range(11)]
    st = time.time()
    n = fib2(ls, 10)
    ed = time.time()
    ls.clear()
    
    print(f"    Resultado: {n}")
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()

    print("Fibonnaci: ")
    
    st = time.time()
    n = fib(10)
    ed = time.time()

    print(f"    Resultado: {n}")
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()


    print("Execucao para n = 100: ")

    print("Fibonnaci com programação dinâmica: ")

    ls = [None for x in range(101)]
    st = time.time()

    n = fib2(ls, 100)
    ed = time.time()
    print(f"    Resultado: {n}")
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()

    print("Fibonnaci: ")

    st = time.time()
    n = fib(100)
    ed = time.time()
    
    print(f"    Resultado: {n}")
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()

if __name__ == "__main__":
    main()