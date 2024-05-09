import math
from hash_table import HashTable
from arquivo import Arquivo
from colors import bcolors

def main():
    # Ler arquivos e indexar cada palavra no indice invertido
    directory_path = "ed2/search_engine/arquivos-colecao-index/arq"
    indice_invertido = HashTable()
    indice = HashTable()
    print("Lendo arquivos. Aguarde.")
    for i in range(1, 68):
        arquivo = None
        if i < 10:
            arquivo = "0" + str(i)
        else:
            arquivo = str(i)

        arquivo = directory_path + arquivo + ".txt"

        with open(arquivo, mode="r") as FILE:
            for line in FILE:
                palavra = ""
                # This is probs wrong
                for c in line:
                    if c.isalpha():
                        palavra += c.lower()

                    else:
                        if len(palavra) < 4:
                            palavra = ""
                            continue

                        
                        indice_busca = indice_invertido.search(palavra)
                        existe_na_tabela = False
                        
                        if indice_busca is not None:
                            # Procurar pelo arquivo de mesmo nome
                            for arq in indice_busca:
                                if arq.get_nome() == arquivo:
                                    existe_na_tabela = True
                                    # Aumentar contagem da palavra no arquivo
                                    arq.set_ocorrencias_palavra(arq.get_ocorrencias_palavra() + 1)
                                    indice_invertido.insert(palavra, indice_busca)

                                
                            if not existe_na_tabela:
                                # Atualiza indice para contar mais uma palavra distinta no arquivo
                                registro_indice = indice.search(arquivo) # O indice guarda mais do que deveria
                                # print(f" o indice tem tamanho {indice.occupied}")
                                if registro_indice is not None:
                                    indice.insert(arquivo, registro_indice + 1)
                                else:
                                    indice.insert(arquivo, 1)

                                # Registra primeira ocorrencia da palavra no documento
                                indice_busca.append(Arquivo(arquivo, 1))
                                indice_invertido.insert(palavra, indice_busca)
                        
                        # Se nao existe registro da palavra no arquivo em questao
                        else:
                            # Atualiza indice para contar mais uma palavra distinta no arquivo
                            registro_indice = indice.search(arquivo)
                        
                            if registro_indice is not None:
                                indice.insert(arquivo, registro_indice + 1)
                            else:
                                indice.insert(arquivo, 1)
                            # Registra a primeira ocorrencia da palavra na colecao
                            novo_registro = Arquivo(arquivo, 1)
                            indice_invertido.insert(palavra, [novo_registro])
                        
                        palavra = ""
                        
    # Implementa as buscas
    while True:
        print("Por favor, selecione um metodo de busca (1-3):")
        print("1. Busca por uma palavra")
        print("2. Busca por pelo menos uma das palavras (duas ou mais)")
        print("3. Busca por todas as palavras")
        print("4. SAIR")

        tipo_busca = int(input("Escolha: "))
        print()

        if tipo_busca == 1:
            busca = input("Palavra de busca: ")
            busca = [busca.lower()]

            flag = False
            for pal in busca:
                if len(pal) < 4:
                    flag = True
                    busca.remove(pal)

            if flag:
                print(f"{bcolors.WARNING}Sua busca contem menos de 4 letras. Tente novamente.{bcolors.ENDC}")
                continue

            resultado = indice_invertido.search(busca[0])

            if resultado is not None:
                relevancias = []

                # Calcular a relevancia de cada documento
                for res in resultado:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)

                # Ordenar
                sort(resultado, relevancias)

                print(f"{bcolors.HEADER}Resultado da busca:")

                for i in range(1, len(resultado) + 1):
                    print(f"{bcolors.OKGREEN}{i}. {resultado[i - 1].get_nome()[-9:]}")
                
                print(bcolors.ENDC)

            else:
                print(f"{bcolors.FAIL}Nao foram encontrados resultados para a busca especificada{bcolors.ENDC}")
                continue
        
        elif tipo_busca == 2:
            busca = input("Palavras separadas por espaco: ")
            busca = busca.split()
            flag = False
            for pal in busca:
                if len(pal) < 4:
                    flag = True
                    busca.remove(pal)

            if flag:
                print(f"\n{bcolors.WARNING}Sua busca possui termos com menos de 4 letras, eles serao ignorados{bcolors.ENDC}\n")
    

            resultados = []
            for item in busca:
                resultado = indice_invertido.search(item)

                if resultado is not None:
                    resultados.append(resultado)
            set_union = []
            if len(resultados) > 0:
                sets = [set(res) for res in resultados]
                set_union = set.union(*sets)
                set_union = list(set_union)
        
            if len(set_union) > 0:
                relevancias = []

                for res in set_union:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)

                sort(set_union, relevancias)

                print(f"{bcolors.HEADER}Resultado da busca:")

                for i in range(1, len(set_union) + 1):
                    print(f"{bcolors.OKGREEN}{i}. {set_union[i - 1].get_nome()[-9:]}")
                
                print(bcolors.ENDC)
            else:
                print(f"{bcolors.FAIL}Nao foram encontrados resultados para a busca especificada{bcolors.ENDC}")
        
        elif tipo_busca == 3:
            busca = input("Palavras separadas por espaco: ")
            busca = busca.split()

            flag = False
            for pal in busca:
                if len(pal) < 4:
                    flag = True
                    busca.remove(pal)

            if flag:
                print(f"{bcolors.WARNING}Sua busca possui termos com menos de 4 letras, eles serao ignorados{bcolors.ENDC}")

            resultados = []
            is_possible = True

            for item in busca:
                resultado = indice_invertido.search(item)

                if resultado is None:
                    # Nao ha resultado para a intersecao
                    is_possible = False
                    break

                resultados.append(resultado)

            
            set_intersection = []
            if is_possible:
                # Calcular a intersecao dos conjuntos
                sets = [set(res) for res in resultados]
    
                # Find the intersection of all sets
                set_intersection = set.intersection(*sets)

                set_intersection = list(set_intersection)

            if len(set_intersection) > 0:
                relevancias = []
                
                for res in set_intersection:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)
                
                sort(set_intersection, relevancias)

                print(f"{bcolors.HEADER}Resultado da busca:")

                for i in range(1, len(set_intersection) + 1):
                    print(f"{bcolors.OKGREEN}{i}. {set_intersection[i - 1].get_nome()[-9:]}")
                
                print(bcolors.ENDC)


            else:
                print(f"{bcolors.FAIL}Nao foram encontrados resultados para a busca especificada{bcolors.ENDC}")

        elif tipo_busca == 4:
            exit()

