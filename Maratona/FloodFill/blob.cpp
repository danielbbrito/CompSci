#include <bits/stdc++.h>

using namespace std;
char grid[30][30];
int ct;
int X[] = {1, 0, -1, 0, 1, 1, -1, -1};
int Y[] = {0, 1, 0, -1, 1, -1, 1, -1};
int lin, sz;
bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < lin && j < sz;
}

void floodfill(int i, int j)
{
    grid[i][j] = '0';
    ct++;
    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];

        if (isSafe(Ni, Nj) && grid[Ni][Nj] == '1')
            floodfill(Ni, Nj);
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        ct = 0;
        getline(cin, s);
        getline(cin, s);
        lin = 0; sz = 0;
        while (s != "")
        {
            for (int j = 0; j < s.length(); j++)
            {
                grid[lin][j] = s[j];
            }

            lin++;
            sz = s.length();
            getline(cin, s);
        }
        int max = 0;
        for (int j = 0; j < lin; j++)
        {
            for (int k = 0; k < sz; k++)
            {
                if (grid[j][k] == '1')
                    floodfill(j, k);

                if (ct > max)
                    max = ct;
                ct = 0;
            }
        }

        cout << max << endl;

        if (n) cout << '\n';
    }
}