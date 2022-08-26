//AU2140213 Vanaja Agarwal
//Q4.Write a function fib( ) that accepts a number n and outputs the nth number in the Fibonacci sequence.
// F(1) = 0
// F(2) = 1
// F(N) = F(N-1) + F(N-2)

#include <iostream>
using namespace std;

int fib(int num){
    if (num == 0){
        return 0;
    }
    else if (num == 1){
        return 1;
    }
    else{
        return (fib(num-1) + fib(num-2));
    }
}

int main(){
    int input;
    cout << "Enter number: ";
    cin >> input;
    int value = fib(input);
    cout << "Answer: " << value << endl;

    return 0;
}

// //Output:
// Enter number: 10
// Answer: 55