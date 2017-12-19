#include <iostream>
using namespace std;

int main() {
    int n = 10;

    myLabel:
        cout << n << ", ";
        n--;
        if(n > 0)
            goto myLabel;
        cout << "liftoff!\n";

    return 0;
}