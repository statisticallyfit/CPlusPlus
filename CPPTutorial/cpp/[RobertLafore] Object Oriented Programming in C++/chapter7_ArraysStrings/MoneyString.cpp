#include <iostream>
#include "math.h"
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip> // for set precision
#include <sstream> //for ostringstream instead of ostrstream

using namespace std;

// Declaring class prototype
class Money;



class Money {

private:
    long double money;
public:
    Money() : money(0.00)
    {}
    Money(string strMoney) : money(stringToDouble(strMoney))
    {}
    Money(long double m) : money(m)
    {}
    long double getMoney() { return money; }
    void setMoney(long double m) { money = m;}

    Money add(Money other){ return Money(money + other.getMoney()); }
    Money subtract(Money other) { return Money(money - other.getMoney()); }
    Money multiply(Money other) { return Money(money * other.getMoney()); }
    Money divide(Money other) { return Money(money / other.getMoney()); }

private:
    /** Converts money fancy display to double */
    long double stringToDouble(string money){

        // fill the character array
        int length = money.length();
        int dotPos = money.find_first_of('.');
        int limit = (dotPos == -1) ? length : dotPos;
        bool hasDecimal = dotPos != -1;
        string cleanMoney;
        char temp[length];

        money.copy(temp, length, 0);

        // reading integer part
        for (int i = 0; i < limit; i++){
            if (isdigit(temp[i])){
                cleanMoney += to_string(temp[i] - '0');
            }
        }

        if (hasDecimal){
            // now doing decimal or cents part
            cleanMoney += '.';
            for (int i = dotPos + 1; i < length; i++){
                if (isdigit(temp[i])){
                    cleanMoney += to_string(temp[i] - '0'); //to convert from char to int
                }
            }
        }

        //convert string to double
        long double moneyDouble = stod(cleanMoney);

        return (moneyDouble);
    }

    /** Converts long double to fancy display money */
    string doubleToString(long double money) {

        string plainMoney = "";
        string fancyMoney = "";
        ostringstream stream;
        bool dollarAmountIsLessThanThreeDigits = to_string((int)money).length() < 3;

        if (money > 9999999999999990.00)
            return ""; // return empty string

        // put the double in memory and then get the string
        // POINT: to convert double to string, THEN format
        stream << fixed << setprecision(2) << money;
        plainMoney = stream.str();

        // Now format the plain money string
        int digitsToSkipInFront = plainMoney.length() % 3; // since commas every 3 digits
        fancyMoney = "$ " + plainMoney.substr(0, digitsToSkipInFront);
        if (!dollarAmountIsLessThanThreeDigits && digitsToSkipInFront != 0){
            fancyMoney += ",";
        }
        // start on index = number skipped in plainMoney
        for (int i = digitsToSkipInFront; i < plainMoney.length(); i += 3){
            fancyMoney += plainMoney.substr(i, 3); //3 is length of digits between commas
            if (plainMoney.substr(i+3, 1) != "." &&
                i + 3 != plainMoney.length() &&
                !dollarAmountIsLessThanThreeDigits) // if not at last set of 3 digits, add comma
                fancyMoney += ",";
        }
        return fancyMoney;
    }

public:
    string toString(){
        return doubleToString(money);
    }
    long double toDouble() {
        return money;
    }
};









int main() {

    string answer = "";

    do {
        string s = "";
        cout << "\nEnter a monetary amount: " << endl;
        getline(cin, s);
        Money m(s);
        // fixed makes iostream not print in scientific notation
        cout << fixed << setprecision(2) << "To double: " << m.toDouble() << endl;
        cout << "Back to string: " << m.toString() << endl;

        cout << "\nContinue? (y/n): " << endl;
        getline(cin, answer);
    } while (answer == "y");

    return 0;
}