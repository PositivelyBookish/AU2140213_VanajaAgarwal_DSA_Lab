//AU2140213 Vanaja Agarwal
//2.
#include<iostream>
using namespace std;


int* insatind(int arr[], int n,int pos){
    pos=pos-1;
    int s=sizeof(arr);
    for (int i = s; i >=pos; i--)
    {
        /* code */
        arr[i]=arr[i-1];

    }
    arr[pos]=n;
    return arr;
}


int main(){
    int arr[5]={22,33,44,55,66};
    
    insatind(arr,99,4);
    for (int  i = 0; i <=sizeof(arr)+1; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }
    return 0;

}
