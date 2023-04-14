#include <iostream>
#include <string>
#include <vector>
#include "tarefa.cpp"

using namespace std;

int main()
{
    vector<Tarefa> tarefas;
    int n;

    cout << "Insira o número de tarefas: ";
    cin >> n;

    while (n--)
    {
        Tarefa t;
        string aux;
        
        cout << "Insirao Título: ";
        cin >> aux;
        t.setTitulo(aux);

        cout << "Insira data de finalização: ";
        cin >> aux;
        t.setData(aux);

        cout << "Insira uma descrição: ";
        cin >> aux;
        t.setDesc(aux);

        t.setStatus(false);
    }

    for (auto it: tarefas)
    {
        it.getInfo();
        cout << endl;
    }

    return 0;
}