#include <iostream>
using namespace std;


int main() {

    int x = 3;
    int *pointerX = &x;
    cout << &x << endl
         << *pointerX << endl
         << pointerX << endl;

    *pointerX = 50;
    cout << *pointerX << endl
         << pointerX << endl;

    return 0;
}