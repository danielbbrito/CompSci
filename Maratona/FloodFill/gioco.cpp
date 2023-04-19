#include <bits/stdc++.h>

using namespace std;
bool flag;
char board[201][201];
int n;
int Y[] = {-1, -1, 0, 0, 1, 1};
int X[] = {-1, 0, -1, 1, 0, 1};

bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

void FloodFill(int i, int j)
{
    board[i][j] = 'w';

    for (int k = 0; k < 6; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (isSafe(Ni, Nj) && board[Ni][Nj] == 'b')
        {
            if (Ni == n - 1)
            {
                flag = true;
                return;
            }

            FloodFill(Ni, Nj);
        }
    }
}

int main()
{
    // Read n
    cin >> n;
    
    for (int i = 1; n; i++)
    {
        flag = false;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                cin >> board[j][k];
            }
        for (int j = 0; j < n; j++)
            FloodFill(0, j);

        if (flag)
            cout << i << " B" << endl;
        
        else
            cout << i << " W" << endl;

        cin >> n;
    }

    return 0;
}