def get_relevance(arquivo: Arquivo, indice: HashTable, indice_invertido: HashTable, termos: list):
    """
    Calcula a relevancia de uma pagina, para fins de ordenacao
    """
    # Calculo do peso de cada termo da busca pij
    ri = 0

    for termo in termos:
        # Buscar pela existencia do termo no arquivo
        resultado = indice_invertido.search(termo)
        if resultado is not None:
            dj = len(resultado)

            fij = 0
            for res in resultado:
                if res.get_nome() == arquivo.get_nome():
                    fij = res.get_ocorrencias_palavra()
                    break
            
            ri += fij * (math.log10(67) / dj)

    # Buscar palavras distintas
    qi = indice.search(arquivo.get_nome())

    return 0 if qi is None else ri / qi


def sort(arquivos, relevancias):
    # Bubblesort, pois no maximo teremos 67 arquivos para ordenar
    for i in range(len(relevancias) - 1):
        sorted = True
        for j in range(len(relevancias) - i - 1):
            if relevancias[j] < relevancias[j + 1]:
                relevancias[j], relevancias[j + 1] = relevancias[j + 1], relevancias[j]
                arquivos[j], arquivos[j + 1] = arquivos[j + 1], arquivos[j]
                sorted = False
        
        if sorted:
            break


if __name__ == "__main__":
    main()