#include <bits/stdc++.h>

using namespace std;
set<int> al[200005];
int seen[200005];
vector<int> order;

void toposort(int s)
{
    seen[s] = 1;

    for (auto it: al[s])
    {
        if (!seen[it])
            toposort(it);
    }

    order.push_back(s);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;

        for (int j = 1; j <= c; j++)
        {
            int b;cin>>b;
            al[i].insert(b);
        }
    }

    toposort(1);

    cout << order.front();

    for (int i = 1; i < (int)order.size() - 1; i++)
    {
        cout << ' ' << order[i];
    }

    cout << endl;
}