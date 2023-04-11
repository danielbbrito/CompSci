#include <bits/stdc++.h>
using namespace std;

int grid[1000][1000], n, m;

int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int traverse()
{
    int dist[1000][1000];
    for (int i = 0; i < 1000; i++)
        memset(dist[i], INT_MAX, sizeof(dist[i]));
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});

    dist[{0, 0}] = grid[0][0];

    while (q.size())
    {
        pair<int , int> u = q.top();

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int Ni = u.first + Y[k], Nj = u.second + X[k];

            if (isValid(Ni, Nj) && dist[u.first][u.second] + grid[Ni][Nj] < dist[Ni][Nj])
            {
                dist[Ni][Nj] = dist[u.first][u.second] + grid[Ni][Nj];

                q.push({Ni, Nj});
            }
        }
    }

    return dist[{n-1, m-1}];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        int d = traverse();

        cout << d << endl;
    }

    return 0;
}