#include <iostream>

using namespace std;

class Veiculo {

protected:
    string marca;
    string modelo;
    int ano;
    int combustivel;
    float eficiencia;

public:
    Veiculo(string marca, string modelo, int ano, int combustivel, int eficiencia);

    virtual void exibirDados() = 0;

    float quilometragem()
    {
        return eficiencia * combustivel;
    }
};

class Moto:public Veiculo {
private:
    int cilindradas;
    int 
}