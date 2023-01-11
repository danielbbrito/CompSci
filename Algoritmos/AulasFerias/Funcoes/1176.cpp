#include <bits/stdc++.h>

using namespace std;

unsigned long long Fib(int n)
{
    vector<unsigned long long> fib{0, 1};

    for (int i = 0; i <= n; i++)
    {
        fib.push_back(fib[0 + i] + fib[1 + i]);
    }

    return fib.at(n);
}

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << "Fib(" << n << ") = " << Fib(n) << endl;
    }

    return 0;
}