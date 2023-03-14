#include <iostream>
#include <string>

using namespace std;

class Tarefa:
{
    private:
        string titulo;
        string descricao;
        string data;
        string status;
    
    public:
      Tarefa(string titulo, string descricao, string data, string status)
      {
        this -> titulo = titulo;
        this -> descricao = descricao;
        this -> data = data;
        this -> status = status;
      }

      Tarefa(){}

      // Metodos setter
      void setTitulo(string titulo)
      {
        this->titulo = titulo;
      }

      void setDescricao(string descricao)
      {
        this->descricao = descricao;
      }

      void setData(string data)
      {
        this->data = data;
      }

      void setStatus(string status)
      {
        this->status = status;
      }

      // Metodos getter
      void getTitulo()
      {
        cout << "Titulo: " << titulo;
      }

      void getDescricao()
      {
        cout << "Descricao: " << descricao;
      }

      void getData()
      {
        cout << "Data final: " << data;
      }

      void getStatus()
      {
        cout << "Status: " << status;
      }

      bool prazo(string dia)
      {
        
      }
        
};

