#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector< pair<int, int> > vpi;

vpi adjlist[105];
int n;

int mices(int s, int e)
{
    int dist[n + 1];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    
    priority_queue< ii, vpi, greater<ii>> q;

    dist[s] = 0;
    q.push({s, 0});

    while (q.size())
    {
        ii curr = q.top();
        q.pop();

        for (int i = 0; i < adjlist[curr.first].size(); i++)
        {
            ii v = adjlist[curr.first][i];

            if (dist[curr.first] + v.second < dist[v.first])
            {
                dist[v.first] = dist[curr.first] + v.second;
                q.push(v);
            }
        }
    }

    return dist[e];
}
 
int main()
{
    int cases;

    cin >> cases;

    while (cases--)
    {
        int count = 0;

        int t, e, m;

        cin >> n >> e >> t >> m;

        for (int i = 0; i < m; i++)
        {
            int a, b, p;

            cin >> a >> b >> p;

            adjlist[a].push_back({b, p});
        }

        for (int i = 1; i <= n; i++)
            if (mices(i, e) <= t)
                count++;

        cout << count << endl;

        if (cases)
            cout << endl;

        
        for (int i = 0; i < 105; i++)
            adjlist[i].clear();
    }
}