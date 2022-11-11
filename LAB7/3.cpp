// AU2140213 Vanaja Agarwal
// Q3.Implement Heapsort algorithm using Minheap.

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{

    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);

        heapify(arr, n, smallest);
    }
}

void buildheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    buildheap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "\nSorted array is: \n\n";
    printArray(arr, n);
    return 0;
}

// Output:

// Sorted array is:

// 5 6 7 11 12 13