#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, p, m, n;
    int tp=0, tm=0;
    cin >> n;

    while (n--)
    {
        cin >> a;

        if (a==1)
            tp++;
        else tm++;
    }

    cin >> p >> m;

    if (tp == p && tm == m)
        cout << 'S' << endl;
    
    else cout << 'N' << endl;
}