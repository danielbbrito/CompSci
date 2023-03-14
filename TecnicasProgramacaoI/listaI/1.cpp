#include <iostream>
#include <string>

using namespace std;

class Animal
{
    private:
        string nome;
        int idade;
        string especie;

    
    public:

        void setNome(string n)
        {
            nome = n;
        }

        void setIdade(int i)
        {
            idade = i;
        }

        void setEspecie(string e)
        {
            especie = e;
        }

        string getNome()
        {
            return "Nome" + nome;
        }

        int getIdade()
        {
            return "Idade" + idade;
        }

        string getEspecie()
        {
            return "Especie" + especie;
        }
};

int main()
{
    // Instanciar 3 objetos da classe animal
    Animal a1 = Animal();

    Animal a2 = Animal();

    Animal a3 = Animal();
}