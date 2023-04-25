#include <bits/stdc++.h>

using namespace std;

int cycle(int i, int j)
{
    int ct = 0;
    int start = i;
    int max = 0;
    while (start <= j)
    {
        while (i != 1)
        {
            if (i%2!=0)
                    i = 3*i + 1;
            else i=i/2;

            ct++;
        }

        if (ct > max)
            max = ct;
        ct = 0;
        start++;
        i = start;
    }

    return max + 1;
    
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int ct;
        if (n > m)
            ct = cycle(m, n);
        else
            ct = cycle(n, m);

        cout << n << ' ' << m << ' ' << ct << endl;
    }
    return 0;
}