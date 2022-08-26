//AU2140213 Vanaja Agarwal
//3.
#include<bits/stdc++.h>
using namespace std;

void delatind(int arr[], int n, int pos)
{
   --pos;
   for(int i=pos;i<=n-1;i++)
   {
    arr[i]=arr[i+1];
   }
   cout<<"\nNew Array is: \n";

  for(int i=0;i<n-1;i++)
  {
    cout<<" "<<arr[i]<<" ";
  }
}

int main()
{
    int n, pos;

    cout << "Enter N: ";
    cin >> n;
    cout << "Enter elements: ";
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter position: ";
    cin >> pos;

    delatind(arr, n, pos);
    return 0;
}