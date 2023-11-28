#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;cin>>m;
    vector<int> al[205];
    vector<int> color;
    while (m--)
    {
        for (int i = 1; i <= 205; i++) al[i].clear();
        color.clear();
        int n;cin>>n;
        color.assign(n + 1, 1000000000);

        for (int i = 1; i <= n; i++)
        {
            int tam;cin>>tam;

            while (tam--)
            {
                int e; cin >> e;
                al[i].push_back(e);
                al[e].push_back(i);
            }
        }

        // Check bipartite
        int seen[n + 1];
        memset(seen, false, sizeof(seen));
        int ans = 0;
        for (int i = 1; i<=n; i++)
        {
            if (!seen[i])
            {
                queue<int> q;
                int zero = 0, um = 0, flag = 0;
                q.push(i);
                color[i] = 0;
                while (q.size())
                {
                    int u = q.front();q.pop();
                    seen[u] = true;
                    for (auto it: al[u])
                    {
                        if (color[it] == 1000000000)
                        {
                            color[it] = color[u] - 1;
                        }
                        else if (color[it] == color[u])
                        {
                            flag = 1;
                        }
                    }

                    if (!flag)
                    {
                        for (int j = 1; j <= n; j++)
                        {
                            if (color[j])
                                um++;
                            else zero++;
                        }

                        ans += max(zero, um);
                    }
                }
            }
        }

        cout << ans << endl;
    }
}