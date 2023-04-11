#include <bits/stdc++.h>

using namespace std;
map<char, vector<char>> adjlist;
vector<char> candle;

int ct;
bool seen[256];
char trap;

void dfs(char s, char x, int c)
{
    if (ct % c == 0)
    {
        candle.push_back(s);
        seen[s] = true;
    }



    ct++;

    for (auto it: adjlist[s])
    {
        int t = 0;

        if (!seen[it] && it != x)
        {
            t++;
            dfs(it, s, c);
        }

        if (!t)
        {
            trap = it;
            return;
        }
    }
}
int main()
{
    char a, b, buffer;

    cin >> a;

    while (a != '#')
    {
        memset(seen, false, sizeof(seen));

        while (1)
        {
            cin >> buffer >> b;
            while (b != ';' && b != '.')
            {
                adjlist[a].push_back(b);
                cin >> b;
            }

            if (b == '.') break;

            cin >> a;
        }

        char m,s; int c;
        cin >> m >> s >> c;
        ct = 1;

        dfs(m, s, c);

        for (auto it: candle)
            if (it != trap)
                cout << it << ' ';
        
        cout << '/' << trap << endl;

        adjlist.clear();

        cin >> a;
    }

    return 0;
}