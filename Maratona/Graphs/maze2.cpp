#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> ppii;

int grid[1005][1005];
int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};
int n,m;

bool isValid(int i, int j)
{
    return i >= 0&& j>=0&&i<n&&j<m;
}
int dijkstra()
{
    int dist[1000][1000];
    for (int i = 0; i < 1000; i++)
        memset(dist[i], 10000, sizeof(dist[i]));
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({dist[0][0], {0, 0}});

    while (q.size())
    {
        ppii u = q.top();

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int Ni = u.second.first + Y[k], Nj = u.second.second;

            if (isValid(Ni, Nj) && (dist[Ni][Nj] == -1 || u.first + grid[Ni][Nj] < dist[Ni][Nj]))
            {
                dist[Ni][Nj] = u.first + grid[Ni][Nj];

                q.push({dist[Ni][Nj], {Ni, Nj}});
            }
        }
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n); scanf("%d", &m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int a;
                scanf("%d", &a);
                grid[i][j] = a;
            }

        printf("%d\n", dijkstra());
    }
}