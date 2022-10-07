//  AU2140213 Vanaja Agarwal
// Implementation of Optimised Bubble Sort

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int arr_len)
{
    // Setting a boolean type value to check if there occurs any changes(or passes) in a particullar round.
    bool swapped;

    // Parsing the array.
    for (int i = 0; i < arr_len; i++)
    {
        // Setting the boolean value to default false in case there are no exchanges.
        swapped = false;

        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Break the loop as the array is sorted because there are no exchanges in a particular round.
        if (swapped == false)
            break;
    }
}

int main()
{
    int array[] = {19, 34, 54, 77, 89, 12, 123};
    int arr_len = (sizeof(array) / sizeof(array[0]));

    bubbleSort(array, arr_len);

    for (int i = 0; i < arr_len; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}