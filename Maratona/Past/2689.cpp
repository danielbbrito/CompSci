#include <bits/stdc++.h>

using namespace std;

void calcularSub(int grid[][3], int subs[][3])
{
    for (int i = 0; i < 3; i++)
    {
        subs[i][0] = abs(grid[i][0] - grid[i][1]);
        for (int j = 1; j < 3; j++)
        {
            subs[i][j] = abs(grid[i][j] - grid[i][j - 1]);
        }
    }

}

void selectionSort(int v[])
{
    for (int i = 0; i < sizeof(v) / sizeof(v[0]) - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; i < sizeof(v) / sizeof(v[0]); i++)
        {
            if (v[j] < v[menor])
                menor = j;
        }

        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

int comum(int v[])
{
    int max = 0;
    for (int i = 0; i < sizeof(v) / sizeof(v[0]); i++)
    {
        int curr = i;
        int count = 0;
        int maior = 0;
        while (v[curr] == v[i])
        {
            count++;
            curr++;
        }
        
        if (count > maior)
        {
            maior = count;
            max = v[i];
        }
    }

    return max;
}

int main()
{
    int grid[3][3], subs[3][3], possiveis[3][3], common[9];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid[i][j];

    calcularSub(grid, subs);

    for (int i = 0; i < 3; i++)
    {
        int ct = 0;
        for (int j = 0; i < 3; i++)
        {
            common[ct] = possiveis[i][j];
            ct++;
        }
    }

    selectionSort(common);

    int c = comum(common);

    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        int diff;
        if (j == 0)
        {
            possiveis[i][j] = possiveis[i][j] - (possiveis)
        }
    }
}