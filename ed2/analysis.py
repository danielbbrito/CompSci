from random import randint
import timeit
import pandas as pd



def main():
    print("---ALGORITMOS DE ORDENAÇÃO---")

    # Dar opções de ação sobre o vetor

    while True:
        print("Selecione uma das opções abaixo: ", "1. Imprimir vetor original", "2. Ordenar vetor", "3. Sair do programa", sep="\n")

        opcao = int(input("Escolha: "))

        if opcao == 1:
            print()
        
        elif opcao == 2:
                global trocas, comparacoes
                trocas = 0
                comparacoes = 0

                runtime = []
                trocou = []
                compara = []

                sizes = [100, 1000, 10000, 100000, 1000000]

                for i in range (6):
                    trocou.append([])
                    runtime.append([])
                    compara.append([])
                
                for i in range(len(sizes)):
                    print(f"Running size {sizes[i]}")
                    vetor = vetor_aleatorio(sizes[i])
                    vetor_backup = vetor.copy()
                    if sizes[i] < 1000000:
                        print("Running 1")
                        time = timeit.timeit(lambda: selection_sort(vetor, len(vetor)), number=1) * 1000
                        trocou[0].append(trocas)
                        compara[0].append(comparacoes)
                        runtime[0].append(time)
                        trocas = 0
                        comparacoes = 0
                        vetor = vetor_backup.copy()
                        
                        print("Running 2")
                        time = timeit.timeit(lambda: bubble_sort(vetor, len(vetor)), number=1) * 1000
                        trocou[1].append(trocas)
                        compara[1].append(comparacoes)
                        runtime[1].append(time)
                        trocas = 0
                        comparacoes = 0
                        vetor = vetor_backup.copy()

                        print("running 3")
                        time = timeit.timeit(lambda: insertion_sort(vetor, len(vetor)), number=1) * 1000
                        trocou[2].append(trocas)
                        compara[2].append(comparacoes)
                        runtime[2].append(time)
                        trocas = 0
                        comparacoes = 0
                        vetor = vetor_backup.copy()
                    
                    else:
                        for i in range(3):
                            trocou[i].append(0)
                            compara[i].append(0)
                            runtime[i].append(0)

                    print("Running 4")
                    time = timeit.timeit(lambda: merge_sort(vetor, 0, len(vetor) - 1), number=1) * 1000
                    trocou[3].append(trocas)
                    compara[3].append(comparacoes)
                    runtime[3].append(time)
                    trocas = 0
                    comparacoes = 0
                    vetor = vetor_backup.copy()

                    print("Running 5")
                    time = timeit.timeit(lambda: randomized_quick_sort(vetor, 0, len(vetor) - 1), number=1) * 1000
                    trocou[4].append(trocas)
                    compara[4].append(comparacoes)
                    runtime[4].append(time)
                    trocas = 0
                    comparacoes = 0
                    vetor = vetor_backup.copy()
                    
                    print("Running 6")
                    time = timeit.timeit(lambda: heap_sort(vetor, len(vetor)), number=1) * 1000
                    trocou[5].append(trocas)
                    compara[5].append(comparacoes)
                    runtime[5].append(time)
                    trocas = 0
                    comparacoes = 0
                    vetor = vetor_backup.copy()
                
                algos = ["Selection Sort", "Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort"]
                # Print to excel
                df_runtime = pd.DataFrame(runtime, index=algos, columns=sizes)
                df_runtime.to_excel("crescente.xlsx")

                df_exchange = pd.DataFrame(trocou, index=algos, columns=sizes)
                df_exchange.to_excel("exchanges_cres.xlsx")

                df_compare = pd.DataFrame(compara, index=algos, columns=sizes)
                df_compare.to_excel("compare_cres.xlsx")

            

        
        elif opcao == 3:
            exit()



def vetor_aleatorio(tam):
    v = []
    for i in range(tam):
        v.append(randint(-9223372036854775808, 9223372036854775807))
    
    return v

def selection_sort(arr: list, n: int) -> None:
    for i in range(n):
        minimum = i
        for j in range(i + 1, n):
            global comparacoes
            comparacoes += 1
            if arr[j] < arr[minimum]:
                minimum = j
        global trocas
        trocas += 1
        (arr[i], arr[minimum]) = (arr[minimum], arr[i])



def insertion_sort(arr: list, n: int) -> None:
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            global comparacoes
            comparacoes += 1
            global trocas
            trocas += 1
            arr[j + 1] = arr[j]
            j -= 1

        trocas += 1
        comparacoes += 1
        arr[j + 1] = key


def bubble_sort(arr: list, n: int) -> None:
    global trocas, comparacoes

    for i in range(n - 1):
        sorted = True
        for j in range(n - i - 1):
            comparacoes += 1
            if arr[j] > arr[j + 1]:
                trocas += 1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                sorted = False
        
        if sorted:
            break


def merge(arr, l, m, r):
    global comparacoes, trocas
    size_a = m - l + 1
    size_b = r - m

    A = []
    B = []
    for i in range(size_a):
        trocas += 1
        A.append(arr[l + i])

    for i in range(size_b):
        trocas += 1
        B.append(arr[m + 1 + i])

    i = 0
    j = 0
    k = l

    while i < size_a and j < size_b:
        comparacoes += 1
        if A[i] <= B[j]:
            trocas += 1
            arr[k] = A[i]
            i += 1
        
        else:
            trocas += 1
            arr[k] = B[j]
            j += 1
        
        k += 1

    while i < size_a:
        trocas += 1
        arr[k] = A[i]
        i += 1
        k += 1
    
    while j < size_b:
        trocas += 1
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


def partition(arr: list, l: int, r: int) -> int:
    global trocas, comparacoes
    x = arr[r]
    i = l - 1

    for j in range(l, r):
        comparacoes += 1
        if arr[j] <= x:
            trocas += 1
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    trocas += 1
    arr[i + 1], arr[r] = arr[r], arr[i + 1]
    return i + 1

def quick_sort(arr: list, l: int, r: int) -> None:
    if l >= r:
        return
    q = partition(arr, l, r)
    quick_sort(arr, l, q - 1)
    quick_sort(arr, q + 1, r)


def randomized_partition(arr: list, l: int, r: int) -> int:
    i = randint(l, r)

    arr[i], arr[r] = arr[r], arr[i]
    return partition(arr, l, r)

def randomized_quick_sort(arr: list, l:int, r: int) -> None:
    if l < r:
        q = randomized_partition(arr, l, r)
        randomized_quick_sort(arr, l, q - 1)
        randomized_quick_sort(arr, q + 1, r)

def heapify(arr: list, n: int, i: int) -> None:
    global comparacoes, trocas
    largest = i
    left_child = 2 * i + 1
    right_child = 2 * i + 2

    comparacoes += 3
    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child

    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child

    if largest != i:
        trocas += 1
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr: list, n: int) -> None:
    global comparacoes, trocas

    # max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        trocas += 1
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

if __name__ == "__main__":
    main()