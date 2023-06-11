#include <bits/stdc++.h>

using namespace std;

map<int, vector<char>> adjlist;
vector<char> minotaur;
vector<char> theseus;
bool seen[255];

void dfs(char t, char m, int k, int ct)
{
    if (ct > 1 && ct % k == 0)
    {
        cout << t << ' ';
        seen[t] = true;
    }

    for (auto it : adjlist[m])
        if (!seen[it] && it != theseus.back())
        {
            theseus.push_back(m);
            minotaur.push_back(it);
            dfs(m, it, k, ct + 1);
        }

    return;
}

int main()
{
    char a, b;

    cin >> a;

    while (a != '#')
    {
        cin >> b;
        int flag = 1;
        while (flag)
        {
            if (b != '.')
                cin >> b;
                
            while (b != ';' && b != '.')
            {
                adjlist[a].push_back(b);
                cin >> b;
            }
            if (b != '.')
                cin >> a >> b;
            else
                flag = 0;
        }

        char t, m;
        int k;

        cin >> m >> t >> k;

        memset(seen, false, sizeof(seen));
        theseus.push_back(t);
        dfs(t, m, k, 0);

        cout << '/' << minotaur.back() << endl;
        minotaur.clear();
        theseus.clear();
        adjlist.clear();

        cin >> a;
    }

    return 0;
}