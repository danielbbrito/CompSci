#include <bits/stdc++.h>

using namespace std;

vector<int> Sabre(int mat[][1000], int n, int m)
{
    vector<int> coord;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            int soma = mat[i+1][j] + mat[i-1][j] + mat[i][j+1] + mat[i][j-1] + 
                       mat[i-1][j-1] + mat[i+1][j-1] +mat[i-1][j+1] + mat[i+1][j+1];
            if (mat[i][j] == 42 && soma == 56)
            {
                coord.push_back(i);
                coord.push_back(j);
                return coord;
            }
        }
    }

    return coord;
}

int main()
{
    int n, m;
    cin >> n
        >> m;

    int mat[n][1000];

    // Ler matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<int> coord = Sabre(mat, n, m);
    
    if (coord.size() != 0)
        cout << coord.at(0) + 1 << ' ' << coord.at(1) + 1 << endl;
    
    else
        cout << "0 0\n";
    return 0;
}
