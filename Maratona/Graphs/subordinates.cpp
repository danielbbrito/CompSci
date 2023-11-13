#include <bits/stdc++.h>

using namespace std;
vector<int> adjlist[200005];
vector<int>subordinates(200005,0);
int n, ct;
bool seen[200005];
void solve(int s)
{
    seen[s] = true;
    
    for (auto it: adjlist[s])
    {
        if (!seen[it])
        {
            solve(it);
            subordinates[s] += subordinates[it] + 1;
        }
    }
}
int main()
{
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int a;cin>>a;

        adjlist[a].push_back(i);
    }

    solve(1);

    cout << subordinates[1];

    for (int i = 2; i <= n; i++)
        cout << " " << subordinates[i];

    cout << endl;
}