#include <iostream>
using namespace std;


int main() {
    int intVar = 8;
    float floatVar = 99.9;

    int *ptrInt;
    float *ptrFloat;
    void *ptrVoid;

    ptrInt = &intVar;
    // ptrInt = &floatVar; //error
    // @todo: don't know why this next line doesn't work...
    //ptrInt = reinterpret_cast<int*>(floatVar); //alternative
    // ptrFloat = &intVar; // error
    ptrFloat = reinterpret_cast<float*>(intVar); //alternative

    ptrFloat = &floatVar;
    ptrVoid = &intVar;
    ptrVoid = &floatVar;
    cout << "void pointer can point to any type" << endl;

    return 0;
}