#include <iostream>
#include "animal.cpp"
using namespace std;

int main()
{
    Animal gato = Animal("Sandro", 2, "gato"); // Instancia um objeto usando o metodo construtor

    Animal outroGato = Animal("Tom", 3, "gato");

    Animal bichos[2] = {gato, outroGato};

    for (int i = 0; i < 2; i++)
    {
        bichos[i].imprimeDados();
    }

    return 0;
}