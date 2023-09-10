#include <bits/stdc++.h>

using namespace std;
int n, f;

char grid[505][505];
int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return i >= 0 &&j>=0 &&i<n&&j<n;
}
void FloodFill(int i, int j)
{
    if (i + j > 0)
        grid[i][j] = '*';

    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];

        if (isValid(Ni, Nj) && grid[Ni][Nj] <= f && grid[Ni][Nj] != '*')
            FloodFill(Ni, Nj);
    }
}

int main()
{
    cin >> n >> f;
    f+= 48;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    if (grid[0][0] <= f)
    {
        grid[0][0] = '*';
    }
    FloodFill(0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        
        cout << endl;
    }
}