#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort()
#include <iomanip> // for setw()
#include <math.h> // for floor()

using namespace std;
/*using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::max_element;     // returns the iterator to the max element, so use * to dereference to get value out
 */


/**
 * Gets a vector of values as input and returns the squares
 */
vector<double> square(const vector<double>& numbersToSquare) {
    // Create a new vector that will hold the squares
    vector<double> temp = numbersToSquare;
    vector<double> squared;

    // Create size type for the iterator i
    typedef vector<double>::size_type vecSize;

    for(vecSize i = 0; i < numbersToSquare.size(); i++) {
        squared.push_back(temp[i] * temp[i]);
    }
    return squared;
}


/**
 * This function checks if a double type number is whole or not.
 */
bool isWhole(double number) {
    return (floor(number) == number);
}


/**
 * This function converts decimal number (double) to string
 * and removes trailing zeroes and decimal point if necessary:
 *  123.000 => 123
 *  123.0500 => 123.05
 */
string doubleToString(double d) {
    string s = to_string(d);
    s.erase(s.find_last_not_of("0") + 1, std::string::npos);
    // if last element is the decimal dot, erase it too
    string lastElement = s.substr(s.size() - 1);
    return (lastElement == ".") ? s.substr(0, s.size() - 1) : s;
}


/**
 * Gets the digit count of the number with most digits
 * For doubles, numbers after decimal count also and
 * decimal dot size = digit size
 */
vector<int>::size_type maxDigits(const vector<double>& numbers) {
    // Iterate over numbers, turn to string, store size in vector
    typedef vector<int>::size_type vecSizeInt;
    vector<vecSizeInt> numberLengths;

    for(vecSizeInt i = 0; i < numbers.size(); i++) {
        string s = doubleToString(numbers[i]);
        vecSizeInt numLength = s.size();
        numberLengths.push_back(numLength);
    }
    // find max length in vector
    sort(numberLengths.begin(), numberLengths.end());

    return(numberLengths[numberLengths.size() - 1]);
}



int main() {

    cout << "Please enter numbers one by one: ";

    // Input the numbers
    double num;
    vector<double> numbersToSquare;
    while(cin >> num) { // while reading in was a success
        numbersToSquare.push_back(num);
    }

    // Square the numbers
    vector<double> squared = square(numbersToSquare);

    // Find the maxIntLength for pretty printing below
    typedef vector<int>::size_type vecSizeInt;

    vecSizeInt maxLengthOfNumbers = maxDigits(numbersToSquare);
    vecSizeInt n1 = 3 + maxLengthOfNumbers;
    vecSizeInt n2 = n1 + 4;

    // Print out with setw()
    cout << setw(n1) << "Numbers: " << setw(n2) << "Squared Numbers: \n";
    for(vecSizeInt i = 0; i < squared.size(); i++){
        cout << setw(n1) << numbersToSquare[i] << setw(n2) << squared[i] << "\n";
    }

    return 0;
}