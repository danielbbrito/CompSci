#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m,rounds=0;
        cin >> n >> m;

        while (n >= m)
        {
            rounds++;
            n = n / m + n % m;
        }

        if (n == 1)
            cout << rounds << endl;

        else    cout << "cannot do this\n";
    }

    return 0;
}