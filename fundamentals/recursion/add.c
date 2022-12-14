/**
 * Adds all decimals up to a specified number with recursion
*/

#include <stdio.h>

int add(int n);

int main(void)
{
    int num;
    scanf("%i", &num);

    printf("%i\n", add(num));

    return 0;
}

int add(int n)
{
    /**
     * What is happening is that it tries to execute it once, 
     * but realizes it depends on another call of itself
     * it repeats the same process until it hits the base case, then all other calls can be returned
     * (recursion is weird, man)
    */
    if (n == 0)
    {
        return n;
    }

    return n + add(n - 1);
}