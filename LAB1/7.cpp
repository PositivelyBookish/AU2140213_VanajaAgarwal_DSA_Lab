//AU2140213 Vanaja Agarwal
//Q7.Write a function IsPali( ) that accepts a string and returns True if it is a palindrome and returns
//False it is not.

#include <iostream>
using namespace std;

int isPali(string input, int start, int end){
    if (start == end){
        return 1;
    }

    if (input[start] != input[end]){
        return 0;
    }

    if (start <= end){
        start++;
        end--;
        return isPali(input, start, end);
    }

    return 1;
}

int main(){
    cout << "Enter String: ";
    string input;
    cin >> input;
    int res;
    if (input.length() != 0){
        res = isPali(input, 0, (input.length()-1));
    }
    else{
        res = 1;
    }

    if (res == 0){
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }
    
    return 0;
}

//Output:
// Enter String: malayalam
// True