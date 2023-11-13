#include <bits/stdc++.h>

using namespace std;
const int UNVISITED = 0;
const int VISITED = 1;
bool cycle = false;
vector<int> adjlist[100005];
int n, m;
bool seen[100005];
stack<int> sorted;
void cyclecheck(int u)
{
    seen[u] = VISITED;

    for (auto it: adjlist[u])
    {
        if (seen[u] == UNVISITED)
            cyclecheck(it);
        else
        {
            cycle = true;
            return;
        }
    }
}

void toposort(int s)
{
    seen[s] = true;

    for (auto it: adjlist[s])
    {
        if (!seen[it])
            toposort(it);
    }

    sorted.push(s);
}
int main()
{
    cin >> n >> m;
    int start;
    while (m--)
    {
        int a, b;cin>>a>>b;
        adjlist[a].push_back(b);
        start = a;
    }

    cyclecheck(1);
    if (cycle)
    {
        cout << -1<< endl;
        return 0;
    }

    memset(seen, false, sizeof seen);
    toposort(start);

    cout << sorted.top();
    sorted.pop();

    while (sorted.size())
    {
        cout << ' ' << sorted.top();
        sorted.pop();
    }

    cout << endl;
}