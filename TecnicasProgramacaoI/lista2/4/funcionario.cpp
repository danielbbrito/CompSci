#include <iostream>
#include <string>

using namespace std;

class Funcionario {
protected:
    string nome;
    string matricula;
    float salario;

public:
    Funcionario(string nome, string matricula, float salario) {
        this->nome = nome;
        this->matricula = matricula;
        this->salario = salario;
    }

    virtual void calcularSalario()=0;
};

class Gerente: public Funcionario {
private:
    string turno;
    string secao;
    
public:
    Gerente(string nome, string matricula, float salario, string turno, string secao) 
        : Funcionario(nome, matricula, salario) {
        this->turno = turno;
        this->secao = secao;
    }

    void calcularSalario() {
        salario = salario;
    }
};

class Vendedor: public Funcionario {
private:
    string secao;
    int vendas;

public:
    Vendedor(string nome, string matricula, float salario, string secao, int vendas)
        : Funcionario(nome, matricula, salario) {
            this->secao = secao;
            this->vendas = vendas;
        }
    void calcularSalario() {
        salario *= vendas * 1.05; 
    }
};

class Tecnico: public Funcionario {
private:
    int bonus;

public:
    Tecnico(string nome, string matricula, float salario, int bonus)
        : Funcionario(nome, matricula, salario) {
            this->bonus = bonus;
        }

    void calcularSalario() {
         salario *= 1 + (bonus / 100.0);
    }
};