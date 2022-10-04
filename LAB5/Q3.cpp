// Vanaja Agarwal AU2140213
// Implement Insertion Sort with the help of binary search.

#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int num)
{

    for (int i = 1; i < num; i++)
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

int main()
{

    int arr[] = {50, 20, 40, 60, 10, 30};

    int arr_len = (sizeof(arr) / sizeof(arr[0]));
    insertionSort(arr, arr_len);

    for (auto x : arr)
        cout << x << " ";
}