#include <bits/stdc++.h>

using namespace std;
int r, c, ct;
char grid[55][55];

int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool comparator(const pair<int, char> &p1, const pair<int, char> &p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first;

    return p1.second < p2.second;
}

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}
void FloodFill(int i, int j, char c)
{
    grid[i][j] = '.';
    ct++;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + Y[k], nj = j + X[k];

        if (isValid(ni, nj) && grid[ni][nj] == c)
            FloodFill(ni, nj, c);
    }
}
int main()
{
    int t = 1;
    cin >> r >> c;

    while (r || c)
    {
        vector<pair<int, char>> holes;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> grid[i][j];


        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != '.')
                {
                    ct = 0;
                    char c = grid[i][j];

                    FloodFill(i, j, grid[i][j]);
                    
                    holes.push_back({ct, c});
                }
            }

        cout << "Problem " << t << ":\n";

        sort(holes.begin(), holes.end(), comparator);


        for (auto it = holes.begin(); it != holes.end(); it++)
            cout << it->second << ' ' << it->first << endl;
        
        holes.clear();
        cin >> r >> c;
        t++;
    }

    return 0;
}