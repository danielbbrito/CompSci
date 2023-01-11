#include <bits/stdc++.h>

int sum(int n)
{
    if (n == 0)
    {
        return n;
    }

    return n + sum(n - 1);
}

int main()
{
    std::cout << sum(5) << std::endl;

    return 0;
}