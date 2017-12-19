#include <iostream>
#include <cstring> // for strlen
using namespace std;


class StringNew {
private:
    char *str;
public:
    StringNew(const char *s) {
        copyString(s); // @todo: ---- understand why reassignment did not work (body of copyString here), without = operator
    }

    void operator =(const char *s) {
        delete [] str;
        copyString(s);
    }

    void copyString(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    ~StringNew(){
        cout << "Deleting str.\n";
        delete[] str;
    }

    void print() {
        cout << str << endl;
    }
};



int main() {

    StringNew s1 = "Today is a beautiful day";
    s1.print();
    s1 = "This is an even longer string to test reassignment capabilities";
    s1.print();

    // @todo: ---- after this code, why does SIGABRT print when using debugger and doesn't when running?
    StringNew s2 = s1;
    s2.print();

    //StringNew s2 = "entirely different";
    //s2.print();

    return 0;
}