#include <bits/stdc++.h>

using namespace std;

int main()
{
    string lang, nome, key;
    int n, m;
    
    map<string, string> linguas;
    vector< pair<string, string> > nomes;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, key);
        getline(cin, lang);
        linguas[key] = lang;
    }

    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin, nome);
        getline(cin, key);
        nomes.push_back({key, nome});
    }

    for (int i = 0; i < m; i++)
        cout << nomes[i].second << '\n' << linguas[nomes[i].first] << '\n' << endl;

    return 0;
}