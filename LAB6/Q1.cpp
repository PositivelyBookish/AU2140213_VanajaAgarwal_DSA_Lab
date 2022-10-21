#include <bits/stdc++.h>
using namespace std;

// Function to fill the array elements into a hash table
// using Linear Probing to handle collisions.
vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
{
    // Your code here
    vector<int> hash(hashSize);
    for (int i = 0; i < hashSize; i++)
        hash[i] = -1;

    for (int i = 0; i < sizeOfArray; i++)
    {
        int k = (arr[i]) % hashSize;
        if (hash[k] == -1)
        {
            hash[k] = arr[i];
        }
        else
        {
            int count = 0;
            int flag = 0;
            while (count < hashSize && hash[k] != -1)
            {
                if (hash[k] == arr[i])
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
                hash[k] = arr[i];
        }
    }
    return hash;
}

bool search(vector<int> arr, int key)
{
    int h = key % (arr.size());
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
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
    cout << "Enter HashSize: ";
    cin >> hashSize;
    int sizeOfArray = 5;
    int Array[] = {133, 88, 92, 221, 174};
    vector<int> res = linearProbing(hashSize, Array, sizeOfArray);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res.at(i) << " ";
    }
    cout << endl;

    if (search(res, 100) == true)
    {
        cout << "100 is Present!" << endl;
    }
    else
    {
        cout << "100 is Not Present!" << endl;
    }

    if (search(res, 174) == true)
    {
        cout << "174 is Present!" << endl;
    }
    else
    {
        cout << "174 is Not Present!" << endl;
    }

    if (search(res, 133) == true)
    {
        cout << "133 is Present!" << endl;
    }
    else
    {
        cout << "133 is Not Present!" << endl;
    }
    return 0;
}
