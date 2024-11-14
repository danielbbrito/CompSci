import time
from random import randint

def selection_sort(arr: list, n: int) -> None:
    for i in range(n):
        minimum = i
        for j in range(i + 1, n):
            if arr[j] < arr[minimum]:
                minimum = j
        (arr[i], arr[minimum]) = (arr[minimum], arr[i])

def merge(arr, l, m, r):
    size_a = m - l + 1
    size_b = r - m

    A = []
    B = []
    for i in range(size_a):
        A.append(arr[l + i])

    for i in range(size_b):
        B.append(arr[m + 1 + i])

    i = 0
    j = 0
    k = l

    while i < size_a and j < size_b:
        if A[i] <= B[j]:
            arr[k] = A[i]
            i += 1
        
        else:
            arr[k] = B[j]
            j += 1
        
        k += 1

    while i < size_a:
        arr[k] = A[i]
        i += 1
        k += 1
    
    while j < size_b:
        arr[k] = B[j]
        j += 1
        k += 1


def merge_sort(arr: list, l:int, r: int) -> None:
    if l >= r:
        return
    
    mid = (l + r) // 2

    merge_sort(arr, l, mid)
    merge_sort(arr, mid + 1, r)
    merge(arr, l, mid, r)

def vetor_aleatorio(tam):
    v = []
    for i in range(tam):
        v.append(randint(0, 10000))
    
    return v

def main():
    v10 = vetor_aleatorio(10)
    v1000 = vetor_aleatorio(1000)

    print("Execucao para um vetor n = 10: ")
    print("Selection Sort: ")
    v10c = v10.copy()
    st = time.time()
    selection_sort(v10c, 10)
    ed = time.time()
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()
    print("Merge sort: ")
    v10c = v10.copy()
    st = time.time()
    merge_sort(v10c, 0, 9)
    ed = time.time()
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()

    print("Execucao para um vetor n = 1000: ")
    print("Selection Sort: ")
    v1000c = v1000.copy()
    st = time.time()
    selection_sort(v1000c, 1000)
    ed = time.time()
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()
    print("Merge sort: ")
    v1000c = v1000.copy()
    st = time.time()
    merge_sort(v1000c, 0, 999)
    ed = time.time()
    print(f"    Tempo de execucao: {(ed - st) * 1000}ms")
    print()

if __name__ == "__main__":
    main()