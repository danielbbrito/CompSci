#include <bits/stdc++.h>
using namespace std;
vector<int> al[60];
int low[60], num[60],parents[60], bridges = 0;
bool seen[60];

void dfs(int s, int ct)
{
    low[s] = num[s] = ct; // Iteration and lowest reachable equal at first
    seen[s] = true;

    for (auto it: al[s])
    {
        if (!seen[it])
        {
            parents[it] = s; // keep track of parents

            dfs(it, ct + 1);

            if (low[it] > num[s]) // No path from it to s' ancestors other than through (s, it) itself
                bridges++;
            
            low[s] = min(low[s], low[it]); // Update lowest possible reachable vertex, if there is another path
            // Otherwise it stays the same
        }

        else if (it != parents[s])
        {
            low[s] = min(low[s], num[it]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;

        cin >> a >> b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!seen[i])
        {
            dfs(i, 0);
        }
    }

    cout << bridges << endl;
}