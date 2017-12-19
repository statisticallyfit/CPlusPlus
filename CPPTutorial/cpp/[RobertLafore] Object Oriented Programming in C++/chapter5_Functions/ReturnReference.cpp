#include <iostream>
using namespace std;


int value; // global variable (is static)


int &setValue(){
    return value;
}


int main() {
    int otherValue = 23;
    setValue() = 92;
    cout << "value = " << value << endl;
    setValue() = otherValue;
    cout << "otherValue = " << otherValue << endl;

    return 0;
}