#include <bits/stdc++.h>

using namespace std;
#define MAX 10000
vector< pair<int, int>> adjlist[12];
int dijkstra(int ini, int fim)
{
    int dist[10010];
    for (int i = 0; i < 10010; i++)
        dist[i] = MAX;
    
    dist[ini] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    Q.push({0, ini});

    while (Q.size())
    {
        pair<int, int> u = Q.top();
        Q.pop();

        for (int i = 0; i < adjlist[u.second].size(); i++)
        {
            pair<int, int> v = adjlist[u.second][i];
            if (dist[u.second] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u.second] + v.second;
                Q.push({dist[v.first], v.first});
            }
        }
    }

    return dist[fim];
}

int main()
{
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b, p;

        cin >> a >> b >> p;

        adjlist[a].push_back({b, p});
        adjlist[b].push_back({a, p});
    }

    cout << dijkstra(1, 6) << endl;
}