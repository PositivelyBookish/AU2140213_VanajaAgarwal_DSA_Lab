//AU2140213 Vanaja Agarwal
//Q3.Write a function addup( ) that accepts a number and adds up all the numbers from 0 to the number.

#include <iostream>
using namespace std;
int addUp(int num){
    if (num == 0){
        return 0;
    }
    return (num + addUp(num -1));
}

int main(){
    int input;
    cout << "Enter number: ";
    cin >> input;
    int value = addUp(input);
    cout << "Answer: " << value << endl;

    return 0;
}

// //Output:
// Enter number: 11
// Answer: 66