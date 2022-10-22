//AU2140213 VANAJA BINAY AGARWAL
//Q3.


#include <iostream>

using namespace std;
 
 
int Hash(int key, int hashSize){
    return key % hashSize;
}
 
int PrimeHash(int key, int prime){
    return prime - (key % prime);
}
 
int DoubleHash(int H[], int key, int hashSize, int prime){
    int idx = Hash(key, hashSize);
    int i = 0;
    while (H[(Hash(idx, hashSize) + i * PrimeHash(idx, prime)) % hashSize] != 0){
        i++;
    }
    return (idx + i * PrimeHash(idx, prime)) % hashSize;
}
 
void Insert(int H[], int key, int hashSize, int prime){
    int idx = Hash(key, hashSize);
 
    if (H[idx] != 0){
        idx = DoubleHash(H, key, hashSize, prime);
    }
    H[idx] = key;
}
 
int Search(int H[], int key, int hashSize, int prime){
    int idx = Hash(key, hashSize);
    int i = 0;
    while (H[(Hash(idx, hashSize) + i * PrimeHash(idx, prime)) % hashSize] != key){
        i++;
        if (H[(Hash(idx, hashSize) + i * PrimeHash(idx, prime)) % hashSize] == 0){
            cout <<key <<" ";
            return -1;
        }
    }
    cout <<key <<" ";
    return (Hash(idx, hashSize) + i * PrimeHash(idx, prime)) % hashSize;
}

void print(int arr[], int sizeofArray){
    for(int i=0; i < sizeofArray;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }
 
 
int main() {
 
    int A[] = {133, 82, 92, 221, 174};
    int sizeofArray = sizeof(A)/sizeof(A[0]);
    print(A, sizeofArray);
    int hashSize = 17;
    int prime = 11;
    // Hash Table
    int HT[hashSize] = {0};
    for (int i=0; i< sizeofArray; i++){
        Insert(HT, A[i], hashSize, prime);
    }

    print(HT, hashSize);
 
    int index1 = Search(HT, 100, hashSize, prime);
    cout << "key found at: " << index1 << endl;
 
    int index2 = Search(HT, 133, hashSize, prime);
    cout << "key found at: " << index2 << endl;

    int index3 = Search(HT, 174, hashSize, prime);
    cout << "key found at: " << index3 << endl;
    return 0;
}


