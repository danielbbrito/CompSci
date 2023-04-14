#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Conta {
private:
    string nome;
    float saldo;
    string numero;
    vector<string> historico;

public:
    Conta(string nome, string titular, string numero)
    {
        this->nome=nome;
        this->titular=nome;
        this->numero=numero;
    }

    void setNome(string n)
    {
        nome = n;
    }

    void setSaldo(float s)
    {
        saldo = s;
    }

    void setNumero(string num)
    {
        numero = num;
    }

    void depositar(float am)
    {
        saldo += am;
    }

    void sacar(float am)
    {
        saldo -= am;
    }

    void transferir(Conta c, float am)
    {
        saldo -= am;

        c.depositar(am);
    }

};
