#include <bits/stdc++.h>

using namespace std;
char grid[55][55];
int w, h, ct;

int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < h && j < w;
}

void fillDot(int i, int j)
{
    grid[i][j] = '*';

    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];

        if (isValid(Ni, Nj) && grid[Ni][Nj] == 'X')
            fillDot(Ni, Nj);
    }
}

void FloodFill(int i, int j)
{
    if (grid[i][j] == 'X')
    {
        fillDot(i, j);
        ct++;
    }

    grid[i][j] = '.';

    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];

        if (isValid(Ni, Nj) && grid[Ni][Nj] == '*' || grid[Ni][Nj] == 'X')
            FloodFill(Ni, Nj);
    }
}

int main()
{
    cin >> w >> h;

    int t = 1;

    while (w || h)
    {
        vector<int> dice;
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> grid[i][j];

        printf("Throw %d\n", t);

        int flag = 0;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '*' || grid[i][j] == 'X')
                {
                    ct = 0;

                    FloodFill(i, j);

                    dice.push_back(ct);
                }
            }
        
        sort(dice.begin(), dice.end());
        
        cout << *dice.begin();
        for (auto it = next(dice.begin(), 1); it != dice.end(); it++)
            cout << ' ' << *it;
        
        cout << "\n\n";
        cin >> w >> h;
        t++;
    }
}