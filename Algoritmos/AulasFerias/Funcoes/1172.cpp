#include <bits/stdc++.h>

using namespace std;

#define TAM 10

void Sub(int *v)
{
    for (int i = 0; i < TAM; i++)
        if (v[i] <= 0)
            v[i] = 1;
    
    return;
}

int main()
{
    int X[TAM];

    for (int i = 0; i < TAM; i++)
        cin >> X[i];

    Sub(X);

    for (int i = 0; i < TAM; i++)
        cout << "X[" << i << "] = " << X[i] << endl;

    return 0;
}