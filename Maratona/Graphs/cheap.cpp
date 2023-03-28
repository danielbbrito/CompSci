#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adjlist;

void bfs(string s, string e)
{
    map<string, bool> seen;
    for (auto it: adjlist)
        seen[it.first] = false;

    queue<vector<string>> q;

    seen[s] = true;

    q.push({s});

    while(q.size())
    {
       vector<string> curr = q.front();
       q.pop();

       if (curr.back() == e)
       {
            for (int i = 0; i < curr.size() - 1; i++)
                cout << curr[i] << ' ' << curr[i + 1] << endl;
                
            
            return;
       }

       for (auto it: adjlist[curr.back()])
            if (!seen[it])
            {
                seen[it] = true;
                vector<string> next = curr;
                next.push_back(it);

                q.push(next);
            }

    }

    cout << "No route\n";
    return;
    
}

int main()
{
    int n;

    while (cin >> n)
    {
        while (n--)
        {
            string a, b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        string s, e;
        cin >> s >> e;

        bfs(s, e);

        cout << endl;
        adjlist.clear();
    }

    return 0;
}