#include <bits/stdc++.h>

using namespace std;

int main()
{
    int am[105][105];
    for (int i = 0; i < 105; i++)
        memset(am[i], 1000000000, sizeof am[i]);

    int t;cin>>t;

    for (int i = 1; i <= t; i++)
    {
        int n, r;cin >> n >> r;

        while (r--)
        {
            int a, b;
            cin >> a >> b;

            am[a][b] = 1;
        }

        int s,d;cin >> s >> d;
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);
            }
        }

        cout << am[s][d] << endl;
    }
}