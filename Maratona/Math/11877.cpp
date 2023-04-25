#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    while (n)
    {
        int b = 0;
        while (n >= 3)
        {
            b+=n/3;
            n = n / 3 + n % 3;
        }

        if (n == 2) b++;

        cout << b << endl;
        cin >> n;
    }

    return 0;
}