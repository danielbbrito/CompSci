#include <iostream>
#include "queuevet.h"
using namespace std;

int main()
{

    QueueVet<int> q(15);

    cout << "Querido usuario, bem vindo ao programa da fila!\n"
         << "Sua fila de inteiros foi criada, escolha uma opcao:\n"
         << "   1. Inserir elemento na fila\n"
         << "   2. Remover elemento da fila\n"
         << "   3. Verificar se fila esta vazia\n"
         << "   4. Verificar se fila esta cheia\n"
         << "   5. Limpar fila\n"
         << "   6. Sair do programa\n\n";

    bool flag = true;
    
    do
    {
        int option;
        cout << "Opcao: ";
        cin >> option;
        switch (option)
        {
            case 1:
                int elemento;
                cout << "\nDigite seu elemento: ";
                cin >> elemento;
                try
                {
                    q.push(elemento);
                    cout << "Elemento inserido\n\n"
                }
                catch(-1)
                {
                    cout << "Fila cheia\n\n";
                }
                
            default:
                cout << "Opcao invalida\n\n"
                break;
        }
    }
    while (flag);
}