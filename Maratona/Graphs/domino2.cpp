#include <bits/stdc++.h>
using namespace std;

vector<int> adjlist[10005];
bool seen[10005];
int ct;

void dfs(int s)
{
    seen[s] = true;
    ct++;

    for (auto it: adjlist[s])
        if (!seen[it])
            dfs(it);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        memset(seen, false, sizeof(seen));
        
        int n, m, l;
        cin >> n >> m >> l;

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
        }

        ct = 0;

        while (l--)
        {
            int z;
            cin >> z;
            if (!seen[z])
                dfs(z);
        }

        cout << ct << endl;
        
        for (int i = 0; i < 10005; i++)
            adjlist[i].clear();
    }

    return 0;
}