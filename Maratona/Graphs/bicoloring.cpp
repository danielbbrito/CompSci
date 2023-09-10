#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adjlist;

bool bicolorable()
{
    vector<int> color(205, -1);
    queue<int> q;
    int s = adjlist.begin()->first;
    q.push(s);
    color[s] = 0;

    bool flag = true;

    while (q.size() && flag)
    {
        int curr = q.front(); q.pop();

        for (auto it: adjlist[curr])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[curr];
                q.push(it);
            }

            else if (color[it] == color[curr])
            {
                flag = false;
                break;
            }
        }
    }

    return flag;
}
int main()
{
    int n, l;

    cin >> n;

    while (n)
    {
        adjlist.clear();

        int l; cin >> l;

        while (l--)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].insert(b);
            adjlist[b].insert(a);
        }

        if (bicolorable())
            cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
        cin >> n;
    }
}