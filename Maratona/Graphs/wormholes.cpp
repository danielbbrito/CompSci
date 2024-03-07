#include <bits/stdc++.h>

using namespace std;
#define INF 1e9

int main()
{
    int c;cin>>c;

    while (c--)
    {
        int n, m;
        cin>>n>>m;

        set<pair<int,int>> adjlist[n];

        for (int i = 0; i < m; i++)
        {
            int x, y, t;
            cin>>x>>y>>t;
            adjlist[x].insert({y, t});
        }

        vector<int>dist(n, INF);
        dist[0] = 0;
        int changed = true;
        for (int i = 0; i < n - 1 && changed; i++)
        {
            changed = false;
            for (int u = 0; u < n; u++)
            {
                if (dist[u] != INF)
                    for (auto &[v, w]: adjlist[u])
                    {   
                        if (dist[v] > dist[u] + w)
                        {
                            dist[v] = dist[u] + w;
                            changed = true;
                        }
                    }
            }
        }

        int cycle = false;
        for (int i = 0; i < n && !cycle; i++)
        {
            if (dist[i] != INF)
            {
                for (auto &[v, w]: adjlist[i])
                {
                    if (dist[v] > dist[i] + w)
                        cycle = true;
                }
            }
        }

        if (cycle)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
}