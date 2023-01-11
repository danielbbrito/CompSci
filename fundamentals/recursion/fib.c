/**
 * Implements fibonacci's sequence using recursion
 */
#include <stdio.h>

long fib(long n)
{
    if (n == 0 || n == 1)
        return n;
    
    else return fib(n - 1) + fib(n - 2); 
}

int main()
{
    printf("%li\n", fib(100));

    return 0;
}