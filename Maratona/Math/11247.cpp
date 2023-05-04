#include <bits/stdc++.h>

using namespace std;

int main()
{
    float x;
    long m;

    cin >> m >> x;

    while (m || x)
    {
        double n;
        for (long i = m + 1; 1; i++)
        {
            n = i * (x / 100);

            if (n > m)
            {
                cout << n << endl;
                break;
            }
        }

        cin >> m >> x;
    }

    return 0;
}