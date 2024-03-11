from random import randint
import timeit



def main():
    print("---ALGOTMOS DE ORDENAÇÃO---")
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

    # Dar opções de ação sobre o vetor

    while True:
        print("Selecione uma das opções abaixo: ", "1. Imprimir vetor original", "2. Ordenar vetor", "3. Sair do programa", sep="\n")

        opcao = int(input("Escolha: "))

        if opcao == 1:
            print(vetor)
        
        elif opcao == 2:
            while True:
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
                    print(f"Execução finalizada em {time}ms")
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
                    print("\nExecutando merge sort")
                    time = timeit.timeit(lambda: quick_sort(vetor, 0, len(vetor) - 1), number=1) * 1000
                    print(f"Execução finalizada em {time: .4f}ms")
                    print(f"Foram realizadas {trocas} trocas e {comparacoes} comparações.\n")
                elif algo == 6:
                    pass # Heap sort
                    print(f"Execução finalizada em {time: .4f}ms")
                elif algo == 7:
                    break


            
            

        
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
    if l < r:
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

if __name__ == "__main__":
    main()