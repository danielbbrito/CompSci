#include <bits/stdc++.h>
using namespace std;
int l, r, c;
char levels[36][36][36];
int Y[] = {1, 0, -1, 0};
int X[] = {0, 1, 0, -1};

bool isValid(int lv, int i, int j)
{
    return lv >= 0 && i >= 0 && j >= 0 && lv < l && i < r && j < c;
}
int bfs(int l, int i, int j)
{
    queue<vector<int>> q;
    int dist[36][36][36];

    for (int d = 0; d < 36; d++)
        for (int e = 0; e < 36; e++)
            for (int f = 0; f < 36; f++)
                dist[d][e][f] = -1;

    dist[l][i][j] = 0;
    q.push({l, i, j});

    while (q.size())
    {
        vector<int> u = q.front();

        q.pop();

        if (levels[u[0]][u[1]][u[2]] == 'E')
            return dist[u[0]][u[1]][u[2]];
        
        for (int k = 0; k < 4; k++)
        {
            // Check same level
            int Ni = u[1] + Y[k], Nj = u[2] + X[k];

            if (isValid(u[0], Ni, Nj) && levels[u[0]][Ni][Nj] != '#' && dist[u[0]][Ni][Nj] == -1)
            {
                // Push same level
                dist[u[0]][Ni][Nj] = dist[u[0]][u[1]][u[2]] + 1;
                q.push({u[0], Ni, Nj});
            }
        }

        if (isValid(u[0] + 1, u[1], u[2]) && levels[u[0]+1][u[1]][u[2]] != '#' && dist[u[0]+1][u[1]][u[2]] == -1)
        {
            dist[u[0]+1][u[1]][u[2]] = dist[u[0]][u[1]][u[2]] + 1;
            q.push({u[0]+1, u[1], u[2]});
        }

        if (isValid(u[0] - 1, u[1], u[2]) && levels[u[0]-1][u[1]][u[2]] != '#' && dist[u[0]-1][u[1]][u[2]] == -1)
        {
            dist[u[0]+1][u[1]][u[2]] = dist[u[0]][u[1]][u[2]] + 1;
            q.push({u[0]-1, u[1], u[2]});
        }
    }

    return -1;
}
int main()
{
    cin >> l >> r >> c;

    while (l || r || c)
    {
        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
                for (int k = 0; k < c; k++)
                    cin >> levels[i][j][k];
        
        int s1=-1, s2, s3;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    if (levels[i][j][k] == 'S')
                    {
                       s1=i,s2=j,s3=k;
                        break;
                    }
                }

                if (s1 != -1)
                    break;
            }

            if (s1 != -1)
                break;
        }
        
        int ct = bfs(s1, s2, s3);
        if (ct == -1)
            cout << "Trapped!\n";
        
        else
            cout << "Escaped in " << ct << " minute(s).\n";
        
        cin >> l >> r >> c;
    }

    return 0;
}