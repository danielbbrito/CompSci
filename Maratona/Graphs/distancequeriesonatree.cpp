#include <bits/stdc++.h>

using namespace std;
#define int long long
set<pair<int, int>> al[20005];
int weights[200005];

int dijkstra(int s, int e)
{
    vector<int> dist(-1, 200005);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0, 0});

    while (pq.size())
    {
        pair<int,int> curr = pq.top();pq.pop();

        if (curr.second == e) return dist[e];

        for (auto it: al[curr.second])
        {
            if (dist[it.second] == -1 || dist[it.second] > dist[curr.second] + weights[it.first])
            {
                dist[it.second] = dist[curr.second] + weights[it.first];
                pq.push({dist[it.second], it.second});
            }
        }
    }

    return -1;
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        al[a].insert({i, b});
        al[b].insert({i, a});
        weights[i] = w;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int code, i, w;cin>>code>>i>>w;

        if (code == 1)
            weights[i] = w;
        else
        {
            cout << dijkstra(i, w) << endl;
        }
    }
}