//AU2140213 Vanaja Agarwal
//Q1.Write the function factorial( ) that we discussed in the class.
#include <iostream>
using namespace std;
#include <cmath>
int factorial(float num){
    if (num > 0 && (floor(num) == num)){
        cout << "Line: " << num << endl;
        if (num == 1 || num == 0){
            cout << "0 or 1, done." << endl;
            return 1;
    }
        int temp = (num*factorial(num-1));
        return temp;
    }
    else {
        return -1;
    }
    
}

int main(){
    float input;
    cout << "Enter number: ";
    cin >> input;
    int value = factorial(input);
    cout << "Facorial of " << input << " is: " <<  value << endl;

    return 0;
}

//Output:
// Enter number: 7
// Line: 7
// Line: 6
// Line: 5
// Line: 4
// Line: 3
// Line: 2
// Line: 1
// 0 or 1, done.
// Facorial of 7 is: 5040