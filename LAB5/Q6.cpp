// AU2140213 Vanaja Agarwal
// QuickSort with middle element as pivot. (Concept: Hoare's Algorithm)

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{   
    int pivot=arr[(l+h)/2];
    int i=l-1,j=h+1;

    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}

void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}
 
int main() {
	
    int arr[]={8,4,7,9,3,10,5};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	quickSort(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}