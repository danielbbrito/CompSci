#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,vector<char>> adjlist;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++)
    {
        string s;

        getline(cin, s);

        for (int i = 0; i < s.length(); i++)
        {
            adjlist[s[i]].push_back(s[i+1]);
            adjlist[s[i+1]]
        }
    }
}