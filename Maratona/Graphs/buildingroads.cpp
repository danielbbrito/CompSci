#include <bits/stdc++.h>
using namespace std;

int n, m;

set<int> al[200005];
int roads[100005];
bool seen[100005];

void dfs(int i)
{
    seen[i] = true;

    for (auto it: al[i])
    {
        if (!seen[it])
            dfs(it);
    }
}
int main()
{
    cin >> n >> m;

    while (m--)
    {
        int a, b;cin>>a>>b;
        al[a].insert(b);
        al[b].insert(a);
    }
    int count = 0;
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!seen[i])
        {
            count++;
            roads[j] = i; j++;
            dfs(i);
        }
    }

    cout << count - 1 << endl;

    for (int i = 1; roads[i] != 0; i++)
    {
        cout << roads[i - 1] << ' ' << roads[i] << endl;
    }

}