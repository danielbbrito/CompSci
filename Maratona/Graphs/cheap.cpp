#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> adjlist;
map<string, string> path;

bool bfs(string s, string e, int amount, map<string, int> dist)
{
    queue<string> q;
    
    q.push(s);
    dist[s] = 0;
    path[s] = "";
    while (q.size())
    {
        string curr = q.front();
        q.pop();

        if (curr == e)
            return true;

        for (auto it: adjlist[curr])
            if (dist[it] == -1)
            {
                dist[it] = dist[curr] + 1;
                q.push(it);
                path[it] = curr;
            }
    }

    return false;
}

int main()
{
    int n;

    while (cin >> n)
    {
        map<string, int> dist;
        vector<string> a;

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;

            adjlist[a].insert(b);
            adjlist[b].insert(a);

            dist[a] = -1;
            dist[b] = -1;
        }

        string start, end;

        cin >> start >> end;

        bool success = bfs(start, end, n, dist);

        // Output path
        if (!success)
            cout << "No route\n";
        
        else
        {
            a.push_back(end);

            string c = end;
            while (c != "")
            {
                a.push_back(path[c]);
                c = path[c];
            }
        }

        cout << a.back();
        for (auto it = a.rbegin() + 1; it != a.rend(); it++)
        {
            cout << ' ' << *it;
        }

        cout << endl;
        
        adjlist.clear();
        path.clear();
        dist.clear();
    }

    return 0;
}