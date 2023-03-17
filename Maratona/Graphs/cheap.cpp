#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adjlist;

map<string, string> bfs(string s, string e)
{
    vector<bool> seen(1000, false);
    queue<string> q;
    map<string, string> path;

    seen[(int)s[0]] = true;
    q.push(s);

    while (q.size())
    {
        string curr = q.front();
        q.pop();

        if (curr == e)
            return path;

        for (auto it: adjlist[curr])
            if (!seen[(int)it[0]])
            {
                q.push(it);
                seen[(int)it[0]] = true;
                path[it] = curr;
            }
    }

    return path;

}

void printPath(map<string, string> path, string e, string s)
{
    string v = path[e]; //?

    while (v != s)
        printPath(path, v, s);
    
    cout << v << e << endl;
}

int main()
{
    int t;

     while (cin >> t)
     {
        for (int i = 0; i < t; i++)
        {
            string a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        string s, e;
        cin >> s >> e;
        map<string, string> path = bfs(s, e);
        cout << e;
        if (path.find(e) != path.end());
            //printPath(path, e);
        else
            cout << "No route\n";
        adjlist.clear();

     }

     return 0;
}