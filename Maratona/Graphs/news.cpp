#include <bits/stdc++.h>

using namespace std;

set<int> adjlist[2505];


vector<int> bfs(int s)
{
    vector<int> dist(2505, -1);
    queue<int> q;

    int md = 0, max = 0, dia, u = 2504;

    dist[s] = 0;

    q.push(s);

    while (q.size())
    {   
        if (dist[q.front()] > dist[u])
        {
            if (max > md)
            {
                md = max;
                dia = dist[u];
            }

            max = 0;
        }
        u = q.front();
        q.pop();

        for (auto it: adjlist[u])
        {
            if (dist[it] == -1)
            {
                dist[it] = dist[u] + 1;
                q.push(it);
                max++;
            }
        }

        


    }

    return {md, ++dia};
}

int main()
{
    int e;

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int n;
        cin >> n;

        while (n--)
        {
            int a;
            cin >> a;

            adjlist[i].insert(a);
        }
    }

    int t;
    cin >> t;

    while (t--)
    {
        int s;

        cin >> s;

        vector<int> md = bfs(s);

        if (md.front() == 0)
            cout << 0 << endl;
        else
            cout << md.front() << ' ' << md.back() << endl;
    }

    return 0;
}