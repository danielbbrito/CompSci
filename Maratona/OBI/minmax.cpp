#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, a, b;


    cin >> s >> a >> b;

    int min = b, max = a;

    for (int i = a; i <= b; i++)
    {
        int a1 = 0, a2 = i;

        while (a2 > 0)
        {
            a1 += a2 % 10;
            a2 /= 10;
        }

        if (a1 == s)
        {
            if (i < min)
                min = i;
            if (i > max)
                max = i;
        }
    }

    cout << min << endl << max << endl;
}