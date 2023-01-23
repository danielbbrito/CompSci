#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

map<int, set<int>> adjlist;

int bfs(int ini, int fim)
{
    queue<int> q;
    vector<int> dist(12, -1);

    dist[ini] = 0;
    q.push(ini);

    while (q.size())
    {
        int curr = q.front();
        q.pop();

        if (curr == fim)
            return dist[curr];
        
        for (auto v: adjlist[curr])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[curr] + 1;
                q.push(v);
            }
        }
    }

    return -5;
}

int main()
{
    int a, b, n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        adjlist[a].insert(b);
    }

    int ini, fim;

    cin >> ini >> fim;

    cout << bfs(ini, fim) << endl;

    return 0;
}