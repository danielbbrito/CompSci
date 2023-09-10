#include <bits/stdc++.h>

using namespace std;
int n,m;
bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main()
{
    cin >>n>>m;
    char arr[505][505];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((i >= 0 && arr[i-1][j] == 'o') || ((arr[i][j-1] == 'o' && arr[i+1][j-1] == '#') || (arr[i][j+1] == 'o' && arr[i+1][j+1] == '#')) && arr[i][j] == '.')
                arr[i][j] = 'o';
        }

    for (int i = 0; i < n;i++)
    {
        for (int j=0; j < m;j++)
            cout << arr[i][j];
        
        cout << endl;
    }
    return 0;
}