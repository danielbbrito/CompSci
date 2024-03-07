#include <bits/stdc++.h>

using namespace std;

#define int long long


int32_t main()
{
    string abc;
    getline(cin, abc);

    for (int i = 1; i < abc.length(); i++)
    {
        if (abc[i - 1] != abc[i])
        {
            if (abc[i] != abc[i-1] + 1 || abc[i] != abc[i-1] + 2)
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}