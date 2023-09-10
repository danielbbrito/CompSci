#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> adjlist;

int main()
{
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < c; i++)
    {
        int a, m;

        cin >> a >> m;

        while (m--)
        {
            int b;
            cin >> b;

            adjlist[b].push_back(a);
        }
    }

    set<int> zero;

    for (auto it: adjlist)
    {
        if (adjlist[it.first].empty())
            zero.insert(it.first);
    }

    for (auto it:zero)
        cout << it << endl;

    return 0;
}