#include <iostream>
using namespace std;


class SerialNumber {

private:
    static unsigned int numberCount;
    unsigned int serialNumber = 0;
    
public:
    SerialNumber() {
        numberCount++;
        serialNumber = numberCount;
    }

    int getSerialNumber() {
        return serialNumber;
    }
};
unsigned int SerialNumber::numberCount = 0;



int main() {

    SerialNumber s1, s2, s3, s4, s5;

    cout << "s1: " << s1.getSerialNumber() << endl;
    cout << "s2: " << s2.getSerialNumber() << endl;
    cout << "s3: " << s3.getSerialNumber() << endl;
    cout << "s4: " << s4.getSerialNumber() << endl;
    cout << "s5: " << s5.getSerialNumber() << endl;

    return 0;
}