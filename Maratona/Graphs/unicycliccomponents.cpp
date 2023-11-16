#include <bits/stdc++.h>

using namespace std;
int n, m, edge, node;
vector<int> adjlist[200005];
bool seen[200005];

void dfs(int s)
{
    node++;
    seen[s] = true;
    edge += adjlist[s].size();
    for (auto it : adjlist[s])
    {
        if (!seen[it])
        {
            dfs(it);
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!seen[i])
        {
            edge = 0;
            node = 0;
            dfs(i);

            edge /= 2;
            if (node != edge)
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}
