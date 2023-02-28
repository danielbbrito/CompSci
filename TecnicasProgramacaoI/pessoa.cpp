#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
    public:
        // Atributos
        string nome;
        int idade;

        // Metodos
        void imprimir()
        {
            cout << nome << " tem " << idade << " anos de idade.\n";
    }
};