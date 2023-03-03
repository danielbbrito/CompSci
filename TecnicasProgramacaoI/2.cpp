#include <iostream>

using namespace std;

class Carro
{
    private:
        char *marca;
        char *modelo;
        int ano;

    public:
        void setMarca(char *m)
        {
            marca = m;
        }

        void setModelo(char *n)
        {
            modelo = n;
        }

        void setAno(int a)
        {
            ano = a;
        }

        void getInfo()
        {
            cout << "Marca: " << marca
                 << "Modelo: " << modelo
                 << "Ano: " << ano << endl;
        }
};

int main()
{

}