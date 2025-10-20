#include <stdio.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
using namespace std;

pair<vector<vector<double>>, vector<vector<double>>> lu_decomp(vector<vector<double>> A)
{
    int A_rows = A.size();

    // Incializamos as matrizes L e U e criamos uma copia de A
    vector<vector<double>> L(A_rows, vector<double>(A_rows, 0));
    //vector<vector<double> U(A_rows, vector<double>(n, 0));

    for (int i = 0; i < A_rows; i++)
    {
        L[i][i] = 1;
    }

    for (int i = 0; i < A_rows - 1; i++)
    {
        double r = 1 / A[i][i];

        for (int j = i + 1; j < A_rows; j++)
        {
            double multiplier = A[j][i] * r;
            L[j][i] = multiplier;
            A[j][i] = 0;
            for (int k = i + 1; k < A_rows; k++)
                A[j][k] -= multiplier * A[i][k];   
        }
    }

    return {L, A};
}

pair<pair<vector<vector<double>>, vector<vector<double>>>, vector<int>> lu_decomp_pivoting(vector<vector<double>> A)
{
    int m = A.size();
    vector<vector<double>> L(m, vector<double>(m, 0));
    vector<int> pivots;
    for (int i = 0; i < m; i++)
        pivots.push_back(i);

    for (int i = 0; i < m; i++)
        L[i][i] = 1;

    for (int i = 0; i < m - 1; i++)
    {
        // Antes da eliminação Gaussiana vamos verificar a troca de linhas
        int p = i;
        double Amax = abs(A[i][i]);

        for (int j = i + 1; j < m; j++)
        {
            if (abs(A[j][i]) > Amax)
            {
                Amax = abs(A[j][i]);
                p = j;
            }

        }

        if (p != i)
        {
            // Realizamos a troca de linhas
            swap(A[i], A[p]);
            swap(pivots[i], pivots[p]);
        }
        
        if (A[i][i] != 0)
        {
            double r = 1 / A[i][i];
            for (int j = i + 1; j < m; j++)
            {
                double multiplier = A[j][i] * r;
                L[j][i] = multiplier;
                A[j][i] = 0;

                for (int k = i + 1; k < m; k++)
                    A[j][k] -= multiplier * A[i][k]; 
            }
        }
    }

    return {{L, A}, pivots};
}

vector<double> solve(vector<vector<double>> L, vector<vector<double>> U, vector<double> b, vector<int> p)
{
    vector<double> x(U.size(), 0);
    vector<double> c(b.size(), 0);
    // Trocar linhas em b se necessário
    c[0] = b[p[0]];

    for (int i = 1; i < L.size(); i++)
    {
        double soma = 0.0;

        for (int j = 0; j < i; j++)
            soma += L[i][j] * c[j];

        c[i] = b[p[i]] - soma;
    }

    int m = U.size();

    x[m - 1] = c[m - 1] / U[m - 1][m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        double soma = 0;

        for (int j = i + 1; j < m; j ++)
            soma += U[i][j] * x[j];
        
        if (U[i][i] < 1e-12)
            return vector<double>{};

        x[i] = (c[i] - soma) / U[i][i];
    }

    return x;
}

int main()
{
    // --- Sistema 1: sem pivotamento necessário ---
    vector<vector<double>> A1 = {
        {4, 2, 0},
        {2, 4, 2},
        {0, 2, 4}
    };
    vector<double> b1 = {2, 4, 6};
    auto dec1 = lu_decomp(A1);
    vector<int> p1 = {0,1,2};

    vector<double> x1 = solve(dec1.first, dec1.second, b1, p1);
    if (x1.empty()) {
        printf("Erro: sistema 1 singular ou quase singular\n");
    } else {
        printf("Solução do sistema 1 (sem pivotamento):\n");
        for (double xi : x1) printf("%f ", xi);
        printf("\n\n");
    }

    // --- Sistema 2: pivotamento parcial necessário ---
   vector<vector<double>> A2 = {
    {0, 2, 1}, 
    {3, 5, 2},
    {1, 1, 3}
};
vector<double> b2 = {3, 10, 6};
    auto dec2 = lu_decomp_pivoting(A2);

    vector<double> x2 = solve(dec2.first.first, dec2.first.second, b2, dec2.second);
    if (x2.empty()) {
        printf("Erro: sistema 2 singular ou quase singular\n");
    } else {
        printf("Solução do sistema 2 (com pivotamento parcial):\n");
        for (double xi : x2) printf("%f ", xi);
        printf("\n");
    }

    return 0;
}