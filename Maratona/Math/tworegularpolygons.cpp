#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t;cin >>t;

    while (t--)
    {
        int n1, n2;cin>>n1>>n2;

        string ans = n1 % n2 == 0 ? "YES\n" : "NO\n";

        cout << ans;
    }
}