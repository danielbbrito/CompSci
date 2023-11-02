#include <bits/stdc++.h>

using namespace std;
map<int,set<int>> adjlist;
int seen[200010];
int ans, node;

void dfs(int i, int ct)
{
    if (ct > ans)
    {
        ans = ct;
        node = i;
    }
    seen[i] = true;
    
    for (auto it: adjlist[i])
        if (!seen[it])
            dfs(it, ct + 1);
    
}
int main()
{
    int n;cin >> n;
    
    for (int i = 1; i < n; i++)
    {
        int a, b;cin>>a>>b;
        
        adjlist[a].insert(b);
        adjlist[b].insert(a);
    }
    memset(seen, false, sizeof seen);
    ans = -1;
    dfs(1, 0);
    ans = -1;
    memset(seen, false, sizeof seen);
    dfs(node, 0);
    cout << ans << endl;
}