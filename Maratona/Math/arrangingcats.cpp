#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;cin>>t;

    while (t--)
    {
        int needs_cat = 0;
        int has_cat = 0;

        int n;cin>>n;

        cin.ignore();
        string a,b;
        getline(cin, a);getline(cin,b);

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (b[i] == '0')
                    needs_cat++;
                else has_cat++;
            }
        }

        cout << max(has_cat, needs_cat) << endl;
    }

    return 0;
}