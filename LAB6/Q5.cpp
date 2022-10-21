//AU2140213 VANAJA BINAY AGARWAL
//Q5.


#include <bits/stdc++.h>
using namespace std;

struct MyHash
{
    const int P = 17, M = 1e9 + 7;
    int h1 = 0;

    void CalculateHash(const string &s)
    {
        long poly_power = 1;
        for (char ch : s)
        {
            h1 = (h1 + (ch + 1 - 'a') * poly_power) % M;
            poly_power = (poly_power * P) % M;
        }
    }

    MyHash(const string &str)
    {
        CalculateHash(str);
    }
};

int main()
{
    const char *testString[6] = {"fist", "sift", "shift", "fast", "faster", "shaft"};

    for (int i = 0; i < 6; i++)
    {
        MyHash h(testString[i]);
        cout << "Hash value of " << testString[i] << " is: ";
        cout << h.h1 << '\n';
    }
    return 0;
}