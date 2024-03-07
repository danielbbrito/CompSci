#include <bits/stdc++.h>
using namespace std;

#define int long long


int32_t main()
{
    int n;
    int MOD = pow(10, 9) + 7;
    while (n--)
    {
        int a, b;cin>>a>>b;

        int pw = (int)pow(a % MOD, b);
        cout << pw % MOD << endl;
    }
}