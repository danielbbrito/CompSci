#include <bits/stdc++.h>

using namespace std;

int SomaImpar(int x, int y)
{
    int soma = 0;
    if (x < y)
    {
        if (x % 2 == 0)
            x++;
        
        else
            x += 2;

        while (x < y)
        {
            soma += x;
            x += 2;
        }

        return soma;
    }

    if (y % 2 == 0)
        y++;
    
    else
        y += 2;

    while (y < x)
    {
        soma += y;
        y += 2;
    }

    return soma;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int X, Y;
        cin >> X >> Y;

        cout << SomaImpar(X, Y) << endl;
    }

    return 0;
}