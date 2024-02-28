#include <bits/stdc++.h>
 
using namespace std;
int n, m;
map<int, vector<int>> adjlist;
bool seen[100005];
 
void build_path(int s, int b, int path[])
{
    stack<int> p;
    p.push(b);
    p.push(s);
    s = path[s];
    while (path[s] != s)
    {
        p.push(s);
        s = path[s];
    }
    p.push(b);
    cout << p.size() << endl;
    cout << p.top();
    p.pop();
    while (p.size())
    {
        cout << ' ' << p.top();
        p.pop();
    }
    cout << endl;
}
 
bool dfs(int s, int start, int path[])
{       
    seen[s] = true;
 
    for (auto it: adjlist[s])
    {
        if (!seen[it])
        {
            path[it] = s;
            if (dfs(it, start, path))
                return true;
        }
 
        else if (path[s] != it)
        {
            path[it] = it;
            build_path(s,it, path);
            return true;
        }
    }
 
    return false;
}   
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
 
    int path[n + 1];
    bool possible = false;
    for (int i = 1; i<=n && !possible;i++)
    {
        if (!seen[i])
        {
 
            if (dfs(i, i, path))
            {
                possible = true;
            }
        }
    }
    
    if (!possible) cout << "IMPOSSIBLE\n";
}