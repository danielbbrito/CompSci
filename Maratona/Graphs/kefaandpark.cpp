#include <bits/stdc++.h>
using namespace std;
bool has_cat[100005], seen[100005];
int timer[100005];
int restaurants=0, n, m;
map<int, set<int>> adjlist;

void dfs(int s, int cat, int maximum, int consecutive)
{
    if (adjlist[s].empty())
    {
        if (has_cat[s])
        {
            if (cat)
                maximum = max(maximum, consecutive + 1);
        }
    }
    if (maximum <= m && adjlist[s].empty())
    {
        restaurants++;
    }
    
    seen[s] = 1;


    for (auto it: adjlist[s])
    {
        if (!seen[it])
        {
            ::timer[it] = ::timer[s] + 1;
            if (has_cat[s])
            {
                if (cat)
                {
                    maximum = max(maximum, consecutive + 1);
                    dfs(it, 1, maximum, consecutive + 1);
                }
                else
                {
                    maximum = max(maximum, 1);
                    dfs(it, 1, maximum, 1);
                }
            }
            else
                dfs(it, 0, maximum, 0);
        }
    }
    
    if (adjlist[s].size() == 1 && ::timer[s])
    {
        if (has_cat[s])
        {
            if (cat)
                maximum = max(maximum, consecutive + 1);
        }
    }
    if (maximum <= m && adjlist[s].size() == 1 && ::timer[s])
    {
        restaurants++;
    }
}

int main()
{
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
    {
        int a;cin>>a;
        if (a) has_cat[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int a,b;cin>>a>>b;
        adjlist[a].insert(b);
        adjlist[b].insert(a);
    }

    dfs(1, 0, 0, 0);
    cout << restaurants << endl;
    return 0;
}