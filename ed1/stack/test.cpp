#include <iostream>
#include "stackvet.h"

using namespace std;

int main()
{
    // Test wether class instantiation is possbile in different types
    StackVet<int> teste(10);
    StackVet<string> t2(10);
    StackVet<double> t3(15);
    cout << "Objetos criados!" << endl;

    // Test wether pushing an element is possible
    if (teste.push(5))
        cout << "Insere um elemento com sucesso!" << endl;
    else
    {
        cout << "<--Erro ao inserir elemento-->" << endl;
        return 0;
    }

    // Test wether popping an element is possible
    if (teste.pop())
        cout << "Remove um elemento com sucesso!" << endl;
    else
    {
        cout << "<--Erro ao remover elemento-->" << endl;
        return 0;
    }

    // Test wether empty stack cannot pop element
    if (!teste.pop())
        cout << "Lida com stack vazia" << endl;
    else
    {
        cout << "<--Permite remover elemento inexistente-->" << endl;
        return 0;
    }

    // Fills stack
    cout << "Enchendo stack" << endl;
    int i = 0;
    while (teste.push(i))
    {
        cout << "   Inserindo elemento no index " << i << endl;
        i++;
    }

    // Tests wether stack will go out of bounds
    if (!teste.push(11))
        cout << "Lida bem com stack cheia" << endl;

    else
    {
        cout << "<--Permite passar do limite de elementos-->" << endl;
        return 0;
    }

    // Clear stack
    if (!teste.empty())
        cout << "Tentando limpar stack" << endl;
    teste.clear();

    if (teste.empty())
        cout << "Stack limpa" << endl;
    else
    {
        cout << "<--Falha ao limpar stack-->" << endl;
        return 0;
    }

    cout << endl << "TODOS TESTES REALIZADOS COM SUCESSO!" << endl;

    return 0;
}