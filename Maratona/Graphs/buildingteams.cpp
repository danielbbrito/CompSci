#include <bits/stdc++.h>
using namespace std;
int color[100005];
vector<int> adjlist[100005];

bool dfs(int s)
{
    for (auto it: adjlist[s])
    {
        if (color[it] == -1)
        {
            color[it] = abs(color[s] - 1);
            if (!dfs(it)) return false;
        }

        else if (color[s] == color[it])
        {
            return false;
        }

    }

    return true;
}
int main()
{
    memset(color, -1, sizeof color);
    int n,m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }


    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!dfs(i))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    cout << color[1] + 1;
    for (int i = 2; i <= n; i++)
        cout << ' ' << color[i] + 1;
    cout << endl;

}
