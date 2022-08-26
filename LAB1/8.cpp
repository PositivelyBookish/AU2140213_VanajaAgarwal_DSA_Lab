//AU2140213 Vanaja Agarwal
//Q8.Write a function reverse( ) that accepts a string and reverses it.

#include  <iostream>

using namespace std;

void reverse(string &input, int first, int last){
    if (first < last){
        swap(input[first], input[last]);
        reverse(input, first+1, last-1);
    }

}

int main(){
    cout << "Enter String: ";
    string input;
    cin >> input;
    reverse(input, 0, (input.length()-1));
    cout << "Reverse: " << input << "\n";


    return 0;
}

//Output:
// Enter String: VanajaAgarwal
// Reverse: lawragAajanaV