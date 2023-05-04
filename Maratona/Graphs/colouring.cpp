#include <bits/stdc++.h>

using namespace std;

char grid[33][81];
char st;
int ct, max;
int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return i >= 1 && j >= 1 && i < ct && j < ::max && grid[i][j] == ' ';
}
void FloodFill(int i, int j)
{
    grid[i][j] = st;

    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];

        if (isValid(Ni, Nj))
            FloodFill(Ni, Nj);
    }
    
    return;
}

int main()
{
    string line;

    while (getline(cin, line))
    {
        for (int i = 0; i < 33; i++)
            memset(grid[i], ' ', sizeof(grid[i]));

        ct = 0;
        ::max = 0;
        int flag = 0;
        while (!flag)
        {
            if (line[0] != '-')
                flag = 1;
            for (int i = 0; i < line.length(); i++)
                grid[ct][i] = line[i];
            
            ct++;
            if (line.length() > ::max)
                ::max = line.length();
            getline(cin, line);
        }
        
        
        for (int i = 0; i < ct; i++)
            for (int j = 0; j < ::max; j++)
                if (grid[i][j] != ' ' && grid[i][j] != 'X')
                {
                    st = grid[i][j];
                    FloodFill(i, j);
                }
        
        for (int i = 0; i < ct; i++)
        {
            for (int j = 0; j < ::max; j++)
                cout << grid[i][j];
            
            cout << endl;
        }
    }

    return 0;
}