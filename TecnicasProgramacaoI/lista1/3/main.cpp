#include <iostream>

#include "matriz.cpp"
using namespace std;

int main()
{
    Matriz matriz = Matriz(5, 10);

    int **m;
    m = new int*[5];

    for (int i = 0; i < 5; i++)
    {
        m[i] = new int[10];
        for (int j = 0; j < 10; j++)
            cin >> m[i][j];
    }

    
    matriz.multiplicaMatriz(m, 5, 10);
}