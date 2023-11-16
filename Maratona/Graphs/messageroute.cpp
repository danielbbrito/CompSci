#include <bits/stdc++.h>

using namespace std;
int n, m;
set<int> adjlist[200005];

void ppath(int path[], int i)
{
    if (path[i] == i)
    {
        cout << i;
        return;
    }
    ppath(path, path[i]);

    cout << ' ' << i;
}
void bfs(int e)
{
    int path[n + 1];
    for (int i = 1; i <= n; i++)
        path[i] = i;
    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 1;

    while (q.size())
    {
        int curr = q.front();
        q.pop();

        if (curr == e)
        {
            cout << dist[e] << endl;
            ppath(path, e);
            return;
        }

        for (auto it : adjlist[curr])
        {
            if (dist[it] == -1 || dist[it] > dist[curr] + 1)
            {
                q.push(it);
                dist[it] = dist[curr] + 1;
                path[it] = curr;
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].insert(b);
        adjlist[b].insert(a);
    }

    bfs(n);
    cout << endl;
}