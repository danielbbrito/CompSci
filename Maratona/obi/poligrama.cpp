#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> palavra;
    map<char, int> ct;
    map<char, int> ct2;
    int n;
    cin >> n;

    while (n--)
    {
        char c;
        cin >> c;

        if (ct.find(c) == ct.end())
            ct[c] = 0;
        
        else
            ct[c]++;
    }

    int v = ct.begin()->second;
    bool flag = true;
    for (auto it: ct)
    {
        if (it.second != v)
        {
            flag = false;
            break;
        }

        ct2[it.first] = 0;
    }
    
    if (!flag)
        cout << '*' << endl;
    else
    {
        
    }
}