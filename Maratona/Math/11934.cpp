#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, l;
    cin >> a >> b >> c >> d >> l;

    while (a||b||c||d||l)
    {
        int q = 0;
        for (int i = 0; i <= l; i++)
        {
            int val = a * (i * i) + b * i + c;

            if (val % d == 0)
                q++;
        }

        cout << q << endl;
        cin >> a >> b >> c >> d >> l;
    }

    return 0;
}