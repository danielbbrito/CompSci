#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, w, k,op=INT_MAX;
    cin>>h>>w>>k;
    char grid[h][w];
    for (int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
        {
            cin >>grid[i][j];
        }

    for (int i = 0; i < h; i++)
    {
        int operations = 0;
        int length = 0;
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] != 'x')
            {
                length++;
                if (grid[i][j] == '.')
                {
                    operations++;
                }

                if (length == k)
                {
                    op = min(op, operations);
                }
            }

            else
                length = operations = 0;
        }
    }

    for (int j = 0; j < w; j++)
    {
        int operations = 0;
        int length = 0;
        for (int i = 0; i < h; i++)
        {
            if (grid[i][j] != 'x')
            {
                length++;
                if (grid[i][j] == '.')
                {
                    operations++;
                }

                if (length >= k)
                {
                    op = min(op, operations - (length - k));
                }
            }

            else
                length = operations = 0;
        }
    }

    if (op == INT_MAX)
        cout << -1 << endl;

    else
        cout << op << endl;
}