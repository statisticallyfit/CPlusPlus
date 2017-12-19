
#ifndef VEC_OP_H
#define VEC_OP_H



#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort()
#include <iomanip> // for setw()
#include "Fraction.h" // for Fraction maxdigits

using namespace std;




/**
 * Gets a vector of values as input and returns the squares
 */
vector<long> square(const vector<long>& numbersToSquare) {
    // Create a new vector that will hold the squares
    vector<long> temp = numbersToSquare;
    vector<long> squared;

    // Create size type for the iterator i
    typedef vector<long>::size_type vecSize;

    for(vecSize i = 0; i < numbersToSquare.size(); i++) {
        squared.push_back(temp[i] * temp[i]);
    }
    return squared;
}


/**
 * Gets the digit x of the number with most digits
 * For doubles, numbers after decimal x also and
 * decimal size = digit size
 */
vector<long>::size_type maxWidth(const vector<long> &numbers) {
    // Iterate over numbers, turn to str, store size in vector
    typedef vector<long>::size_type vecSize; // for iterating i over double vec numbers
    vector<vecSize > numberLengths;

    for(vecSize i = 0; i < numbers.size(); i++) {
        long num = numbers[i];
        string str = to_string(num);
        vecSize numLength = str.size();
        numberLengths.push_back(numLength);
    }
    // find max length in vector
    sort(numberLengths.begin(), numberLengths.end());

    return(numberLengths[numberLengths.size() - 1]);
}

/** Returns the max number of digits of the largest Fraction denominator **/
int maxWidth(const vector<Fraction> &fractions, bool checkDenomWidth){

    //typedef vector<Fraction>::size_type fracSize;
    vector<int> denominatorLengths;
    string str = "";
    int value = 0;

    for(int i = 0; i < fractions.size(); i++) {
        if (checkDenomWidth)
            value = fractions.at(i).getDenom();
        else
            value = fractions.at(i).getNum();
        str = to_string(value);
        int length = str.size();
        denominatorLengths.push_back(length);
    }
    // find max length in vector
    sort(denominatorLengths.begin(), denominatorLengths.end());

    return(denominatorLengths[denominatorLengths.size() - 1]);
}

#endif //VEC_OP_H