#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adjlist;

int bfs(int ini, int ttl, int sz)
{
    map<string, int> dist;

    for (auto it: adjlist)
    {
        dist[to_string(it.first)] = -1;
    }

    queue<int> q;

    dist[to_string(ini)] = 0;
    q.push(ini);

    while (q.size())
    {
        int v = q.front();
        q.pop();


        for (auto it: adjlist[v])
            if (dist[to_string(it)] == -1)
            {
                q.push(it);
                dist[to_string(it)] = dist[to_string(v)] + 1;
            }

        if (dist[to_string(v)] + 1 > ttl)
            break;
    }

    int ct = 0;
    for (auto n: adjlist)
    {
        if (dist[to_string(n.first)] == -1 || dist[to_string(n.first)] > ttl)
            ct++;
    }

    return ct;
}
int main()
{
    int nc;

    cin >> nc;
    int cases = 1;
    while (nc)
    {
        // Reads the edge nodes in the network
        for (int i = 0; i < nc; i++)
        {
            int a, b;

            cin >> a >> b;

            adjlist[a].insert(b);
            adjlist[b].insert(a);
        }

        int n, ttl;
        cin >> n >> ttl;
        while (n || ttl)
        {
            cout << "Case " << cases << ": " << bfs(n, ttl, nc) << " nodes not reachable from node " << n << " with TTL = " << ttl << ".\n";
            cases++;
            
            cin >> n >> ttl;
        }

        adjlist.clear();

        cin >> nc;
    }
}