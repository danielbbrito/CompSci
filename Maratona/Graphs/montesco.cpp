#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adjlist;
int seen[205];
int zeros, uns;

void dfs(int s, int color)
{
    if (!color)
        zeros++;
    else uns++;
    seen[s] = true;

    for (auto it: adjlist[s])
        if (!seen[it])
            dfs(it, 1-color);

}

int main()
{
    int m;

    cin >> m;

    while (m--)
    {
        adjlist.clear();
        int n;
        cin>>n;
        cin.ignore();

        for (int i = 1; i <= n; i++)
        {
            int j;
            cin >> j;

            while (j--)
            {
                int a; cin >> a;

                adjlist[i].insert(a);
                adjlist[a].insert(i);
            }
        }

        dfs(adjlist.begin()->first, 0);

            if (uns > zeros)
                cout << uns << endl;
            else cout << zeros << endl;

    }
}