/*
 * Implement a binary search algorithm that uses recursion
*/
#include <stdio.h>

int binary_search(int *list, int start, int end, int n)
{
    // If starting point is greater than end point, n is not in list
    if (start > end)
        return -1;

    // Calculate mid point
    int mid = (end + start) / 2;

    // If n is in mid point, the item has been found
    if (n == list[mid])
        return mid;

    // If n is after the mid point, update starting point
    else if (n > list[mid])
        return binary_search(list, mid + 1, end, n);

    // Else update end point
    return binary_search(list, start, mid - 1, n);
}

int main(void)
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Pos: %i\n", binary_search(A, 0, 9, 1));

    return 0;
}