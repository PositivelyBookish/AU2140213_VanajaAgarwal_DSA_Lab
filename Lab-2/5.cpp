//AU2140213 Vanaja Agarwal
//5.
#include <iostream>
using namespace std;

int* function(int *arr, int ele){
    int n = sizeof(arr)/sizeof(arr[0]);
    arr[0] = ele;
    return arr;
}


int main(){
    int n, ele;
    cout << "Enter N: ";
    cin >> n;
    int arr[n+1];
    cout << "Enter elements: " << endl;

    for (int i = 1; i < n+1; i++){
        cin >> arr[i];
    }

    cout << "Enter element to be inserted: ";
    cin >> ele;

    int* value = function(arr,ele);

    for (int i = 0; i < n+1; i++){
        cout << value[i] << " ";
    }
    
    return 0;
}