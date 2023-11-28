// Use union find instead
#include <bits/stdc++.h>

using namespace std;

vector<int> al[200005];
set<pair<int,int>> restricted;
int seen[200005];

bool dfs(int s)
{
    seen[s] = 1;

    for (auto it: al[s])
    {
        if (restricted.find({s, it}) != restricted.end())
            return false;
        else if (!seen[it])
            return dfs(it);
    }

    return true;
}
int main()
{
    int n, m;cin>>n>>m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    int k;
    cin >> k;
    while (k--)
    {
        int a, b;cin>>a>>b;

        restricted.insert({a, b});
    }

    int q;cin>>q;
    while (q--)
    {
        int a, b;

        // add edge
        al[a].push_back(b);
        al[b].push_back(a);
        memset(seen, false, sizeof(seen));
        if (dfs(a))
        {
            cout << "Yes\n";
        }
        else cout << "No\n";

        // Remove edge
        al[a].pop_back();
        al[b].pop_back();

    }

}