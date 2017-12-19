#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
using std::setw;

int main() {
    for(int i = 1; i <= 1000; i++){
        // if width of number (i) is smaller than (n) in setw(n)
        // then setw(n) will align numbers to right and pad left with
        // leading empty spaces.
        // if width of number (i) is greater than (n), setw(n)
        // will still align to right and fill left with empty spaces,
        // just this time the left has less spaces.
        cout << setw(7) << i << setw(9) << (i * i) << endl;
    }
    return 0;
}

