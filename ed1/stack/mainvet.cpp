#include <iostream>
#include "stackvet.h"
using namespace std;

int main()
{
    int flag = true;

    cout << "Querido usuário, bem vindo ao programa de pilha!\n"
         <<  "Os comandos disponíveis são os seguintes:\n"
         <<  "1. Insere elemento\n"
         <<  "2. Remove elemento\n"
         <<  "3. Retorna elemento no topo\n"
         <<  "4. Verifica se pilha está vazia\n"
         <<  "5. Finaliza o programa\n";

    StackVet<int> st(15);

    do
    {
        cout << "\nEscolha um opção (1-5): ";
        int option;
        cin >> option;

        switch (option)
        {
            case 1:
                {
                cout << "Digite o elemento a ser inserido: ";
                int el;
                cin >> el;
                if (st.push(el))
                    cout << "Elemento inserido!\n\n";
                
                else
                    cout << "Elemento não inserido (stack cheia)\n\n";
                break;
                }

            case 2:
                if (st.pop())
                    cout << "Elemento mais recente removido!\n\n";
                
                else 
                    cout << "Não foi possível remover um elemento (pilha vazia)\n\n";
                break;

            case 3:
                cout << "Topo: " << st.top() << '\n';
                break;

            case 4:
                cout << st.empty() ? "A pilha está vazia!\n" : "A pilha não está vazia!";
                break;

            case 5:
                flag = false;
                cout << "Saindo!\n";
                break;

            default:
                cout << "Opção inválida\n";
                break;
        }
    }
    while (flag);

    return 0;
}