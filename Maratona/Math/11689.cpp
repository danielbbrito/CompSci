#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int e, f, c;

        cin >> e >> f >> c;
        int total = 0;
        while (e >= c)
        {
            total += e / c;
            e = e / c + e % c;
        }

        e += f;

        while (e >= c)
        {
            total += e / c;
            e = e / c + e % c;
        }

        cout << total << endl;
    }

    return 0;
}