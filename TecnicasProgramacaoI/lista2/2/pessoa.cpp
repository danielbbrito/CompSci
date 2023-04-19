#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

struct Endereco {
string rua;
int numero;
int apto=NULL;
};

struct Telefone {
int ddd;
int numero;
};

class Pessoa {
protected:
    Endereco endereco;
    string nome;
    Telefone telefone;

public:
    Pessoa(Endereco endereco, string nome, Telefone telefone)
    {
        this->endereco = endereco;
        this->nome = nome;
        this->telefone = telefone;
    }

    virtual void exibirDados()=0;
};

class Aluno: public Pessoa {
private:
    string matricula;
    map<string, string> materiasAluno;

public:
    Aluno(Endereco endereco, string nome, Telefone telefone, string matricula, map<string, string> materiasAluno)
        : Pessoa(endereco, nome, telefone)
        {
            this->matricula = matricula;
            this->materiasAluno = materiasAluno;
        }

    void exibirDados() {
        cout << "Aluno: " << nome
             << "\nMatrícula: " << matricula
             << "\nEndereço: " << endereco.rua << ", " << endereco.numero;

        if (endereco.apto != NULL)
            cout << ", " << endereco.apto;

        cout << "\nTelefone: " << '(' << telefone.ddd << ')' << ' ' << telefone.numero
             << "\nMatérias matriculadas: \n";
        
        for (auto it: materiasAluno)
        cout << '-' << it.first << ": " << it.second << endl;
    }
};