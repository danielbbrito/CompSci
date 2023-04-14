#include <iostream>
using namespace std;

class Tarefa
{
    private:
        string titulo, descricao, data;
        bool status;

    public:
    // Construtor
    Tarefa()
    {

    }

    Tarefa(string titulo, string descricao, string data, bool status)
    {
        this->titulo = titulo;
        this->descricao = descricao;
        this->data = data;
        this->status = status;
    }

    // Setters

    void setTitulo(string t)
    {
        titulo = t;
    }

    void setDesc(string d)
    {
        descricao = d;
    }

    void setData(string dt)
    {
        data = dt;
    }

    void setStatus(bool s)
    {
        status = s;
    }

    void getInfo()
    {
        cout << "Tarefa: " << titulo <<"\n"
             << "Data limite: " << data << "\n"
             << "Finalizada? ";
        
        if (status)
            cout << "sim\n";
        else
            cout << "não\n";

        cout << "Descrição:\n" << descricao << "\n";
    }

    void atrasada(string d)
    {
        if (data[3] + data[4] <= d[3] + d[4] && data[6] + data[7] + data[8] + data[9] <= d[6] + d[7] + d[8] + d[9] + d[10])
        {
            if (data[0] + data[1] <= d[0] + d[1])
                cout << "Está em tempo!\n";

            else
                cout << "Está atrasada!\n";
            
            return;
        }

        else
            cout << "Está atrasada!\n";
        
        return;
    }
};