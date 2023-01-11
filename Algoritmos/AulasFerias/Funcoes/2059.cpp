#include <bits/stdc++.h>

using namespace std;

int ParImpar(int p, int j1, int j2, int r, int a)
{
    // Verificar acusação de roubo
    if (r == 1)
    {
        if (a == 1)
            return 2;
        
        return 1;
    }

    if (a == 1)
        return 1;

    // Verificar partida normal
    j1 += j2;

    if (p == 1)
    {
        if (j1 % 2 == 0)
            return 1;
        
        return 2;
    }

    if (j1 % 2 == 0)
        return 2;

    return 1;
}

int main()
{
    int P, J1, J2, R, A;

    cin >> P >> J1 >> J2 >> R >> A;

    cout << "Jogador " << ParImpar(P, J1, J2, R, A) << " ganha!\n";

    return 0;
}