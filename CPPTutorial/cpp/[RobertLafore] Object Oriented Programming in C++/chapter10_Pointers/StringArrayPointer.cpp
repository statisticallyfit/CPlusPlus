#include <iostream>
using namespace std;

int main() {
    char str1[] = "Defined as an array";
    const char *str2 = "Defined as a pointer";

    cout << str1 << endl;
    cout << str2 << endl;

    // str1++; // gives error since str1 is a constant
    str2 += 3; //ok since pointer

    cout << str2 << endl;

    return 0;
}