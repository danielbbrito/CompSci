#include <bits/stdc++.h>

using namespace std;

set<int> adjlist[105];
vector<bool> seen;

void dfs(int s)
{
    seen[s] = true;

    for (auto it: adjlist[s])
        if (!seen[it])
            dfs(it);
}

int main()
{
    int n;

    cin >> n;

    while (n)
    {
        int a, b;
        cin >> a;

        while (a)
        {
            cin >> b;
            while (b)
            {
                adjlist[a].insert(b);
                cin >> b;
            }

            cin >> a;
        }

        int amount;
        cin >> amount;

        while (amount--)
        {

            for (int i = 0; i <= 105; i++)
                seen.push_back(false);
            int s;
            cin >> s;

            dfs(*(adjlist[s].begin()));
            
            cout << count(seen.begin() + 1, seen.begin() + n + 1, false);

            for (int i = 1; i <= n; i++)
            {
                if (!seen[i])
                    cout << ' ' << i;
            }
               
            seen.clear(); 
            cout << endl;
        }

        for (int i = 1; i < 105; i++)
            adjlist[i].clear();

        cin >> n;
    }

    return 0;
}