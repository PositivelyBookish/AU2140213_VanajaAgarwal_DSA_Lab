//AU2140213 Vanaja Agarwal
//9.Replace en element by index position
#include <iostream>
using namespace std;

void replatind(int arr[], int n, int ind, int ele){
    arr[ind] = ele;
    for (int l = 0; l < n; l++){
        cout << arr[l] << " ";
    }
    
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array: ";
    int arr[n];
    for (int l = 0; l < n; l++){
        cin >> arr[l];
    }
    int ind, ele;
    cout << "Enter index: ";
    cin >> ind;
    cout << "Enter element to be replaced: ";
    cin >> ele;
    replatind(arr, n, ind, ele);
    return 0;
}