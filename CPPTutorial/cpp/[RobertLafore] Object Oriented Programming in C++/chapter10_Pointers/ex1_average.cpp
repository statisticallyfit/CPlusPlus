#include <iostream>
using namespace std;



float average(float *numbers, int length){
    float *traverser = numbers;
    float *end = numbers + length;
    float sum = 0;

    for (/*traverser = numbers*/; traverser < end; traverser++){
        sum += *traverser;
    }

    return sum / length;
}


int main() {

    int length = 0;
    cout << "\nHow many numbers?: "; cin >> length;

    float *listOfNumbers = new float[length + 1];

    for (int i = 0; i < length; i++){
        cout << "#" << i + 1 << ": ";
        cin >> *(listOfNumbers + i);
    }

    cout << "\nThe average is: " << average(listOfNumbers, length) << endl;
    delete[] listOfNumbers;

    return 0;
}