#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
int sz;
void ppath(char path[100][100], int i, int j)
{
    if (i == j)
    {
        cout << (char)j;
        return;
    }

    ppath(path, i, path[i][j]);
    cout << ' ' << (char)j;
}

void getlen(char path[100][100], int i, int j, int count)
{
    if (i == j)
    {
        return;
    }

    getlen(path, i, path[i][j], count + 1);
    sz++;
}

int main()
{
    int s, p;
    cin >> s >> p;
    int am[100][100];

    for (int i = 64; i < 100; i++)
        for (int j = 65; j < 100; j++)
            am[i][j] = INF;
    while (p--)
    {
        char a, b;
        int d;
        cin >> a >> b >> d;
        am[a][b] = d;
        am[b][a] = d;
    }

    int n;
    cin >> n;
    while (n--)
    {
        char s, e, path[100][100];
        int cpy[100][100];
        cin >> s >> e;
        // Init path array
        for (int i = 65; i < 100; i++)
            for (int j = 65; j < 100; j++)
            {
                path[i][j] = i;
            }

        for (int i = 65; i < 100; i++)
            for (int j = 65; j < 100; j++)
                cpy[i][j] = am[i][j];

        for (int k = 65; k < 91; k++)
            for (int i = 65; i < 91; i++)
                for (int j = 65; j < 91; j++)
                    if (cpy[i][j] > cpy[i][k] + cpy[k][j])
                    {
                        cpy[i][j] = cpy[i][k] + cpy[k][j];
                        path[i][j] = path[k][j];
                    }

                    else if (cpy[i][j] == cpy[i][k] + cpy[k][j])
                    {
                        sz = 0;
                        cpy[i][j] = cpy[i][k] + cpy[k][j];
                        getlen(path, i, j, 0);
                        int curr = sz;
                        sz = 0;
                        getlen(path, i, k, 0);
                        int n = sz;
                        sz = 0;
                        getlen(path, k, j, 0);
                        n += sz;

                        if (curr > n)
                        {
                            path[i][j] = path[k][j];
                        }
                    }

        ppath(path, s, e);
        cout << endl;
    }
}