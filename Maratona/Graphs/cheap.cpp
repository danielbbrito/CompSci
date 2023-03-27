#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> adjlist;

void bfs(string s, string e)
{
    map<string, bool> seen;
    for (auto it: adjlist)
        seen[it.first] = false;

    queue<vector<pair<string, string>>> q;

    seen[s] = true;
    seen[adjlist[s].front()] = true;

    q.push({{s, adjlist[s].front()}});

    while(q.size())
    {
       vector<pair<string, string>> curr = q.front();
       q.pop();

       if (curr.back().second == e)
       {
            for (int i = 0; i < curr.size(); i++)
                cout << curr[i].first << ' ' << curr[i].second << endl;
            
            return;
       }

       for (auto it: adjlist[curr.back().second])
            if (!seen[it])
            {
                seen[it] = true;
                curr.push_back({curr.back().second, it});

                q.push(curr);
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
}