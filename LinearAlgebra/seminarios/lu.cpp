#include <stdio.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <algorithm>
using namespace std;

pair<vector<vector<double>>, vector<vector<double>>> lu_decomp(vector<vector<double>> A)
{
    int m = A.size();

    vector<vector<double>> L(m, vector<double>(m, 0));
    //vector<vector<double> U(m, vector<double>(n, 0));

    for (int i = 0; i < m; i++)
    {
        L[i][i] = 1;
    }

    for (int i = 0; i < m - 1; i++)
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
        
        if (A[i][i] > 1e-14)
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

    if (abs(U[m - 1][m - 1]) < 1e-12)
    {

        if (abs(c[m - 1]) < 1e-12)
        {
            printf("Atencao, existem infinitas solucoes\n");
            x[m - 1] = 0;
        }
        else
            return vector<double>{};
    }

    else
        x[m - 1] = c[m - 1] / U[m - 1][m - 1];

    for (int i = m - 2; i >= 0; i--)
    {
        double soma = 0;

        for (int j = i + 1; j < m; j ++)
            soma += U[i][j] * x[j];
        
        if (abs(U[i][i]) < 1e-12)
            return vector<double>{};

        x[i] = (c[i] - soma) / U[i][i];
    }

    return x;
}

int main()
{
    

//     // --- Sistema 2: pivotamento parcial necessário ---
//    vector<vector<double>> A2 = {
//     {0, 1, -1}, 
//     {1, -1, 0},
//     {1, 0, -1}
// };
// vector<double> b2 = {0, 0, 0};
//     auto dec2 = lu_decomp_pivoting(A2);

//     vector<double> x2 = solve(dec2.first.first, dec2.first.second, b2, dec2.second);
//     if (x2.empty()) {
//         printf("Erro: sistema 2 singular\n");
//     } else {
//         printf("Solução do sistema 2 (com pivotamento parcial):\n");
//         for (double xi : x2) printf("%f ", xi);
//         printf("\n");
//     }

    vector<vector<double>>  A = {
        {0.001, 0.0},
        {1.0, 1000}
    };

    pair<vector<vector<double>>, vector<vector<double>>> p = lu_decomp(A);

    vector<vector<double>> ans1 = p.second;
    printf("Eliminação direta:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.8f ", ans1[i][j]);
        }
        printf("\n");
    }
    pair<pair<vector<vector<double>>, vector<vector<double>>>, vector<int>> p2 = lu_decomp_pivoting(A);
    vector<vector<double>> ans2 = p2.first.second;
    printf("\n");
    printf("Eliminação com pivotamento parcial:\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.8f ", ans2[i][j]);
        }
        printf("\n");
    }
    return 0;
}