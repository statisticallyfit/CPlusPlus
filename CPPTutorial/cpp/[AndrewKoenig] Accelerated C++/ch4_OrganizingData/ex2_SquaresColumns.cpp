#include "VectorOperations.h"
/*using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::max_element; */    // returns the iterator to the max element, so use * to dereference to get value out




int main() {

    cout << "Please enter numbers one by one: ";

    // Input the numbers
    long num;
    vector<long> numbersToSquare;
    while(cin >> num) { // while reading in was a success
        numbersToSquare.push_back(num);
    }

    // Square the numbers
    vector<long> squared = square(numbersToSquare);

    // Find the maxIntLength for pretty printing below
    typedef vector<long>::size_type vecSize;

    vecSize maxLengthOfNumbers = maxDigits(squared);
    vecSize n1 = 3 + maxLengthOfNumbers;
    vecSize n2 = n1 + 4;

    // Print out with setw()
    cout << setw(n1) << left << "N: " << setw(n2) << left << "N^2: " << endl;
    for(vecSize i = 0; i < squared.size(); i++){
        cout << setw(n1) << left << numbersToSquare[i]
             << setw(n2) << left << squared[i] << "\n";
    }

    return 0;
}