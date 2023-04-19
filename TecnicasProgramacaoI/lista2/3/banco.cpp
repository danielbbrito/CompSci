#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
protected:
    string numeroConta;
    float saldo;

public:
    ContaBancaria(string numeroConta, float saldo) {
        this->numeroConta = numeroConta;
        this->saldo = saldo;
    }

    virtual void sacar(float am) {
        saldo -= am;
    }

    virtual void depositar(float am) {
        saldo += am;
    }
};

class ContaCorrente: public ContaBancaria {
private:
    float limite;
    int taxa;
public:
    ContaCorrente(string numeroConta, float saldo, float limite, int taxa)
        : ContaBancaria(numeroConta, saldo) {
            this->limite = limite;
            this->taxa = taxa;
        }
    
    void sacar(float am) {
        if (am > limite)
            cout << "Limite excedido, não é possível sacar " << am << endl;
        else
        {
            saldo -= am;
            limite -= am;
        }
    }

    void depositar(float am) {
        saldo += am - am * (taxa / 100);
    }
};

class ContaPoupanca : public ContaBancaria
{
private:
    int taxaAnual;
    int saquesPermitidos;

public:
    ContaPoupanca(string numeroConta, float saldo, int saquesPermitidos, int taxaAnual)
        : ContaBancaria(numeroConta, saldo) {
        this->saquesPermitidos = saquesPermitidos;
        this->taxaAnual = taxaAnual;
    }

    void sacar(float am) {
        if (saquesPermitidos == 0)
            cout << "Número máximo de saques atingido. Não é possível sacar.\n";
        
        else
        {
            saldo -= am;
            saquesPermitidos--;
        }
    }

    void depositar(float am) {
        saldo += am;
    }
};