/**
 * @file 1082.cpp
 * @author your name (you@domain.com)
 * @about exercise about GRAPH CONNECTIVITY
 * 
 */
#include <bits/stdc++.h>
using namespace std;

map< char, set<char> > adjlist;
bool seen[26];
set<char> component;

set<char> dfs(char c)
{
    component.insert(c);
    seen[(int)(c - 97)] = true;

    for (auto itr: adjlist[c])
        if (!seen[itr - 97])
            dfs(itr);

    return component;
}

int main()
{
     int n;
     cin >> n;

     for (int j = 1; j <= n; j++)
     {
        int count = 0;
        memset(seen, false, sizeof(seen));

        int v, e;
        cin >> v >> e;
        for (int i = 0; i < v; i++)
            adjlist[97 + i] = {};
        
        for (int i = 0; i < e; i++)
        {
            char a, b;

            cin >> a >> b;
            adjlist[a].insert(b);
            adjlist[b].insert(a);
        }

        cout << "Case #" << j << ':';

        for (auto itr: adjlist)
        {
            if (!seen[itr.first - 97])
            {
                dfs(itr.first);
                count++;
                cout << '\n';

                for (auto it: component)
                    cout << it << ',';
                component.clear();
            }
        }
        
        cout << '\n' << count << " connected components\n\n";
        adjlist.clear();
     }

     return 0;
}