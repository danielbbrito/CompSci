#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while (t--)
    {
        int n, m;cin>> n>>m;
        m = ceil(m / 2);

        cout << n * m << endl;
    }
}