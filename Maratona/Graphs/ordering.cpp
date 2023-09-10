#include <bits/stdc++.h>

using namespace std;
vector<pair<char, char>> constraints;
vector<char> variables;
set<string> results;
bool seen[255];

bool valid(char curr, string ts)
{
    // Iterate over list of constraints
    for (auto it: constraints)
    {
        if (it.first == curr)
        {
            for (int i = 0; i < ts.length(); i++)
                if (it.second == ts[i])
                    return false;
        }
    }

    return true;
}

void toposort(char s, string ts)
{
    ts += s;
    
    if (ts.length() == variables.size())
    {
        results.insert(ts);
    }

    for (auto it: variables)
    {
        if (ts.find(it) == string::npos)
        {
            if (valid(it, ts))
                toposort(it, ts);
        }
    }

    return;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        results.clear();
        variables.clear();
        constraints.clear();
        string vars;
        
        getline(cin, vars);
        
        while (vars.empty())
            getline(cin, vars);
            
        for (int i = 0; i < vars.length(); i++)
            if (vars[i] != ' ')
                variables.push_back(vars[i]);

        string cons;
        getline(cin, cons);
        for (int i = 0; i <= cons.length();i++)
            if (cons[i] == ' ' || cons[i] == '\0')
                constraints.push_back({cons[i-3],cons[i-1]});

        
        for (auto it: variables)
            toposort(it, "");
        
        if (results.size())
        {
            for (auto it: results)
            {
                cout << it[0];
                for (int i = 1; i < it.length(); i++)
                    cout << " " << it[i];
                cout << '\n';
            }
        }
        
        else cout << "NO\n";
            
        if (n)
            cout << '\n';
    }

    return 0;
}