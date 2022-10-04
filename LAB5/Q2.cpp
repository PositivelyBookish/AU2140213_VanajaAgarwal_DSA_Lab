// Vanaja Agarwal AU2140213
// Implement Selection Sort

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int num)
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
    int array[] = {23, 75, 11, 34, 56, 78};

    int arr_len = (sizeof(array) / sizeof(array[0]));
    selectionSort(array, arr_len);

    for (int i = 0; i < arr_len; i++)
    {
        cout << array[i] << " ";
    }

    return 0;

}

