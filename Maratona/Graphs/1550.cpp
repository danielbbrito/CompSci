#include <bits/stdc++.h>

using namespace std;
#define INF -1

int inverte(int i)
{
    int inv = 0;
    while (i != 0)
    {
        inv = inv * 10 + i % 10;
        i /= 10;
    }

    return inv;
}

int bfs(int ini, int end)
{
    vector<int> dist(10100, __INT_MAX__);
    queue<int> q;

    dist[ini] = 0;
    q.push(ini);

    while (q.size())
    {
        int curr = q.front();
        q.pop();

        if (curr == end)
            return dist[curr];
        
        if (curr + 1 <= 10010 && dist[curr + 1] == __INT_MAX__)
        {
            int v = curr + 1;
            
            q.push(v);

            dist[v] = dist[curr] + 1;
        }

        if (inverte(curr) <= 10010 && dist[inverte(curr)] == __INT_MAX__)
        {
            int v = inverte(curr);
            
            q.push(v);

            dist[v] = dist[curr] + 1;
        }
    }

    return -5;
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int a, b;

        cin >> a >> b;
        
        cout << bfs(a, b) << endl;
    }

    return 0;
}