#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;


double norma(vector<double> x1, vector<double> x2)
{
    double norm = 0;
    vector<double> x;
    for (int i = 0; i < x1.size(); i++)
    {
        x.push_back(x1[i] - x2[i]);
    }

    for (int i = 0; i < x.size(); i++)
    {
        norm += pow(x[i], 2); 
    }


    return sqrt(norm);
}

pair<vector<double>, int> jacobi(vector<vector<double>>& A, int n, vector<double>& b, vector<double>& x0, double eps, int itermax)
{
    int iter = 0;

    vector<double> x = x0;

    for (int i = 0; i < n; i++)
    {
        double  r = 1 / A[i][i];

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                A[i][j] *= r;
            }
        }

        b[i]*= r; 
    }

    vector<double> v = x;

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            double soma = 0;

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    soma = soma + A[i][j] * x[j];
                }
            }
            v[i] = b[i] - soma;

        }

        if (norma(v, x) <= eps)
        {
            break;
        }

        x = v;
        iter++;

    }

    return {x, iter};

    return {x, iter};
}

int main()
{
    vector<vector<double>> A = {
        {10, 3, -2},
        {2, 8, -1},
        {1, 1, 5}
    };

    vector<double> b = {57, 20, -4};

    vector<double> x0 = {0,0,0};

    pair<vector<double>, int> ans = jacobi(A, A.size(), b, x0, 1e-5, 1000);

    vector<double> a = ans.first;

    for (auto it: a)
    {
        cout << it << ", ";
    }
    cout << endl;
    cout << ans.second << endl;
}