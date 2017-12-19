#include <iostream>
#include <cstring>
using namespace std;


class String {

private:
    enum {SIZE = 80 };
    char string[SIZE];

public:
    String() {
        string[0] = '\0';
    }

    String(char s[]) {
        strcpy(string, s);
    }

    void display() {
        cout << string;
    }

    void concatenate(String other) {
        if (strlen(string) + strlen(other.string) < SIZE)
            strcat(string, other.string);
        else
            cout << "\nString too long";
    }
};


int main() {

    String s1("Merry Christmas! ");
    String s2 = "Season's Greetings!"; //alternate form of constructer 2
    String s3;

    cout << "\ns1 = "; s1.display();
    cout << "\ns2 = "; s2.display();
    cout << "\ns3 = "; s3.display();

    s3 = s1;
    cout << "\ns3 = "; s3.display();

    s3.concatenate(s2);
    cout << "\ns3 = "; s3.display();
    cout << endl;

    return 0;
}