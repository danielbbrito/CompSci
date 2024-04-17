import math
from hash_table import HashTable
from arquivo import Arquivo

def main():
    # Ler arquivos e indexar cada palavra no indice invertido
    directory_path = "ed2/search_engine/arquivos-colecao-index/arq"
    indice_invertido = HashTable()
    indice = HashTable()
    for i in range(1, 68):
        arquivo = None
        if i < 10:
            arquivo = "0" + str(i)
        else:
            arquivo = str(i)

        arquivo = directory_path + arquivo + ".txt"
        print(f"Lendo arquivo {arquivo}. Restam {67 - i} arquivos.")
        with open(arquivo, mode="r") as FILE:
            indice.insert(arquivo, 0)

            for line in FILE:
                palavra = ""
                # This is probs wrong
                for c in line:
                    if c.isalpha():
                        palavra += c.lower()

                    else:
                        if len(palavra) < 4:
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
                                    registro_indice = indice.search(arquivo)
                                    indice.insert(arquivo, registro_indice + 1)

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

        tipo_busca = int(input("Escolha: "))
        print()

        if tipo_busca == 1:
            busca = input("Palavra de busca: ")
            busca = [busca.lower()]

            resultado = indice_invertido.search(busca[0])

            if resultado is not None:
                relevancias = []

                # Calcular a relevancia de cada documento
                for res in resultado:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)

                # Ordenar
                sort(resultado, relevancias)

                print("Resultado da busca:")

                for i in range(1, len(resultado) + 1):
                    print(f"{i}. {resultado[i].nome()}")
                
                print()

            else:
                print("Nao foram encontrados resultados para a busca especificada")
                continue
        
        elif tipo_busca == 2:
            busca = input("Palavras separadas por espaco: ")
            busca = busca.split()

            set_union = []
            for item in busca:
                resultado = indice_invertido.search(item)

                if resultado is not None:
                    for res in resultado:
                        if res not in set_union:
                            set_union.append(res) # Inclui todos os items que possuam pelo menos uma das palavras da busca

            if len(set_union) > 0:
                relevancias = []
                for res in set_union:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)
                
                sort(set_union, relevancias)

                print("Resultado da busca:")

                for i in range(1, len(set_union) + 1):
                    print(f"{i}. {set_union[i].nome()}")
                
                print()
            else:
                print("Nao foram encontrados resultados para a busca especificada")
        
        elif tipo_busca == 3:
            busca = input("Palavras separadas por espaco: ")
            busca = busca.split()

            resultados = []
            is_possible = True

            for item in busca:
                resultado = indice_invertido.search(item)

                if resultado is None:
                    # Nao ha resultado para a intersecao
                    is_possible = False
                    break

                resultados.append(resultado)

            set_intersection = set()
            if is_possible:
                # Calcular a intersecao dos conjuntos
                set_intersection = set(resultados[0])

                for i in range(1, len(resultados)):
                    set_intersection = set_intersection.intersection(resultados[i])

                set_intersection = list(set_intersection)

            if len(set_intersection) > 0:
                relevancias = []
                
                for res in set_intersection:
                    relevancia = get_relevance(res, indice, indice_invertido, busca)
                    relevancias.append(relevancia)
                
                sort(set_intersection, relevancias)

                print("Resultado da busca:")

                for i in range(1, len(set_intersection) + 1):
                    print(f"{i}. {set_intersection[i].nome()}")
                
                print()


            else:
                print("Nao foram encontrados resultados para a busca especificada")

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
                if res.nome() == arquivo.nome():
                    fij = res.ocorrencias_palavra()
                    break
            
            ri += fij * (math.log10(67) / dj)

    # Buscar palavras distintas
    qi = indice.search(arquivo.nome())

    return ri / qi


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