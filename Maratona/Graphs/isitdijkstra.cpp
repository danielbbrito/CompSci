#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
#define int long long
#define MAX LLONG_MAX
set<ii> adjlist[100005];
int n,m;

void ppath(int path[], int i)
{
    if (path[i] == i)
    {
        cout << i;
        return;
    }
    
    ppath(path, path[i]);
    
    cout << ' ' << i; 
}
void dijkstra()
{
    vector<int> dist(n + 1, MAX);
    int path[n + 1];
    
    for (int i = 1; i <= n; i++)
        path[i] = i;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    while (pq.size())
    {
        ii curr = pq.top();pq.pop();
        
        if (curr.second == n)
        {
            ppath(path, n);
            return;
        }
        
        for (auto it: adjlist[curr.second])
        {
            if (dist[it.second] > dist[curr.second] + it.first)
            {
                dist[it.second] = dist[curr.second] + it.first;
                pq.push({dist[it.second], it.second});
                path[it.second] = curr.second;
            }
        }
    }
    cout << -1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    while (m--)
    {
        int a,b,w;cin>>a>>b>>w;
        
        adjlist[a].insert({w, b});
        adjlist[b].insert({w, a});
    }
    
    dijkstra();
    cout << endl;
}