//AU2140213 Vanaja Agarwal
//1.Search Array

#include <iostream>
using namespace std;

int srch(int *arr, int n, int ele){
    
    for (int x = 0; x < n; x++){
        if (arr[x] == ele){
            return x;
        }  
    }
    
    return -1;
}

int main(){
    int n, ele;

    cout << "Enter N: ";
    cin >> n;
    cout << "Enter elements: ";
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter element to be searched for: ";
    cin >> ele;


    int ans = srch(arr, n, ele);
    cout << "Element found at position: "  << ans << endl;
    return 0;
}