//#include "Fraction.h"
#include "../../../../trunk/Fraction.h"
//#include <iostream>
//#include <cmath>
//using namespace std;




int main() {

    string answer;
    bool userContinue = true;

    cout << "===================" << endl;
    do {
        int n;
        int d;

        printf("\n");
        printf("Enter fraction 1: ");
        scanf("%i/%i", &n, &d);
        Fraction f1(n, d);

        printf("Enter fraction 2: ");
        scanf("%i/%i", &n, &d);
        Fraction f2(n, d);

        printf("\n");

        printf("Added: ");
        f1.add(f2).show();
        printf("Subtracted: ");
        f1.subtract(f2).show();
        printf("Multiplied: ");
        f1.multiply(f2, true).show();
        printf("Divided: ");
        f1.divide(f2).show();

        printf("\n");
        cout << "Continue? (y/n): ";
        cin >> answer;

        if (answer == "n")
            userContinue = false;
        if (userContinue)
            cout << "===================" << endl;

    } while (userContinue);

    return 0;
}