#include <bits/stdc++.h>

using namespace std;

set<int> adjlist[1500];

vector<int> bfs()
{
    vector<int> dist(1500, -1);
    queue<int> q;

    q.push(0);
    dist[0] = 0;

    while (q.size())
    {
        int curr = q.front();
        q.pop();
        
        for (auto it: adjlist[curr])
        {
            if (dist[it] == -1)
            {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }

    return dist;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p, d;

        cin >> p >> d;

        while (d--)
        {
            int a, b;
            cin >> a >> b;

            adjlist[a].insert(b);
            adjlist[b].insert(a);
        }

        vector<int> di = bfs();
        di.shrink_to_fit();
        for (auto it: di)
        {
            if (it != -1)
                cout << it << endl;
        }
        
        if (t)
            cout << endl;
    }

    return 0;
}