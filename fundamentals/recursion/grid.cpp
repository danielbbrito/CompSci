#include <bits/stdc++.h>
using namespace std;

int GridPath(int n, int m)
{
    // If it is a straight line, return 1
    if (n == 1 || m == 1)
        return 1;

    return GridPath(n, m - 1) + GridPath(n - 1, m);
}

int main()
{
    cout << GridPath(3, 4) << endl;

    return 0;
}