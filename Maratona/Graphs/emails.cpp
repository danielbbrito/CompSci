#include <iostream>
#include <set>
#include <map>

using namespace std;

set<int> adjlist[50001];
bool seen[50001];
map<int, int> possible;

int count;

void dfs(int i)
{
    seen[i] = true;
    ::count++;

    for (auto it: adjlist[i])
        if (!seen[it])
            dfs(it);
}

int main()
{
    int t;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            adjlist[j].clear();
            seen[j] = false;
        }

        for (int j = 0; j < n; j++)
        {
            int a, b;

            cin >> a >> b;

            adjlist[a].insert(b);
        }

        for (int j = 1; j <= n; j++)
        {
            if (!seen[j])
            {
                ::count = 0;
                dfs(j);
            }
            
            possible[::count] = possible.find(::count) != possible.end()  || possible[::count] > j ? possible[::count] = j : possible[::count];
        }

        cout << "Case #" << i << ": " << (possible.rbegin())->second << endl;
    }

    return 0;
}