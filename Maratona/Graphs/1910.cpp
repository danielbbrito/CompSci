#include <bits/stdc++.h>

using namespace std;

int bfs(int s, int e, vector<int> p)
{
    vector<int> dist(100100, 0);
    queue<int> q;
    q.push(s);

    while (q.size())
    {
        int curr = q.front();
        q.pop();

        if (curr == e)
            return dist[curr];
        
        if (curr + 1 <= 100000 && dist[curr + 1] == __INT_MAX__)
        {
            int v = curr + 1;
            dist[v] = dist[curr] + 1;
            q.push(v);
        }

        if (curr - 1 <= 100000 && dist[curr - 1] == __INT_MAX__)
        {
            int v = curr - 1;
            dist[v] = dist[curr] + 1;

            q.push(v);
        }

        if (curr * 2 <= 100000 && dist[curr * 2] == __INT_MAX__)
        {
            int v = curr * 2;
            dist[v] = dist[curr] + 1;

            q.push(v);
        }

        if (curr * 3 <= 100000 && dist[curr * 3] == __INT_MAX__)
        {
            int v = curr * 3;
            dist[v] = dist[curr] + 1;

            q.push(v);
        }

        if (curr / 2 <= 100000 && dist[curr/2] == __INT_MAX__)
        {
            int v = curr / 2;
            dist[v] = dist[curr] + 1;

            q.push(v);
        }
    }

    return -5;
}

int main()
{
    int o, d, k;

    cin >> o >> d >> k;

    while (o != 0 && d != 0 && k != 0)
    {
        vector<int> prohibited;
        prohibited.clear();

        for (int i = 0; i < k; i++)
        {
            int p;
            cin >> p;
            prohibited.push_back(p);
        }

        cout << bfs(0, d, prohibited) << endl;
    }

    return 0;
}
