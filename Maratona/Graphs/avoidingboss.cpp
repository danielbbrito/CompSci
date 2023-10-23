#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
int am[105][105];

int fw(int s, int e)
{

}

int main()
{
    int p, r, bh, of, yh, m;

    while (cin >> p >> r >> bh >> of >> yh >> m)
    {
        for (int i = 0; i < r; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            am[a][b] = d;
            am[b][a] = d;
        }


    }
}