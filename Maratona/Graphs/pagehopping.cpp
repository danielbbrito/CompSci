#include <bits/stdc++.h>

using namespace std;

int main()
{
    int am[105][105];
    for (int i = 0; i < 105; i ++)
        for (int j = 0; j < 105; j++)
            am[i][j] = 1000000000;


    int a, b, t = 1;
    cin >> a >> b;

    while (a && b)
    {
        int mx = max(a, b);
        float count = 1.0;
        am[a][b] = 1;

        cin >> a >> b;
        
        while (a || b)
        {
            mx = max(max(a, b), mx);
            count++;
            am[a][b] = 1;
            cin >> a >> b;
        }

        for (int k = 1; k <= mx; k++)
            for (int i = 1; i <= mx; i++)
                for (int j = 1; j <= mx; j++)
                    am[i][j] = min(am[i][j], am[i][k] + am[k][j]);

        int sum = 0;
        for (int i = 1; i <= mx; i++)
            for (int j = 1; j <= mx; j++)
                sum += am[i][j];

        cout << fixed << setprecision(3) << "Case " << t << ": average length between pages = " << sum / count  << " clicks\n";
        cin >> a >> b;
        t++;
    }
}