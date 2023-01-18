#include <bits/stdc++.h>

using namespace std;

#define SIZE 20

char arr[SIZE][SIZE];
char land;
int n, m, n1, m1;

int X[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Y[] = {0, 0, 1, -1, 1, -1, -1, 1};

int floodContinent(int i, int j, int count)
{
    // Flood current element, so that it is nmo longer accessible
    arr[i][j] = '0';
    count++;

    // Check adjacent elements
    for (int k = 0; k < 8; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (Ni >= 0 && Nj >= 0 && Ni < n && Nj < m && arr[Ni][Nj] == land)
            return floodContinent(Ni, Nj, count);
    }

    if (j == m - 1 && arr[i][0] == land)
        return floodContinent(i, 0, count);
    
    else if (j == 0 && arr[i][m - 1] == land)
        return floodContinent(0, m - 1, count);

    return count;

}

int main()
{
    // Read map size
    while (cin >> n >> m)
    {
        memset(arr, 0, sizeof(arr));
        int ans = 0;

        // Read map
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        // Read size of king's territory
        cin >> n1 >> m1;
        cout << '\n';

        land = arr[n1][m1];

        // Flood the king's continent
        floodContinent(n1, m1, 0);

        // Iterate over the continent
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == land)
                {
                    int current = floodContinent(i, j, 0);

                    if (current > ans)
                        ans = current;
                }

        cout << ans << endl;
    }

    return 0;
}