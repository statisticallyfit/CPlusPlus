#include <iostream>
#include <vector>
#include "../../../../trunk/Fraction.h"
//#include "../../../../trunk/Fraction.h";
using namespace std;


void readFractions(vector<Fraction> &fractions) {

    string userContinues = "";
    int numerator = 0;
    int denominator = 0;
    int count = 1;

    cout << "Enter a list of fractions one by one: " << endl;
    do {
        cout << "numerator #" << count << ": ";
        cin >> numerator;
        cout << "denominator #" << count << ": ";
        cin >> denominator;
        fractions.push_back(Fraction(numerator, denominator));
        count++;

        cout << "continue? (y/n): ";
        cin >> userContinues;

    } while (userContinues == "y");
}

/** Assume at least one element in vector */
Fraction averageFractions(vector<Fraction> &fractions){

    Fraction accumulator = fractions.at(0);
    for (int i = 1; i < fractions.size(); i++){
        accumulator.addAcumulatively(fractions.at(i));
    }
    Fraction ans = accumulator.divide(fractions.size());
    return ans;
}


int main() {

    // create vector
    vector<Fraction> fractions;

    // input fractions
    readFractions(fractions);

    // average the fractions
    Fraction answer = averageFractions(fractions);

    cout << "\n\nAnswer is: " << answer.toString() << endl;
}