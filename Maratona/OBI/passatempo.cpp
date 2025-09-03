#include <bits/stdc++.h>

using namespace std;
int l, c;
string grid[105][105];

map<string, int> vars;

int sl[], sc[];
int main()
{
    cin >> l >> c;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            vars[grid[i][j]] = 1;
        }

        cin >> sl[i];
    }

    for (int i = 0; i < c; c++)
        cin >> sc[i];

    
}