#include <iostream>
#include <string>
#include <bits/algorithmfwd.h>

using namespace std;

int main() {
    string s1 = "123.000";     // should be 123.
    string s2 = "123.003400";  // should be 123.034

    //npos is static and is used to mean "until str end"
    s1.erase(s1.find_last_not_of("0") + 1, std::string::npos);
    cout << s1 << endl;
    cout << "The dot" << s1.substr(s1.size() - 1) << endl;

    s2.erase(s2.find_last_not_of("0") + 1, std::string::npos);
    cout << s2 << endl;
}