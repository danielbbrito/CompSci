from random import randint
import timeit

def main():
    print("---ALGORITMOS DE ORDENAÇÃO---")
    while True:
        print("Escolha o tipo de geração do vetor:", "1. Aleatório", "2. Crescente", "3. Decrescente", sep="\n")
        tipo_vetor = int(input("Escolha: "))
        print()

        tamanho_vetor = int(input("Agora, escolha o tamanho do vetor: "))
        print()

        # Criar e popular vetor baseado nos parâmetros especificados
        vetor = []

        if tipo_vetor == 1:
            vetor = vetor_aleatorio(tamanho_vetor)
        
        elif tipo_vetor == 2:
            for i in range(tamanho_vetor):
                vetor.append(i)
        
        elif tipo_vetor == 3:
            for i in range(tamanho_vetor):
                vetor.append(tamanho_vetor - i)

        # Criar backup do vetor
        vetor_backup = vetor

        while True:
            # Dar opções de ação sobre o vetor
            print("Selecione uma das opções abaixo: ", "1. Imprimir vetor original", "2. Ordenar vetor", "3. Novo vetor", "4. Sair", sep="\n")

            opcao = int(input("Escolha: "))
            if opcao == 1:
                print(vetor)
            
            elif opcao == 2:
                while True:
                    vetor = vetor_backup.copy()
                    print("Qual algoritmo deseja utilizar?", 
                        "1. Selection Sort", 
                        "2. Bubble Sort", 
                        "3. Insertion Sort", 
                        "4. Merge Sort", 
                        "5. Quick Sort", 
                        "6. Heap Sort",
                        "7. Nenhum, sair",
                        sep="\n")

                    algo = int(input("Escolha: "))

                    global trocas, comparacoes
                    trocas = 0
                    comparacoes = 0
                    if algo == 1:
                        print("\nExecutando insertion sort")
                        time = timeit.timeit(lambda: selection_sort(vetor, len(vetor)), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")

                    elif algo == 2:
                        print("\nExecutando bubble sort")
                        time = timeit.timeit(lambda: bubble_sort(vetor, len(vetor)), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")
                        
                    elif algo == 3:
                        print("\nExecutando insertion sort")
                        time = timeit.timeit(lambda: insertion_sort(vetor, len(vetor)), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")

                    elif algo == 4:
                        print("\nExecutando merge sort")
                        time = timeit.timeit(lambda: merge_sort(vetor, 0, len(vetor) - 1), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")
                    elif algo == 5:
                        print("\nExecutando quick sort")
                        time = timeit.timeit(lambda: randomized_quick_sort(vetor, 0, len(vetor) - 1), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")
                    elif algo == 6:
                        print("\nExecutando heap sort")
                        time = timeit.timeit(lambda: heap_sort(vetor, len(vetor)), number=1) * 1000
                        print(f"Execução finalizada em {time: .4f}ms")
                        print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")
                    elif algo == 7:
                        break

                    print("Imprimir vetor ordenado?\n1.Sim\n2. Nao")
                    to_print = int(input("Escolha: "))

                    if to_print == 1:
                        print(vetor)
                    else:
                        print("tudo bem :(\n")
                        break


                
                

            
            elif opcao == 3:
                break

            elif opcao == 4:
                exit()



def vetor_aleatorio(tam):
    v = []
    for i in range(tam):
        v.append(randint(0, 10000))
    
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
        A.append(arr[l + i])

    for i in range(size_b):
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