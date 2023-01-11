#include <stdio.h>

 void Merge(int list[], int start, int mid, int end)
 {
    // Build temp array to avoid modyfing normal array
    int temp[end - start + 1];

    int i = start, j = mid + 1, k = 0;

    // While both have values, try to merge in sorted order
    while (i <= mid && j <= end)
    {
        if (list[i] <= list[j])
        {
            temp[k] = list[i];
            i++;
            k++;
        }

        else
        {
            temp[k] = list[j];
            j++;
            k++;
        }
    }

    // Add the rest of the values from left subarray
    while (i <= mid)
    {
        temp[k] = list[i];
        k++;
        i++;
    }

    // Add the rest of the values from right subarray
    while (j <= end)
    {
        temp[k] = list[j];
        j++;
        k++;
    }

    for (i = start; i <= end; i++)
    {
        list[i] = temp[i - start];
    }
 }

 void MergeSort(int list[], int start, int end)
 {
    // While the start point is not the same as the end point
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(list, start, mid);
        MergeSort(list, mid + 1, end);
        Merge(list, start, mid, end);
    }

    return;
 }

 int main()
 {
    int data[] = {-5, 20, 10, 3, 2, 0};

    MergeSort(data, 0, (sizeof(data) / sizeof(data[0])) - 1);

    for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
    {
        printf("%i ", data[i]);
    }
 }