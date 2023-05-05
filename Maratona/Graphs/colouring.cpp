#include <bits/stdc++.h>

using namespace std;

vector<char> grid[33];
char st, init;
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
        ct = 0;
        ::max = 0;
        int flag = 0;
        while (line[0] != '_')
        {

            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ' && !flag)
                {
                    init = line[i];
                    flag = 1;
                }
                grid[ct].push_back(line[i]);
            }

            ct++;
            if (line.length() > ::max)
                ::max = line.length();
            getline(cin, line);
        }

        for (int i = 0; i < line.length(); i++)
            grid[ct].push_back(line[i]);

        for (int i = 0; i < ct; i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] != ' ' && grid[i][j] != init)
                {
                    st = grid[i][j];
                    FloodFill(i, j);
                }

        for (int i = 0; i <= ct; i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
                cout << grid[i][j];

            cout << endl;
        }

        for (int i = 0; i < 33; i++)
            grid[i].clear();
    }

    return 0;
}