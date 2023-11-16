#include <bits/stdc++.h>

using namespace std;
int n,m;
char grid[1005][1005];

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};


bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void FloodFill(int i, int j)
{
    grid[i][j] = '#';

    for (int k = 0; k < 4; k++)
    {
        int ni = i + Y[k], nj = j + X[k];

        if (isSafe(ni, nj) && grid[ni][nj] == '.')
            FloodFill(ni, nj);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '#')
            {
                count++;
                FloodFill(i,j);
            }
        }
    }

    cout << count << endl;
    return 0;
}