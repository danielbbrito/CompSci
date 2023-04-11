#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adjlist;

int bfs(string s, string e)
{
    map<string, int> dist;

    queue<string> q;

    dist[s] = 0;
    q.push(s);

    while (q.size())
    {
        string u = q.front();

        q.pop();

        if (u == e)
            return dist[u];

        for (auto it: adjlist[u])
        {
            if (dist.find(it) == dist.end())
            {
                dist[it] = dist[u] + 1;
                q.push(it);
            }
        }
    }

    return -1;
}

int main()
{
    int t;

    cin >> t;
    cout << "SHIPPING ROUTES OUTPUT\n\n";

    for (int i = 1; i <= t; i++)
    {
        int m, n, p;

        cin >> m >> n >> p;

        string s;
        for (int i = 0; i < m; i++) cin >> s;

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;

            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        cout << "DATA SET  " << i << endl << endl;

        while (p--)
        {
            int w;
            string s, e;

            cin >> w >> s >> e;

            int am = bfs(s, e);

            if (am == -1)
                cout << "NO SHIPMENT POSSIBLE\n";
            
            else
                cout << "$" << w * am * 100 << endl;
        }

        cout << endl;
        adjlist.clear();
    }

    cout << "END OF OUTPUT\n";
    return 0;
}