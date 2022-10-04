// Vanaja Agarwal AU2140213
// Implement Selection Sort

#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int num)
{

    // Set the position of the index where the lowest element is to be set.
    for (int i = 0; i < num; i++)
    {
        int low_index = i;

        // Search for the index of the lowest element in the list starting from (i+1).
        for (int j = i + 1; j < num; j++)
        {
            if (arr[j] < arr[low_index])
            {
                low_index = j;
            }
        }

        swap(arr[i], arr[low_index]);
    }
}



int main()
{
    auto start = chrono::steady_clock::now();
    int array[] = {2, 3, 11, 34, 56, 78};

    int arr_len = (sizeof(array) / sizeof(array[0]));
    SelectionSort(array, arr_len);

    for (int i = 0; i < arr_len; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
    auto stop = chrono::steady_clock::now();
    auto diff = stop - start;
    cout << "Time taken: ";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;

}

