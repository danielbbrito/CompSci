// ??????
#include <bits/stdc++.h>
using namespace std;

#define SIZE 8

int board[SIZE][SIZE];

bool isValid()
{
    return true;
}

void queens(int row)
{
    if (row > SIZE)
        return;
}

int main()
{
    int cases, n, m;

    cin >> cases;
    cout << '\n';
    cin >> n >> m;

    // Set initial queen position value
    memset(board, 0, sizeof(board));
    board[n - 1][m - 1] = 1;
}