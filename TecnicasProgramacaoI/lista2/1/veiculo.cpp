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
    Veiculo(string marca, string modelo, int ano, int combustivel, int eficiencia) {
        this->marca = marca;
        this->modelo = modelo;
        this->ano = ano;
        this->combustivel = combustivel;
        this->eficiencia = eficiencia;
    }

    virtual void exibirDados() = 0;

    float quilometragem()
    {
        return eficiencia * combustivel;
    }
};

class Moto:public Veiculo {
private:
    int cilindradas;
    string partida;
    
public:
    Moto(string marca, string modelo, int ano, int combustivel, int eficiencia, int cilindradas, string partida)
        :Veiculo(marca, modelo, ano, combustivel, eficiencia) {
            this->cilindradas = cilindradas;
            this->partida = partida;
        }
        
    
    void exibirDados() {
        cout << "Tipo: moto\n"
             << "Marca: "  << marca
             << "\nModelo" << modelo
             << "\nQtd de combustível: " << combustivel << 'L'
             << "\nEficiência: " << eficiencia << "Km/L"
             << "\nCilindradas: " << cilindradas
             << "\nTipo de partida: " << partida << endl;
    }
};

class Carro:public Veiculo {
private:
    int portas;
    int capacidadePortaMalas;
    string tipoCombustivel;
    
public:
    Carro(string marca, string modelo, int ano, int combustivel, int eficiencia, int portas, int capacidadePortaMalas, int tipoCombustivel)
        :Veiculo(marca, modelo, ano, combustivel, eficiencia) {
            this->portas = portas;
            this->capacidadePortaMalas = capacidadePortaMalas;
            this->tipoCombustivel = tipoCombustivel;
        }
        
    void exibirDados() {
        cout << "Tipo: moto\n"
             << "Marca: "  << marca
             << "\nModelo" << modelo
             << "\nQtd de combustível: " << combustivel << 'L'
             << "\nEficiência: " << eficiencia << "Km/L"
             << "\nQtd de portas: " << portas
             << "\nCapacidade do porta malas" << capacidadePortaMalas
             << "\nTipo de combustível" << tipoCombustivel << endl;
    }
};

class Caminhao:public Caminhao {
 private:
    float capacidadeCarga;
    int numEixos;
    
public:
    Caminhao(string marca, string modelo, int ano, int combustivel, int eficiencia, int capacidadeCarga, numEixos)
        :Veiculo(marca, modelo, ano, combustivel, eficiencia)
        {
            this->capacidadeCarga;
            this->numEixos;
        }
        
    
    void exibirDados()
    {
        cout << "Tipo: moto\n"
             << "Marca: "  << marca
             << "\nModelo" << modelo
             << "\nQtd de combustível: " << combustivel << 'L'
             << "\nEficiência: " << eficiencia << "Km/L"
             << "\nCapacidade de carga: " << capacidadeCarga
             << "\nQtd de eixos: " << numEixos << endl;
    }
};
