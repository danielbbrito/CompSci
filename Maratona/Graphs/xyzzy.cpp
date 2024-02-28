#include <bits/stdc++.h>

using namespace std;
#define INF 1e9

bool bfs(map<int, set<int>> adjlist, int s, int e)
{
    vector<int> dist(e + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (q.size())
    {
        int curr = q.front(); q.pop();

        if (curr == e) return true;

        for (auto it: adjlist[curr])
        {
            if (dist[it] == -1 || dist[it] < dist[curr] + 1)
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
    int n;cin>>n;

    while (n > -1)
    {
        map<int, set<int>> adjlist;
        int weights[n + 1];
        
        for (int i = 1; i <= n; i++)
        {
            int w,k;cin>>w>>k;
            weights[i] = k;

            while (k--)
            {
                int b; cin>>b;
                adjlist[i].insert(b);
            } 
        }

        vector<int> dist(n + 1, INF);
        bool changed = true;
        for (int i = 0; i < n - 1 && changed; i++)
        {
            changed = false;
            for (int i = 1; i <= n; i++)
            {
                if (dist[i] != INF)
                    for (auto it: adjlist[i])
                    {
                        if (dist[it] > dist[i] + weights[it])
                        {
                            changed = true;
                            dist[it] = dist[i] + weights[it];
                        }
                    }
            }
        }

        // Check connectedness
        bool cycle = false;
        // Check positive cycle
        for (int i = 1; i <= n && !cycle; i++)
        {
            if (dist[i] != INF)
            {
                for (auto it: adjlist[i])
                {
                    if (dist[it] < dist[i] + weights[it])
                    {
                        if (bfs(adjlist, it, n))
                        {
                            cout << "winnable\n";
                        }
                        else
                            cout << "hopeless\n";

                        cycle = true;
                    }
                }
            }
        }

        if (!cycle && dist[n] != INF)
            cout << "winnable\n";

        cin >> n;
    }
}