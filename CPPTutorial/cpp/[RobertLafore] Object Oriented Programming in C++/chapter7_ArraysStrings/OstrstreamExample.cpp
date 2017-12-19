#include <strstream>
#include <iostream>
#include <iomanip> //for setiosflags()
using namespace std;


const int SIZE = 80;

int main() {

    char ch = 'x';
    int j = 77;
    double d = 67890.12345;
    char str1[] = "Kafka";
    char str2[] = "Freud";

    char memoryBuffer[SIZE]; // buffer in memory
    ostrstream outputMemory(memoryBuffer, SIZE); //create stream object

    outputMemory << "ch=" << ch << endl
                 << "j=" << j << endl
                 << setiosflags(ios::fixed) //format with decimal point
                 << setprecision(2)
                 << "d=" << d << endl
                 << "str1=" << str1 << endl
                 << "str2=" << str2 << endl
                 << ends;                   // end the buffer with '\0'
    cout << memoryBuffer;

    return 0;
}