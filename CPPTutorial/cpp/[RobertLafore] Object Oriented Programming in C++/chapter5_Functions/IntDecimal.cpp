#include <iostream>
using namespace std;



void separateParts(float realNumber, float &integerPart, float &fractionPart) {
    long temp = static_cast<long>(realNumber);
    integerPart = static_cast<float>(temp);
    fractionPart = realNumber - integerPart;
}


int main() {

    float number, intPart, fracPart;

    do {
        cout << "\nEnter a real number: ";
        cin >> number;
        separateParts(number, intPart, fracPart);
        cout << "Integer part is: " << intPart
             << "\nFraction part: " << fracPart << endl;
    } while (number != 0.0);

    return 0;
}