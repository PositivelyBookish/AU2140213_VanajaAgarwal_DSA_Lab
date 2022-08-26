//AU2140213 Vanaja Agarwal
//Q2.Write the following function and see its output:
// def first( ):
// second( )
// print("I am the first")
// def second( ):
// third( )
// print("I am the second")
// def third():
// fourth( )
// print("I am the third")
// def fourth( ):
// print("I am the fourth")

#include <iostream>
using namespace std;

void fourth(){
    cout << "I am the fourth" << "\n";
}

void third(){
    fourth();
    cout << "I am the third" << "\n";
}

void second(){
    third();
    cout << "I am the second" << "\n";
}

void first(){
    second();
    cout << "I am the first" << "\n";
}


int main(){
    first();

    return 0;
}

// //Output:
// I am the fourth
// I am the third
// I am the second
// I am the first