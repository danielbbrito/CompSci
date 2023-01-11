#include <bits/stdc++.h>
using namespace std;

long fat(long n)
{
    if (n == 1)
    {
        return n;
    }

    return n * fat(n - 1);
}

int main()
{
    long n;

    cin >> n;

    cout << fat(n) << endl;

    return 0;
}