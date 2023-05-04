#include <bits/stdc++.h>

using namespace std;
map<int, vector< pair<int, int> > > adjlist;
int n, m;
float ct;
bool seen[505];

void dfs(int b, int s)
{
    seen[s] = true;
    if (b != 0)
        ct += adjlist[b][s].second;

    for (auto it: adjlist[s])
        if (!seen[it.first])
            dfs(s, it.first);
    
    return;
}

int main()
{
    cin >> n >> m;
    int i = 1;

    while (n || m)
    {
        while (m--)
        {
            int a, b, l;
            cin >> a >> b >> l;

            adjlist[a].push_back({b, l});
        }

        ct = 0;

        dfs(0, 1);

        printf("System #%d\nThe last domino falls after %.1f seconds, ", i, ct);



    }

    return 0;
}