// WHAT THE FUCK IS THIS INPUT MY MAN???!?!??!?!?
#include <bits/stdc++.h>

using namespace std;

char grid[100][100];

int X[] = {1, -1, 0, 0, 1, -1, -1, 1};
int Y[] = {0, 0, 1, -1, 1, -1, 1, -1};
int count;

bool isSafe(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m ? true : false;
}

void FloodFill(int i, int j, int n, int m)
{
    grid[i][j] = 'L';
    ::count++;

    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isSafe(Ni, Nj, n, m) && grid[Ni][Nj] == 'W')
            FloodFill(Ni, Nj, n, m);
    }

    return;
}

int main()
{
    int t;
    char c;
    // Read number of test cases
    cin >> t;
    cin >> c;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        // Read grid
        string s;

        int q = 0;
        int columns;

        getline(cin, s);

        s = " ";

        // Read a string containing a line of input
        while (!s.empty())
        {
            // Go to new line in the grid
            q++;

            getline(cin, s);

            columns = !s.empty() ? s.length() : columns;
            // For each character in the string, add to its respewctive grid column on the appropriate line
            for (int g = 0; g < columns; g++)
            {
                grid[q][g] = s[g];
            }
        }

        int a, b;     
        while (cin >> a >> b)
        {
            ::count = 0;

            FloodFill(a, b, q - 1, columns);

            cout << ::count << endl;
        }
    }

    return 0;
}