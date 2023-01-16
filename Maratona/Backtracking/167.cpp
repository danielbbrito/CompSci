#include <iostream>
using namespace std;

bool isValid(int l, int c, int m[8][8])
{
    // Validate column
    for (int i = l - 1; i >= 0; i--)
        if (m[i][c] == 0)
            return false;
    
    // Validate diag1
    for (int i = l - 1, j = c - 1; j >= 0; i--, j--)
        if (m[i][j] == 0)
            return false;
    
    // Validate diag2
    for (int i = l - 1, j = c + 1; j < 8; i--, j++)
        if (m[i][j] == 0)
            return false;

    return true;

}
int score(int l, int m[8][8], int sum)
{
    if (l == 8)
    {
        return sum;
    }

    bool flag = false;
    for (int i = 0; i < 8; i++)
    {
        if (isValid(l, i, m))
        {
            flag = true;
            sum += m[l][i];
            m[l][i] = 0;
            return score(l++, m, sum);
        }
    }

    return 0;
}

int main()
{
    int k;
    int board[8][8];

    //cin >> k;

    for (int i = 0; i < 1; i++)
    {
        // Ask user to input 2d array
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                cin >> board[i][j];
        
        // Evaluate score for this board
        int sum = score(0, board, 0);

        cout << sum << endl;
    }

    return 0;
}