#include <bits/stdc++.h>

using namespace std;

bool seen[1001];
set<int> adjlist[1001];
set<int> shooter;
double p;
double prob = 1.0;

void dfs(int s, int e)
{
    seen[s] = true;
    if (shooter.find(s) != shooter.end())
        prob *= p;
    
    if (s == e)
        return;

    for (auto it: adjlist[s])
        if (!seen[it])
            dfs(it, e);
    
    return;
}

int main()
{
    int n, m, k;

    while (cin >> n >> m >> k >> p)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adjlist[a].insert(b);
        }

        int A;
        for (int i = 0; i < A; i++)
        {
            int pos;
            cin >> pos;
            shooter.insert(pos);
        }

        int s, e;

        cin >> s >> e;

        dfs(s, e);

        cout << fixed << setprecision(3) << prob << endl;
    }

    return 0;
}