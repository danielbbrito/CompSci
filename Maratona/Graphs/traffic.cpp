#include <bits/stdc++.h>

using namespace std;
#define INF 1e9

int main()
{
    int n;
    int count = 0;
    while (cin >> n)
    {
        count++;
        vector<int> dist;
        dist.push_back(INF);
        for (int i = 1; i <= n; i++)
        {
            int w; cin >> w;
            dist.push_back(w);
        }

        int r;cin>>r;
        map<int, set<pair<int, int>>> adjlist;
        while (r--)
        {
            int a,b;cin>>a>>b;

            adjlist[a].insert({b, pow(dist[b] - dist[a], 3)});
            //cout << pow(dist[b] - dist[a], 3) << endl;
        }

        for (int i = 2; i < dist.size(); i++)
            dist[i] = INF;
        
        dist[1] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 1; u <= n; u++)
            {
                if (dist[u] != INF)
                {
                    for (auto &[v, w]: adjlist[u])
                    {
                        if (dist[v] > dist[u] + w)
                        {
                            dist[v] = dist[u] + w;
                        }
                    }
                }
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            
            for (int i = 1; i <= n; i++)
            {
                if (dist[i] != INF)
                {
                    for (auto &[v, w]: adjlist[i])
                    {
                        if (dist[v] > dist[i] + w)
                        {
                            dist[v] = -INF;
                        }
                    }
                }
            }
        }
        int q;
        cin >> q;
        cout << "Set #" << count << endl;

        while (q--)
        {
            int c; cin>>c;

            if (dist[c] >= 3 && dist[c] != INF)
                cout << dist[c] << endl;
            
            else
                cout << '?' << endl;
        }
    }

    return 0;
}