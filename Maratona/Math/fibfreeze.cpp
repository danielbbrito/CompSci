#include <bits/stdc++.h>
using namespace std;

long long seen[1000000];

long long fib(int n)
{
    if (seen[n] > -1)
    {
        return seen[n];
    }

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return seen[n] = fib(n-1) + fib(n-2);

}

int main()
{
    int n;
    memset(seen, -1, sizeof seen);
    fib(5000);
    while (cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is " << seen[n] << endl;
    }
}