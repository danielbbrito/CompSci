#include <bits/stdc++.h>

using namespace std;
int n, m;
int indeg[200005];
set<int> al[200005];
vector<int> order;

void toposort()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (!indeg[i]) pq.push(i);
    }

    while (pq.size())
    {
        int u = pq.top(); pq.pop();
        order.push_back(u);

        for (auto it: al[u])
        {
            --indeg[it];

            if (indeg[it] > 0) continue;

            pq.push(it);
        }
    }
}

int main()
{
    cin>>n>>m;

    while (m--)
    {
        int a, b;cin>>a>>b;
        indeg[b]++;
        al[a].insert(b);
    }
    toposort();
    if (order.size() != n)
    {
        cout << -1;
    }
    
    else
    {
        cout << order.front();
    
        for (int i = 1; i < (int)order.size(); i++)
        {
            cout << ' ' << order[i];
        }
    }

    cout << endl;

}