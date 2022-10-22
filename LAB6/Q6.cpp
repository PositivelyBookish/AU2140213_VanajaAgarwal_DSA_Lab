// AU2140213 VANAJA BINAY AGARWAL
// Q6.

#include <bits/stdc++.h>
using namespace std;
void createhash(int array1[], int array2[][10], int sizeofArray)
{
    int key;
    for (int i = 0; i < sizeofArray; i++)
    {
        key = array1[i] % 10;
        if (array2[key][0] == -1)
        {
            array2[key][0] = array1[i];
        }
        else
        {
            for (int j = 1; j < 10; j++)
            {
                if (array2[key][j] == -1)
                {
                    array2[key][j] = array1[i];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << array2[i][j] << " ";
        }
        cout << "\n";
    }
}

void searchhash(int arr[], int arr2[][10], int size, int ele)
{
    int nu;
    nu = ele % 10;
    if (arr2[nu][0] == ele)
    {
        cout << "Row: " << nu << " " << "\nColumn: " << 0;
    }
    else
    {
        for (int j = 1; j < 10; j++)
        {
            if (arr2[nu][j] == ele)
            {
                cout << "Row: " << nu << " " << "\nColumn: " << j;
                break;
            }
        }
    }
}

int main()
{
    int sizeofArray, element;
    cout << "Enter size of Array: ";
    cin >> sizeofArray;

    int Array[sizeofArray];
    cout << "\nEnter elements: " << endl;
    for (int i = 0; i < sizeofArray; i++)
    {
        cin >> Array[i];
    }

    int Array2[10][10];
    cout << "\n\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Array2[i][j] = -1;
        }
    }
    createhash(Array, Array2, sizeofArray);

    cout << "\n\nEnter element to be searched: ";
    cin >> element;
    searchhash(Array, Array2, sizeofArray, element);
    return 0;
}
