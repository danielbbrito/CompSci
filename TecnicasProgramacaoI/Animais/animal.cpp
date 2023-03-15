#include <iostream>
using namespace std;

class Animal
{
    // OPCIONAL: private: // DEFAULT PARA A CLASSE
    int idade;

    public:
        // Atributos
        string nome;
        string especie;
        // Metodo(s) construtor(es)
        Animal(string n, int i, string e)
        {
            nome = n;
            idade = i;
            especie = e;
        }

        // Metodos getter e setter
        void setIdade(int i)
        {
            if (i >= 0)
                idade = i;
            
            else
                idade = 0;
        }

        int getIdade()
        {
            return idade;
        }

        void imprimeDados()
        {
            cout << "Nome: " << nome << endl
                 << "Idade: " << idade << endl
                 << "Especie: " << especie << endl;
        }
};