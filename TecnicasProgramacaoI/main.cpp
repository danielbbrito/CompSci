#include <iostream>
#include <string>
#include "pessoa.cpp"
using namespace std;

int main()
{
    Pessoa p1, p2;
    cin >> p1.nome >> p1.idade;
    cin >> p2.nome >> p2.idade;
    p1.imprimir();
    p2.imprimir();
}


