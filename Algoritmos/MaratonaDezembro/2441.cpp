#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, soma1=0, soma2=0;

    cin >> n;

    int m[n][n];


    // Ler matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    cout << "chegou";
    // Somar triangulo b
    for (int l = 0; l < n; l++)
    {
        for (int c = l + 1; c < n; c++)
        {
            soma1 += m[l][c];
        }
    }

    // somar trinagulo a
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; i++)
        {
            soma2 += m[i][j];
        }
    }

    if (soma1 > soma2)
        cout << "O maior eh B\n";
    else if (soma2 > soma1)
        cout << "O maior eh A\n";
    else
        cout << "Eles sao iguais\n";

    return 0;
}