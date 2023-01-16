#include <bits/stdc++.h>

using namespace std;

void DividirLista(const string &item, set<string> &items);

int main()
{
    short n;
    set<string> items;

    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++)
    {
        string item;

        getline(cin, item);
        DividirLista(item, items);

        cout << *items.begin();
        for (set<string>::iterator itr = next(items.begin(), 1); itr != items.end(); itr++)
        {
            cout << ' ' << *itr;
        }

        cout << endl;

        items.clear();
    }

    return 0;
}

void DividirLista(const string &item, set<string> &items)
{
    if (item.find(" ") == string::npos)
    {
        items.insert(item);
        return;
    }
    
    items.insert(item.substr(0, item.find(" ")));

    return DividirLista(item.substr(item.find(" ") + 1, item.length()), items);
}