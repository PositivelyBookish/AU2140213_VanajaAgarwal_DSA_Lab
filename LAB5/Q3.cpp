// AU2140213 Vanaja Agarwal 
// Implement Insertion Sort with the help of binary search. (Compare timings of linear vs binary insertion sort)

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int bSearch(int arr[], int x, int low, int high)
{
    if (high <= low)
        return (x > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (x == arr[mid])
        return mid + 1;

    if (x > arr[mid])
        return bSearch(arr, x, mid + 1, high);

    return bSearch(arr, x, low, mid - 1);
}

void BinInsertionSort(int arr[], int num)
{
    for (int i = 1; i < num; ++i)
    {
        int j = i - 1;
        int key = arr[i];
        int pos = bSearch(arr, key, 0, j);
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void linearInsertionSort(int arr[], int num)
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

void print_arr(int arr[], int arr_len){
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int array1[] = {22,1,56,123,89,657,34};

    int arr_len1 = (sizeof(array1) / sizeof(array1[0]));
    auto start1 = chrono::steady_clock::now();
    BinInsertionSort(array1, arr_len1);
    print_arr(array1, arr_len1);
	auto stop1 = chrono::steady_clock::now();
	auto diff1 = stop1 - start1;
    cout << "\n";
	cout<<"Time taken(Binary Insertion Sort): ";
	cout << chrono::duration <double, milli> (diff1).count() << " ms" << endl;
	cout<<endl;

    int array2[] = {22,1,56,123,89,657,34};

    int arr_len2 = (sizeof(array2) / sizeof(array2[0]));

    auto start2 = chrono::steady_clock::now();
    linearInsertionSort(array2, arr_len2);
    print_arr(array2, arr_len2);
	auto stop2 = chrono::steady_clock::now();
	auto diff2 = stop2 - start2;
    cout << "\n";
	cout<<"Time taken(Linear Insertion Sort): ";
	cout << chrono::duration <float, milli> (diff1).count() << " ms" << endl;
	cout<<endl;

    return 0;

}