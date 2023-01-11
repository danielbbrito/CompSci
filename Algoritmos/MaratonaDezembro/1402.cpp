#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, x=-1, y=-1, flag=0, m[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> m[i][j];
        }

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5 && flag == 0; j++)
        {
            if (m[i][j] == 7 && m[i-1][j] == 3 && m[i+1][j] == 3 && m[i][j-1] == 3 && m[i][j+1] == 3)
            {
                flag = 1;
                x = i;
                y = j;
            }
        }

    if (x != -1 && y != -1)
        cout << "Posicao X, Y do valor: " << x << " " << y << endl;
    
    else
        cout << "Numero nao encontrado." << endl;

    return 0;
}