#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i1, i2, soma=0, apostas;

    cin >> i1 >> i2;

    for (int i = 0; i < 4; i++)
    {
        cin >> apostas;
        soma += apostas;
    }

    if (soma < abs(i1 - i2))
        cout << "Carlota e Savoca estavam certos: Ganhou!\n";
    
    else
        cout << "Carlota e Savoca estavam certos: Perdeu!\n";
    
    return 0;
}