// AU2140213 Vanaja Agarwal
// Best and worst cases for selection and insertion sort.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min_ind = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
            {
                min_ind = j;
            }
        }

        swap(arr[i], arr[min_ind]);
    }
}

void insertionSort(int arr[], int n)
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

void print_arr(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr1[] = {12, 45, 67, 78, 89, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {117, 90, 87, 76, 53, 43, 32, 21};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Best case
    cout << "Insertion sort(Best case): " << endl;
    auto start1 = chrono::steady_clock::now();
    insertionSort(arr1, n1);
    auto stop1 = chrono::steady_clock::now();
    auto diff1 = stop1 - start1;
    print_arr(arr1, n1);
    cout << endl;
    cout << "Time taken: ";
    cout << chrono::duration<double, milli>(diff1).count() << " ms" << endl;
    cout << endl;

    cout << "Selection sort(Best case): " << endl;
    auto start2 = chrono::steady_clock::now();
    selectionSort(arr1, n1);
    auto stop2 = chrono::steady_clock::now();
    auto diff2 = stop2 - start2;
    print_arr(arr1, n1);
    cout << endl;
    cout << "Time taken: ";
    cout << chrono::duration<double, milli>(diff2).count() << " ms" << endl;
    cout << endl;

    // Worst case
    cout << "Insertion sort(Worst case): " << endl;
    auto start3 = chrono::steady_clock::now();
    insertionSort(arr2, n2);
    auto stop3 = chrono::steady_clock::now();
    auto diff3 = stop3 - start3;
    print_arr(arr2, n2);
    cout << endl;
    cout << "Time taken: ";
    cout << chrono::duration<double, milli>(diff3).count() << " ms" << endl;
    cout << endl;

    cout << "Selection sort(Worst case): " << endl;
    auto start4 = chrono::steady_clock::now();
    selectionSort(arr2, n2);
    auto stop4 = chrono::steady_clock::now();
    auto diff4 = stop4 - start4;
    print_arr(arr2, n2);
    cout << endl;
    cout << "Time taken: ";
    cout << chrono::duration<double, milli>(diff4).count() << " ms" << endl;
    cout << endl;

    return 0;
}