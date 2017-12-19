//#include "FractionClass.h"
#include "../../../../trunk/Fraction.h"
#include "../../../../trunk/VectorOperations.h"
#include <iostream>
#include <vector>
#include <string.h>


int inputDenominator() {
    int d;
    cout << endl;
    cout << "Input a denominator: ";
    cin >> d;

    return d;
}

void createFractions(vector<Fraction> &fractions, int denominator) {

    for (int numerator = 1; numerator < denominator; numerator++){
        Fraction f(numerator, denominator);
        f.simplify();
        fractions.push_back(f);
    }
}


void fractionize(vector<Fraction> &fractions, vector<Fraction> &table) {

    typedef vector<Fraction>::size_type fracSize;

    for (fracSize i = 0; i < fractions.size(); i++){
        for (fracSize j = 0; j < fractions.size(); j++){
            table.push_back(fractions.at(i)
                                    .multiply(fractions.at(j), false));
        }
    }
}

string makeSymbols(int amount, char sym)
{
    string spaces(amount, sym);
    return spaces;
}

void printTable(vector<Fraction> &fractions,
                vector<Fraction> &table,
                int denominator)
{
    int space = 3;
    int leftMostBorder = 1;
    int bracketLen = 1;
    int maxFracDenomLen = maxWidth(fractions, true);
    int maxFracNumLen = maxWidth(fractions, false);
    int maxTableDenomLen = maxWidth(table, true); //getting max denominator digit length
    int maxTableNumLen = maxWidth(table, false); //getting max numerator digit length
    int numCols = denominator - 1;

    int indent = maxFracDenomLen + maxFracNumLen + bracketLen + space;
    const string INDENTSPACE(indent, ' ');
    string INDENTLINES(indent, '-');


    const int MAXROOM = maxTableDenomLen + maxTableNumLen + bracketLen + space;
    const string BORDER(leftMostBorder, ' ');


    /** FIrst line of fractions list */
    cout << endl;
    cout << INDENTSPACE;
    for (int i = 0; i < fractions.size(); i++){
        Fraction f = fractions.at(i);
        string FILL_SPACE = makeSymbols(MAXROOM - f.toString().length(), ' ');

        cout << f.toString() << FILL_SPACE;
    }

    /** Making lines underneath fraction titles */
    cout << endl;
    cout << INDENTLINES;
    for (int i = 0; i < fractions.size(); i++){
        Fraction f = fractions.at(i);
        string UNDER_LINE = makeSymbols(f.toString().length(), '-');
        string FILL_LINE = makeSymbols(MAXROOM - f.toString().length(), '-');

        //another dash for left vertical border
        cout << UNDER_LINE << FILL_LINE << "-";
    }

    /** Making the actual content */
    cout << endl;
    int j = 0;
    int i = 0;
    for(int counter = 0; counter < table.size(); counter++)
    {
        Fraction f = fractions.at(j);
        string FILL_SPACE = makeSymbols(MAXROOM - f.toString().length(), ' ');

        if (i == 0 || i % numCols == 0)  // if at first left border
        {
            cout << BORDER << f.toString() << FILL_SPACE;
        }
        f = table.at(i); // now to output the table values
        i++; //for next value
        FILL_SPACE = makeSymbols(MAXROOM - f.toString().length(), ' ');
        cout << f.toString() << FILL_SPACE; //spaces between this and next fraction

        if (i % numCols - 1 == 0){ // if at right border
            j++;
            cout << endl;
        }
/*
        if (i % numCols-1 == 0){
            j++;
        }*/
    }
}


int main() {

    vector<Fraction> listOfFractions;
    vector<Fraction> answerTable;

    int denominator = inputDenominator();
    createFractions(listOfFractions, denominator);
    fractionize(listOfFractions, answerTable);
    printTable(listOfFractions, answerTable, denominator);

    return 0;
}
