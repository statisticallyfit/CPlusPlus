#include <iostream>
using namespace std;

// ----- Overloading -------
int multiply(int a, int b){
    return(a * b);
}

double multiply(double a, double b) {
    return (a * b);
}



// ------- Templates ---------
template <class SomeType>
SomeType operate(SomeType a, SomeType b){
    return a+b;
}

template <class T, class U>
bool areEqual(T a, U b) {
    return (a == b);
}

// non-type template
template <class T, int N>
T fixedMultiply(T value){
    return value * N;
}


// ---------------------------
// ** NOTE: using & makes a constant pointer but * makes a mutable pointer
int main() {
    /*//operate example
    cout << operate<int>(10, 20.5) << endl;
    cout << operate<float>(10, 20.5) << endl;*/

    /*// areEqual example (can use two arguments in template)
    string x = "cat";
    string y = "cat";
    if(areEqual(x, y))
        cout << "x and y are equal\n";
    else
        cout << "x and y are not equal\n";*/

    // fixedMultiply example
    cout << fixedMultiply<int, 2>(10) << "\n";
    cout << fixedMultiply<int, 3> (10) << "\n";

    return 0;
}