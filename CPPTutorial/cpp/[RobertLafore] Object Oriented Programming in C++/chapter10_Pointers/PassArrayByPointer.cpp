#include <iostream>
using namespace std;

const int MAX = 5;

void centimize(double* doubleArray) {
    for (int i = 0; i < MAX; i++){
        *doubleArray++ *= 2.54;
    }
}



int main()
{
    double array[MAX] = {10, 43.1, 95.9, 59.7, 87.3};

    centimize(array);

    for (int i = 0; i < MAX; i++) {
        cout << "array[" << i << "] = " << array[i] << " centimeters" << endl;
    }

    return 0;
}