#include <iostream>
using namespace std;



void centimizeByRef(double &v){
    v *= 2.54;
}

void centimizeByPointer(double* pointerToDouble){
    *pointerToDouble *= 2.54;
}


int main()
{
    double var = 10.0;

    cout << endl << "REF" << endl;
    cout << "var = " << var << " inches" << endl;
    // passing the variable itself so function can change the actual var
    centimizeByRef(var);
    cout << "var = " << var << " centimeters" << endl;

    var = 10.0;
    cout << endl << "POINTER" << endl;
    cout << "var = " << var << " inches" << endl;
    // not passing the actual variable, but its address, then using indirection operator *
    centimizeByPointer(&var);
    cout << "var = " << var << " centimeters" << endl;

    return 0;
}