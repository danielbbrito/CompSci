#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adjlist;

bool bfs(int n)
{
    vector<int> dist(n+1, -1);

    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (q.size())
    {
        int curr = q.front(); q.pop();

        if (curr == n)
            return dist[n] == 2;

        for (auto it: adjlist[curr])
        {
            if (dist[it] == -1 || dist[it] > dist[curr] + 1)
            {
                q.push(it);
                dist[it] = dist[curr] + 1;
            }
        }
    }

    return false;
}
int main()
{
    int n,m;cin>>n>>m;

    while (m--)
    {
        int a,b;cin>>a>>b;
        adjlist[a].insert(b);
        adjlist[b].insert(a);
    }

    if (bfs(n))
        cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
}