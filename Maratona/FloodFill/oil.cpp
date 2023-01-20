#include <bits/stdc++.h>

using namespace std;

#define SIZE 101

char grid[SIZE][SIZE];
int n, m;

int X[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Y[] = {0, 0, 1, -1, -1, 1, 1, -1};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m ? true : false;  
}

void FloodFill(int i, int j)
{
    grid[i][j] = '*';

    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isValid(i, j) && grid[Ni][Nj] == '@')
            FloodFill(Ni, Nj);
    }

    return;
}

int main()
{
    // Read grid dimensions
    cin >> n >> m;

    while (m != 0)
    {
        int count = 0;

        // Read grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        
        // Iterate over the grid
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    FloodFill(i, j);

                    count++;
                }
            }
        
        cout << count << endl;

        cin >> n >> m;
    }

    return 0;
}