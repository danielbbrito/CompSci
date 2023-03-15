#include <bits/stdc++.h>

using namespace std;

void dfs(int s, int t, bool seen[], set<int> adjlist[])
{
    seen[s] = true;

    for (auto it: adjlist[s])
    {
        for (int i = 0; i < t; i++)
            cout << ' ';

        cout << s << '-' << it;;

        if (!seen[it])
        {   
            cout << " pathR(G, " << it << ")\n";
            dfs(it, t + 2, seen, adjlist);
        }

        else
            cout << '\n';
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int v, e;
        cin >> v >> e;
        set<int> adjlist[v];
        bool seen[v];
        memset(seen, false, sizeof(seen));

        while (e--)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].insert(b);
        }
        
        cout << "Caso " << i << ":\n";

        for (int j = 0; j < v; j++)
            if (!seen[j] && adjlist[j].size())
            {
                dfs(j, 2, seen, adjlist);
                cout << endl;
            }
        
        for (int j = 0; j < v; j++)
            adjlist[j].clear();
    }

    return 0;
}