#include <bits/stdc++.h>
using namespace std;

#define int long long

// Took me a while to realize bfs could be used
//did not pay attention to the fact that we simply need to compute the shortest distance
int bfs(int n, int m)
{
    vector<int> dist(1000000, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while (q.size())
    {
        int curr = q.front();q.pop();
        
        if (curr == m) return dist[curr];
        
        // Try minus 1
        if (dist[curr - 1] == -1 || dist[curr - 1] > dist[curr] + 1)
        {
            q.push(curr - 1);
            dist[curr - 1] = dist[curr] + 1;
        }
        
        if (dist[curr * 2] == -1 || dist[curr * 2] > dist[curr] + 1)
        {
            q.push(curr * 2);
            dist[curr * 2] = dist[curr] + 1;
        }
    }
    
    return -1;
}

int32_t main()
{
    int n,m;cin >> n >> m;
    int ans = bfs(n, m);
    
    cout << ans << endl;
}