#include <iostream>

using namespace std;

class Matriz
{
    private:
        int row, col;
        int **matriz;

    public:
        Matriz()
        {
            row = 0;
            col = 0;
            matriz = nullptr;
        }

        Matriz(int row, int col, int **matriz=nullptr)
        {
            this->row = row;
            this->col = col;
            
            if (matriz == nullptr)
            {
                matriz = new int*[row];

                for (int i = 0; i < row; i++)
                {
                    matriz[i] = new int[col];

                    for (int j = 0; j < col; j++)
                        cin >> matriz[i][j];
                }
            }
            
            else
                this->matriz = matriz;
        }

        // Método para somar matrizes, as matrizes devem ser de mesma ordem
        void somaMatriz(int **m)
        {   
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << matriz[i][j] + m[i][j] << ' ';
                }

                cout << endl;
            }
        }

        void subMatriz(int **m)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << matriz[i][j] - m[i][j] << ' ';
                }

                cout << endl;
            }
        }

        void transporMatriz()
        {
            int mat[col][row];

            for (int i = 0; i < col; i++)
            {
                for (int j = 0; j < row; j++)
                    cout << matriz[i][j] << ' ';

                cout << endl;
            }
        }

        void multiplicaMatriz(int **m, int r, int c)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    int sum = 0;

                    for (int k = 0; k < col; k++)
                    {
                        sum += matriz[i][k] * m[k][i]; 
                    }

                    cout << sum << ' ';
                }

                cout << endl;
            }
        }
};