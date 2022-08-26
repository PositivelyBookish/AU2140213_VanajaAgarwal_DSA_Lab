//AU2140213 Vanaja Agarwal
//4.
#include <iostream>
using namespace std;

void insatend(int arr[], int n, int ele){
    arr[n-1] = ele;
}

int main(){
    int n, ele;
    cout << "Enter N: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n-1; i++){
        cin >> arr[i];
    }
    cout << "Enter element to be inserted: ";
    cin >> ele;
    insatend(arr, n, ele);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}