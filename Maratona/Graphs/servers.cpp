#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<ii> adjlist[20005];

int shortest(int s, int e)
{
    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = m * 10000;

    priority_queue<ii, vector<ii>, greater<ii>> q;
    dist[s] = 0;
    q.push({s, 0});

    while (q.size())
    {
        ii curr = q.top();
        q.pop();

        for (int i = 0; i < adjlist[curr.first].size(); i++)
        {
            ii v = adjlist[curr.first][i];

            if (dist[curr.first] + v.second < dist[v.first])
            {
                dist[v.first] = dist[curr.first] + v.second;
                q.push({v.first, dist[v.first]});
            }
        }
    }

    return dist[e];
}

int main()
{
    int cases;

    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        int s, t;
        cin >> n >> m >> s >> t;

        for (int j = 0; j < m; j++)
        {
            int a, b, p;

            cin >> a >> b >> p;

            adjlist[a].push_back({b, p});
            adjlist[b].push_back({a, p}); 
        }

        int ans = shortest(s, t);

        if (ans < (m * 10000))
            cout << "Case #" << i << ": " << shortest(s, t) << endl;
        
        else
            cout << "Case #" << i << ": unreachable\n";

        for (int i = 0; i < 20005; i++)
            adjlist[i].clear();
    }
}