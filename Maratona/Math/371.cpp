#include <bits/stdc++.h>

using namespace std;

vector<long> cycle(long i, long j)
{
    long ct = 0;
    long start = i;
    long max = -1;
    long num;
    int flag = 0;

    while (start <= j)
    {
        while (i != 1 || flag == 0)
        {
            if (i % 2 != 0)
                i = 3 * i + 1;
            else
                i = i / 2;

            ct++;
            flag = 1;
        }

        if (ct > max)
        {
            max = ct;
            num = start;
        }
        ct = 0;
        start++;
        i = start;
        flag = 0;
    }

    return {max, num};
}

int main()
{
    long n, m;
    cin >>n>>m;
    while (n != 0 && m != 0)
    {
        vector<long> ct;
        if (n > m)
            ct = cycle(m, n);
        else
            ct = cycle(n, m);

        cout << "Between " << min(n, m) << " and " << max(n, m) << ", " << ct.back() << " generates the longest sequence of " << ct.front() << " values.\n";

        cin >> n >> m;
    }
    return 0;
}