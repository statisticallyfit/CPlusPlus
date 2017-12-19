#include <iostream>
#include <string.h> // for strcpy(), strcat()
#include <stdlib.h> // for exit()

using namespace std;


class String {

private:
    static const int SIZE = 80;
    char str[SIZE];

public:
    String() {
        strcpy(str, "");
    }
    String(char s[]) {
        strcpy(str, s);
    }

    char* getString() {
        return str;
    }
    void setString(char s[]) {
        strcpy(str, s);
    }

    void show() {
        cout << str;
    }

    void input() {
        cout << "Enter a string: ";
        cin >> str;
    }

    String operator + (String other) const {
        String temp;
        if (strlen(str) + strlen(other.getString()) < SIZE) {
            strcpy(temp.getString(), str);
            strcat(temp.getString(), other.getString());
        }
        else {
            cout << "\nString overflow"; exit(1);
        }

        return temp;
    }

    String operator += (String other) {
        if (strlen(str) + strlen(other.getString()) < SIZE) {
            strcat(str, other.getString());
        }
        else {
            cout << "\nString overflow"; exit(1);
        }
        return String(str);
    }

    bool operator == (String other) const {
        return (strcmp(str, other.getString()) == 0);
    }

    operator char*() {
        return str;
    }
};


int main () {

    /** Testing (+=) operator */
    String s1, s2, result;
    s1.input();
    s2.input();

    cout << "\nBEFORE void add: ";
    cout << "\ns1 = "; s1.show();
    cout << "\ns2 = "; s2.show();

    s1 += s2;

    cout << "\nAFTER void add: ";
    cout << "\ns1 = "; s1.show();
    cout << "\ns2 = "; s2.show(); cout << endl << endl;



    /** Test 2 with return */
    s1.input();
    s2.input();

    cout << "\nBEFORE return add: ";
    cout << "\ns1 = "; s1.show();
    cout << "\ns2 = "; s2.show();

    result = s1 += s2;

    cout << "\nAFTER return add: ";
    cout << "\ns1 = "; s1.show();
    cout << "\ns2 = "; s2.show();
    cout << "\nresult = "; result.show();

    return 0;
}