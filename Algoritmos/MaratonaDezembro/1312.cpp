#include <bits/stdc++.h>
using namespace std;

int main()
{
    int inicio, fim, n;
    long soma=0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> inicio >> fim;

        for (int j = inicio; j <= fim; j++)
        {
            if (j % 21 != 0)
            {
                soma += j;
            }
        }

        cout << soma << endl;
        soma = 0;
    }
}