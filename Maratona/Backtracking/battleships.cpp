#include <iostream>

using namespace std;

#define SIZE 101
int n, shipSize = 0;
char grid[SIZE][SIZE];

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

// Checks whether a ship is vertical or not
bool isVertical(int i, int j)
{
    for (int k = 0; k <  2; k++)
    {
        int Ni = i + Y[k];

        if (Ni >= 0 && Ni < n && (grid[Ni][j] == 'x' || grid[Ni][j] == '@'))
            return true;
    }

    return false;
}

bool isShip(int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (Ni >= 0 && Nj >= 0 && Nj < n && Ni < n && grid[Ni][Nj] != '.')
            return false;
    }

    return true;
}
// Flood fills vertical ships
void FloodFillVert(int i, int j)
{
    grid[i][j] = '.';
    shipSize++;

    for (int k = 0; k < 2; k++)
    {
        int Ni = i + Y[k];

        if (Ni >= 0 && Ni < n && (grid[Ni][j] == 'x' || grid[Ni][j] == '@'))
            FloodFillVert(Ni, j);
    }

    return;
}

// Flood fills horizontal ships
void FloodFillHor(int i, int j)
{
    grid[i][j] = '.';
    shipSize++;

    for (int k = 2; k < 4; k++)
    {
        int Nj = j + X[k];

        if (Nj >= 0 && Nj < n && (grid[i][Nj] == 'x' || grid[i][Nj] == '@'))
            FloodFillHor(i, Nj);
    }

    return;
}

int main()
{
    int t;

    // Read t
    cin >> t;

    // Read t cases
    for (int i = 1; i <= t; i++)
    {
        int count = 0;

        // Read n
        cin >> n;

        int maxSize = n / 2;
        // Read grid
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                cin >> grid[j][k];
        
        // Iterate over grid
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (grid[j][k] == 'x')
                {
                    if (isVertical(j, k))
                        FloodFillVert(j, k);
                    
                    else if (isShip(j, j))
                        grid[j][k] = '.';
                    
                    else    
                        FloodFillHor(j, k);
                    
                    if (shipSize <= maxSize)
                        count++;
                    
                    shipSize = 0;
                }
            }
        
        // Print number of ships
        cout << "Case " << i << ": " << count << endl;
    }
}