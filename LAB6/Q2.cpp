//AU2140213 VANAJA BINAY AGARWAL
//Q2.


#include <bits/stdc++.h>
using namespace std;

// Function to fill the array elements into a hash table
// using Quadratic Probing to handle collisions.
vector<int> QuadraticProbing(int hashSize, int arr[], int sizeOfArray)
{
    vector<int> hash(hashSize);
    for (auto &x : hash)
    {
        x = -1;
    }
    for (int i = 0; i < sizeOfArray; i++)
    {
        int j = 1;
        int k = arr[i] % hashSize;
        int p = k;
        while (hash[p] != -1 && hash[p] != arr[i])
        {
            p = (k + (j * j)) % hashSize;
            j++;
        }
        k = p;
        if (hash[k] == -1)
            hash[k] = arr[i];
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
    vector<int> res = QuadraticProbing(hashSize, Array, sizeOfArray);
    for (int i = 0; i < hashSize; i++)
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
