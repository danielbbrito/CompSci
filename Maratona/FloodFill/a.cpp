#include <bits/stdc++.h>

using namespace std;

int grid[2][150];
int n;

int X[] = {1, 0, -1, 0, 1, 1, -1, -1};
int Y[] = {0, 1, 0, -1, 1, -1, 1, -1};
bool flag;
bool isSafe(int i, int j)
{
    return i >= 0 && j >= 0 && i < 2 && j < n;
}
void FloodFill(int i, int j)
{
    if (i == 1 && j == n - 1)
    {
        flag = true;
        return;
  
    }
    
    grid[i][j] = 1;
    
    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k], Nj = j + X[k];
        
        if (isSafe(Ni, Nj) && grid[Ni][Nj] == 0)
            FloodFill(Ni, Nj);
    }

}

int main()
{
    
    cin >> n;
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    } 
    flag = false;
    FloodFill(0, 0);
    if (flag)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}