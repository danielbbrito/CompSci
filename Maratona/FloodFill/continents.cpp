#include <iostream>

using namespace std;

#define SIZE 20

char arr[SIZE][SIZE];
char land;
int n, m, n1, m1, count=0;

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

void floodContinent(int i, int j)
{
    // Flood current element, so that it is no longer accessible
    arr[i][j] = land + 3;
    ::count++;

    // Check adjacent elements
    for (int k = 0; k < 4; k++)
    {
        int Ni = i + Y[k];
        int Nj = j + X[k];

        if (Ni >= 0 && Nj >= 0 && Ni < n && Nj < m && arr[Ni][Nj] == land)
            floodContinent(Ni, Nj);
    }

    if (j == m - 1 && arr[i][0] == land)
        floodContinent(i, 0);
    
    else if (j == 0 && arr[i][m - 1] == land)
        floodContinent(i, m - 1);

    return;

}

int main()
{
    // Read map size
    while (cin >> n >> m)
    {
        int ans = 0;

        // Read map
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        // Read size of king's territory
        cin >> n1 >> m1;

        land = arr[n1][m1];

        // Flood the king's continent
        floodContinent(n1, m1);

        // Iterate over the continent
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == land)
                {
                    ::count = 0;
                    floodContinent(i, j);

                    
                    ans = max(ans, ::count);
                }

        cout << ans << endl;
    }

    return 0;
}