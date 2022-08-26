//AU2140213 Vanaja Agarwal 
//Q5.Write a function prodArray( ) that returns the product of the numbers in the array. It returns 1 if
//the array is empty. For example, prodArray([2,5,10]) = 100.

#include<iostream>
using namespace std;

int prodArray(int x[],int num)
{
    if(num==0){
        return 1;
    }

    return(x[num]*prodArray(x, num-1));
}


int main()
{
    int arr[] = {11,22,33,44,56};
    int n = sizeof(arr)/sizeof(int);
    int res = prodArray(arr,n-1);
    cout << "Result: " << res << endl;
    
    return 0;
}

//Output:
//Result: 1788864