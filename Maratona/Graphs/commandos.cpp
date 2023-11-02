#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000
#define int long long

int32_t main()
{
    int t;cin >> t;
    for (int c = 1; c <= t; c++)
    {
        int n,r;cin>>n>>r;
        int map[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    map[i][j] = 0;
                
                else map[i][j] = MAX;
            }

        while (r--)
        {
            int a,b;cin>>a>>b;
            map[a][b] = 1;
            map[b][a] = 1;
        }

        int s,e;cin>>s>>e;

        // Floyd-Warshall
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
    
        int mx = -1;
        
        for (int i = 0; i < n; i++)
            if (mx < map[s][i] + map[i][e])
                mx = map[s][i] + map[i][e];
                
        cout << "Case " << c << ": " << mx << endl;
    }
}