//AU2140213 VANAJA BINAY AGARWAL
//Q4.


#include <bits/stdc++.h>
using namespace std;

// Function to fill the array elements into a hash table
// using Linear Probing to handle collisions.
vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
{
    vector<int> hash(hashSize);
    for (int i = 0; i < hashSize; i++)
        hash[i] = 0;

    for (int i = 0; i < sizeOfArray; i++)
    {
        int k = (arr[i]) % hashSize;
        if (hash[k] == -1)
        {
            hash[k] = 1;
        }
        else
        {
            int count = 0;
            int flag = 0;
            while (count < hashSize && hash[k] != 0)
            {
                if (hash[k] == 1)
                {
                    flag = 1;
                    break;
                }
                k = (k + 1) % hashSize;
                count++;
            }
            if (flag == 1)
                continue;
            if (count < hashSize)
                hash[k] = 1;
        }
    }
    return hash;
}

bool search(vector<int> arr, int key)
{
    int h = key % (arr.size());
    int i = h;
    while (arr[i] != 0)
    {
        if (arr[i] == 1)
            return true;
        i = (i + 1) % (arr.size());
        if (i == h)
            return false;
    }
    return false;
}

int main()
{
    int hashSize;
    cout << "Test Case 1: " << endl;
    int hashSize1 = 17;
    int sizeOfArray = 5;
    int Array[] = {133, 88, 92, 221, 174};
    vector<int> res1 = linearProbing(hashSize1, Array, sizeOfArray);
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1.at(i) << " ";
    }
    cout << endl;

    if (search(res1, 100) == true)
    {
        cout << "100 is Present!" << endl;
    }

    else
    {
        cout << "100 is Not Present!" << endl;
    }

    if (search(res1, 174) == true)
    {
        cout << "174 is Present!" << endl;
    }
    else
    {
        cout << "174 is Not Present!" << endl;
    }

    if (search(res1, 133) == true)
    {
        cout << "133 is Present!" << endl;
    }
    else
    {
        cout << "133 is Not Present!" << endl;
    }



    cout << "\n\nTest Case 2: " << endl;
    int hashSize2 = 37;

    vector<int> res2 = linearProbing(hashSize2, Array, sizeOfArray);
    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2.at(i) << " ";
    }
    cout << endl;

    if (search(res2, 100) == true)
    {
        cout << "100 is Present!" << endl;
    }
    else
    {
        cout << "100 is Not Present!" << endl;
    }

    if (search(res2, 174) == true)
    {
        cout << "174 is Present!" << endl;
    }
    else
    {
        cout << "174 is Not Present!" << endl;
    }

    if (search(res2, 133) == true)
    {
        cout << "133 is Present!" << endl;
    }
    else
    {
        cout << "133 is Not Present!" << endl;
    }


    return 0;
}
