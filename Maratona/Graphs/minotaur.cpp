#include <bits/stdc++.h>

using namespace std;
map<char, set<char>> adjlist;
vector<char> candles;
vector<bool> visited(255, false);
queue<char> seen;
int ct;

void dfs(int s, int k)
{
    visited[s] = true;
    ct++;

    seen.push(s);

    if (ct % k == 0)
        candles.push_back(s);

    for (auto it: adjlist[s])
        if (!visited[it])
            dfs(it, k);

}
int main()
{
    char a;

    cin >> a;

    while (a != '#')
    {
        char buffer, b;
        cin >> buffer >> b;
        while (1)
        {
            while (b != ';' && b != '.')
            {
                adjlist[a].insert(b);
                cin >> b;
            }

            if (b == '.')
                break;
            
            cin >> a >> buffer >> b;
        }

        char t, m;
        int k;
        cin >> m >> t >> k;
        visited[t] = true;
        ct = 0;
        dfs(m, k);
        
        for (int i = 1; seen.size(); i++)
        {
            if (seen.size() == 1)
                cout << '/' << seen.front() << endl;
            
            else if (i % k == 0)
                cout << seen.front() << ' ';
            
            seen.pop();
        }

        adjlist.clear();
        visited.clear();
        candles.clear();

        cin >> a;
    }
}