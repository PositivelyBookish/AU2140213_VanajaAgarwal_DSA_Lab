// AU2140213 Vanaja Agarwal
// Implementation of Merge Sort

#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    
    // Dividing the main array into two parts (from mid to leftmost part and from mid to rightmost part).
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];

    // Sorting the two divided arrays .
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + low];

    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Comparing the two arrays and adding them to the main array using the kth index.
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];

        else
            arr[k++] = right[j++];
    }

    // Adding the remaining elements if there are any which are already sorted.
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int r)
{
    if (r > low)
    {
        int mid = low + (r - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, low, mid, r);
    }
}

int main()
{

    int array[] = {10, 5, 30, 15, 7, 89, 91};
    int left = 0, right = (sizeof(array)/sizeof(int))-1;

    mergeSort(array, left, right);
    for (int x : array)
        cout << x << " ";
}