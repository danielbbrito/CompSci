#include <bits/stdc++.h>

using namespace std;
int r,c;
char grid[25][25], seen[25][25];
int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}


void FloodFill(int i, int j, int s, int e, int p)
{
    seen[i][j] = true;
    if (grid[i][j] == '#')
        grid[i][j] = '.';

    for (int k = 0; k < 4; k++)
    {
        int ni = i + Y[k], nj = j + X[k];

        if (isSafe(ni, nj) && abs(ni - s) + abs(nj - e) <= p - 48 && !seen[ni][nj])
            FloodFill(ni, nj, s, e, p);
        
    }
}
int main()
{
    cin >> r >> c;
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            //printf("%d %d\n", i,j);
            cin >> grid[i][j];
            seen[i][j] = false;
        }
        
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] != '#' && grid[i][j] != '.')
            {
                FloodFill(i, j, i, j, grid[i][j]);
                grid[i][j] = '.';
            }
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << grid[i][j];
        cout << endl;
    }
}