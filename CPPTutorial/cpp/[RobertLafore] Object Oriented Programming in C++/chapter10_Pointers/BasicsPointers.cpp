#include <iostream>
using namespace std;


int main () {

    int v;
    int *p;
    p = &v;
    cout << "p: " << p << endl <<
    "*p: " << *p << endl <<
    "v: " << v << endl;

    // changing value of v directly...
    v = 3;
    cout << "p: " << p << endl <<
            "*p: " << *p << endl <<
            "v: " << v << endl;

    // changing value of v first by pointer assignment
    *p = 4;
    cout << "p: " << p << endl <<
    "*p: " << *p << endl <<
    "v: " << v << endl;

    return 0;
}