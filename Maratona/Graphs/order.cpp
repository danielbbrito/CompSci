#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> al;
set<string> results;

void toposort(char s, string ts)
{
    ts += ' ' + s;

    if (ts.length() == al.size())
    {
        results.insert(ts);
    }
    for (auto it: al[s])
    {
        if (ts.find(it) == string::npos)
        {
            toposort(it, ts);
        }
    }
}
int main()
{
    int t;cin>>t;
    cin.ignore();
    while (t--)
    {
        string vars;
        getline(cin, vars);

        while (vars.empty())
            getline(cin, vars);

        for (auto it: vars)
        {
            al[it] = vector<char>();
        }

        string cond;
        getline(cin, cond);

        for (int i = 0; i < cond.length(); i++)
        {
            if (cond[i] == ' ' || cond[i] == '\0')
                al[cond[i - 3]].push_back(cond[i - 1]);
        }

        for (int i = 0; i < vars.length(); i++)
        {
            toposort(vars[i], "");
        }

        if (results.size())
        {
            for (auto it: results)
            {
                for (int i = 1; i < it.length(); i++)
                {
                    cout << it;
                }

                cout << endl;
            }
        }

        else cout << "NO\n";

        if (t) cout << endl;
        al.clear();
        results.clear();
    }
}