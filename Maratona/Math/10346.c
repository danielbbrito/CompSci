#include <stdio.h>

int calculate(int n, int k, int count, int rem)
{
    if (rem / k >= 1)
    {
        n += rem / k;
        rem = rem % k;
    }

    if (!n)
    {
        return count;
    }

    calculate(n / k, k, count + n, rem + n % k);
}

int main()
{
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF)
    {
        printf("%d\n", calculate(n, k, 0, 0));
    }

    return 0;
}