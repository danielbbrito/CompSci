#include <iostream>
#include <vector>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) // CLRS page 19
{
    for (int i = 1; i < n; i++)
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

void bubbleSort(int arr[], int n)
{
    bool sorted = false;
    
    for (int i = 0; i < n - 1 && !sorted; i++)
    {
        sorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
    }
}

void merge(int *arr, int l, int m, int r)
{
    // Create temp arrays
    int sizeA = m - l + 1;
    int sizeB = r - m;
    int A[sizeA];
    int B[sizeB];

    for (int i = 0; i < sizeA; i++)
        A[i] = arr[l + i];

    for (int i = 0; i < sizeB; i++)
        B[i] = arr[m + 1 + i];

    // Perform merge
    int i = 0;
    int j = 0;
    int k = l;

    while (i < sizeA && j < sizeB)
    {
        if (A[i] <= B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else
        {
            arr[k] = B[j];
            j++;
        }

        k++;
    }

    while (i < sizeA)
    {
        arr[k] = A[i];
        i++;
        k++;
    }

    while (j < sizeB)
    {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) // Where l is the leftmost index and r is the rightmost index
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}


int partition(int arr[], int l, int r)
{
    int x = arr[r]; // Pivot

    int i = l - 1; // Initial greater index for the low side (not an actual index in the array, since the low side has 0 elements initially) 

    for (int j = l; j < r; j++)
    {
        if (arr[j] <= x) // Does arr[j] belong on the low side?
        { // If so, increment i so that it stores the appropriate index for the new size of the low side
            ++i;
            swap(arr[i], arr[j]); // Then, put arr[j] on the low side by swapping it with the element at i, which definitely belongs in the high side
        }
    }

    // Place the pivot exactly between the low and high sides
    swap(arr[i + 1], arr[r]);

    // Return the pivot's index
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Find the pivot for the subarray and place it in its appropriate place
        int q = partition(arr, l, r);

        // Recusively sort
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}


int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    quickSort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);

    cout << "{" << arr[0];
    for (int i = 1; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << ", " << arr[i];
    }

    cout << "}" << endl;

    return 0;
}