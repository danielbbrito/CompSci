#include <iostream>

using namespace std;

void selectionSort(int arr[])
{
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[]) // CLRS page 19
{
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}