#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
int am[105][105];
int p[105][105];
int fw(int s, int e, int mx)
{
    int cpy[105][105];

    for (int i = 1; i < 105; i++)
        for (int j = 1; j < 105; j++)
        {
            cpy[i][j] = am[i][j];
            p[i][j] = i;
        }

    // Actual algo
    for (int k = 1; k <= mx; k++)
    {
        for (int i = 1; i <= mx; i++)
        {
            for (int j = 1; j <= mx; j++)
            {
                if (cpy[i][j] > cpy[i][k] + cpy[k][j])
                {
                    cpy[i][j] = cpy[i][k] + cpy[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    return cpy[s][e];
}

void remove(int i, int j, int ant)
{
    if (i != j)
    {
        remove(i, p[i][j], j);
    }

    am[ant][j] = INF;
    am[j][ant] = INF;
}

int main()
{
    int p, r, bh, of, yh, m;

    while (cin >> p >> r >> bh >> of >> yh >> m)
    {
        for (int i = 1; i < 105; i++)
            for (int j = 1; j < 105; j++)
                if (i != j)
                    am[i][j] = INF;

        for (int i = 0; i < r; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            am[a][b] = d;
            am[b][a] = d;
        }

        if (am[bh][of] != INF)
            am[bh][of] = INF;
        int inter = fw(bh, of, p);

        while (inter != INF && inter)
        {
            remove(bh, of, bh);
            inter = fw(bh, of, p);
        }

        inter = fw(yh, m, p);

        if (inter == INF || yh == m || of == m || bh == m)
            cout << "MISSION IMPOSSIBLE.\n";

        else
            cout << inter << endl;
    }
}