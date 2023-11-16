#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define int long long

vector<ii> adjlist[200005];
int n,m;

vector<int> dijkstra()
{
    vector<int> dist(n + 1, LLONG_MAX);
    bool seen[n+1];
    memset(seen, false, sizeof seen);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push(ii(0, 1));
    dist[1] = 0;

    while (pq.size())
    {
        ii curr = pq.top();
        pq.pop();
        if (dist[curr.second] < curr.first || seen[curr.second]) continue;
        seen[curr.second] = true;
        for (auto it: adjlist[curr.second])
        {
            if (dist[it.second] > dist[curr.second] + it.first)
            {
                dist[it.second] = dist[curr.second] + it.first;
                pq.push({dist[it.second], it.second});
            }
        }
    }

    return dist;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        int a, b, w;cin>>a>>b>>w;
        adjlist[a].push_back(ii(w, b));
    }

    vector<int> dist = dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;
}