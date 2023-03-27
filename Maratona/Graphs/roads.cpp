#include <bits/stdc++.h>

using namespace std;

map<char, vector<char> > adjlist;

void bfs(string s, string e)
{
    vector<bool> seen(255, false);
    queue<string> q;
    q.push(string(1, s[0]));
    seen[(int)s[0]] = true;

    while (q.size())
    {
        string curr = q.front();
        q.pop();

        if (curr.back() == e.front())
            cout << curr << endl;
        
        for (auto it: adjlist[curr.back()])
        {
            if (!seen[(int)it])
            {
                seen[(int)it] = true;
                q.push(curr + it);
            }
        }
    }
}

int main()
{
    int t;
    
    cin >> t;

    while (t--)
    {
        int m, n;
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

            bfs(s, e);
        }

        if (t)
            cout << endl;
        
        adjlist.clear();
    }
}