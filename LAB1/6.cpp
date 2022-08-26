//AU2140213 Vanaja Agarwal
//Q6.Write a function HCF( ) that accepts two numbers and finds the highest common factor of the
//two numbers. For e.g. HCF(6,9) = 3.

#include <iostream>
using namespace std;

int HCF(int num1, int num2){
    while (num1 != num2)
    {
        /* code */
        if (num1 > num2){
            return HCF(num1-num2, num2);
        }
        else{
            return HCF(num1, num2-num1);
        }
    }

    return num1;
    
}

int main()
{
    int num1, num2;
    cout << "Enter Number 1: ";
    cin >> num1;
    cout << "Enter Number 2: ";
    cin >> num2;
    int res = HCF(num1, num2);
    cout << "Answer: " << res << "\n";

    return 0;
}

//Output:
// Enter Number 1: 24
// Enter Number 2: 42
// Answer: 6