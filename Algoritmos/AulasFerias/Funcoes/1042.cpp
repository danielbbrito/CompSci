#include <bits/stdc++.h>

using namespace std;

#define TAM 3

void SortSimples(int *v)
{
    bool flag = false;

    while (!flag)
    {
        flag = true;

        for (int i = 1; i < TAM; i++)
        {
            if (v[i] < v[i - 1])
            {
                flag = false;
                int aux = v[i];
                v[i] = v[i - 1];
                v[i - 1] = aux;
            }
        }
    }

    return;
}

int main()
{
    int vect[TAM];
    int og[TAM];

    for (int i = 0; i < TAM; i++)
    {
        cin >> vect[i];
        og[i] = vect[i];
    }

    SortSimples(vect);

    for (int i = 0; i < TAM; i++)
        cout << vect[i] << endl;
    
    cout << '\n';

    for (int i = 0; i < TAM; i++)
        cout << og[i] << endl;

    return 0;
}