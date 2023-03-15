#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> adjlist;

map<char, char> bfs(char s, char e)
{
    map<char, bool> seen;
    map<char, char> path;
    queue<char> q;
    q.push(s);
    seen[s] = true;
    path[s] = '\0';

    while (q.size())
    {
        char curr = q.front();
        q.pop();

        if (curr == e)
            return path;

        for (auto it: adjlist[curr])
        {
            if (seen.find(it) == seen.end())
            {
                seen[it] = true;
                path[it] = curr;
                q.push(it);
            }
        }
    }

    return path;
}

void printPath(map<char, char> p, char e)
{
    char c = p[e];

    if (c != e)
        printPath(p, c);
    
    cout << e;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n,m;
        cin >> m >> n;

        while (m--)
        {
            string a, b;
            cin >> a >> b;
            adjlist[a[0]].push_back(b[0]);
            adjlist[b[0]].push_back(a[0]);
        }

        while (n--)
        {

            string s, e;
            cin >> s >> e;

            map<char, char> path = bfs(s[0], e[0]);

            // Reconstruir caminho
            printPath(path, e[0]);
            
            cout << endl;
        }    

        adjlist.clear();
        if (t)
            cout << endl;
    }
    
    return 0;
}