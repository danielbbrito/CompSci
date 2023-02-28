/**
 * DFS or BFS?
*/
#include <bits/stdc++.h>

using namespace std;
set<int> adjlist[500];

int bfs(int s)
{
    queue<int> q;
    vector<int> dist(500, -1);
    q.push(s);
    dist[s] = 0;
    bool flag = true;
    while (q.size())
    {
        int curr = q.front();
        q.pop();

        for (auto it: adjlist[curr])
            if (dist[it] == -1 || dist[curr] + 1 <= dist[it])
            {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }

        flag = false;
    }

    return dist[s];
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        int v, a;

        cin >> v >> a;

        for (int i = 0; i < a; i++)
        {
            int b, c;

            cin >> b >> c;

            adjlist[b].insert(c);
            adjlist[c].insert(b);
        }

        cout << bfs(n) << endl;
    }

    return 0;
}