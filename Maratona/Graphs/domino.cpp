#include <bits/stdc++.h>

using namespace std;
map<int,set<int>> adjlist, adjt;
vector<int> order;
vector<int> seen;
void dfs(int i, int pass)
{
    seen[i] = true;
    
    set<int> &n = pass ==1 ? adjlist[i] : adjt[i];
    for (auto it: n)
        if (!seen[it])
            dfs(it, pass);
    
    order.push_back(i);
}

int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        order.clear();
        int n,m;cin>>n>>m;

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].insert(b);
            adjt[b].insert(a);
        }

        seen.assign(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            if (!seen[i])
                dfs(i, 1);
        }

        seen.assign(n + 1, false);
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!seen[order[i]])
            {
                dfs(i, 2);
                count++;
            }
        }

        cout << count << endl;
        adjlist.clear();adjt.clear();
    }
}