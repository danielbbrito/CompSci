#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    while (cin >> n >> m)
    {
        int ct = 0;
        for (int i = n; i <= m; i++)
        {
            string s = to_string(i);
            
            set<char> n;
            for (int j = 0; j < s.length(); j++)
                n.insert(s[j]);
            if (s.size() == n.size())
                ct++;
        }

        cout << ct << endl;
    }

    return 0;
}