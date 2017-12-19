#include <iostream>
#include <string.h> // for strcpy(), strcat()
#include <stdlib.h> // for exit()

using namespace std;


class StringHelper {

private:
    static const int SIZE = 80;
    char str[SIZE];

public:
    StringHelper() {
        strcpy(str, "");
    }
    StringHelper(char s[]) {
        strcpy(str, s);
    }

    char* getString() {
        return str;
    }
    void setString(char s[]) {
        strcpy(str, s);
    }

    void display() {
        cout << str;
    }

    void input() {
        cin >> str;
    }

    StringHelper operator + (StringHelper other) const {
        StringHelper temp;
        if (strlen(str) + strlen(other.getString()) < SIZE) {
            strcpy(temp.getString(), str);
            strcat(temp.getString(), other.getString());
        }
        else {
            cout << "\nString overflow"; exit(1);
        }

        return temp;
    }

    bool operator == (StringHelper other) const {
        return (strcmp(str, other.getString()) == 0);
    }

    operator char*() {
        return str;
    }
};


int main() {

    // this doesn't work since s is StringHelper then why say c is c-string when in fact they must
    // be the same type? not true conversion to string class...
    /*StringHelper s;
    char c[] = "the c-string";
    strcpy(s, c);*/

    /*char c1[] = "Merry Christmas! ";
    StringHelper s1(c1);
    char c2[] = "Happy new year!";
    StringHelper s2(c2);
    StringHelper s3;

    // Testing addition
    cout << "\ns1 = "; s1.display();
    cout << "\ns2 = "; s2.display();
    cout << "\ns3 = "; s3.display();

    s3 = s1 + s2;
    cout << "\ns3 = "; s3.display(); cout << endl;

    // Testing == operator
    char c4[] = "yes";
    s1.setString(c4);
    char c5[] = "no";
    s2.setString(c5);

    cout << "\nEnter yes or no: ";
    s3.input();

    if (s3 == s1)
        cout << "You typed yes\n";
    else if (s3 == s2)
        cout << "You typed no\n";
    else
        cout << "You didn't follow instructions\n";
*/

    // Testing conversion from C-string to StringHelper class
    StringHelper s4 = "Hi";
    char aStr[] = "Joyeux Noel! ";
    //s4 = aStr; // convert C-string to StringHelper
    s4.display();

    /*char aStr2[] = "Bonne Annee!";
    StringHelper s5 = aStr;
    cout << static_cast<char*>(s5); //convert StringHelper to C-string
    cout << endl;*/

    return 0;
}
