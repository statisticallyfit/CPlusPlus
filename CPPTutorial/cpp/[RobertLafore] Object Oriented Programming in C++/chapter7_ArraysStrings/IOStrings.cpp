#include <iostream>
#include <string>
using namespace std;


int main() {

    string fullName, nickName, address;
    string greeting("Hello, ");

    cout << "Enter your full name: ";
    getline(cin, fullName); //reads embedded blanks
    cout << "Your full name is: " << fullName << endl;

    cout << "Enter your nickname: ";
    cin >> nickName;

    greeting += nickName;
    cout << greeting << endl;

    cout << "Enter your address on separate lines\n";
    cout << "Terminate with '$'\n";
    getline(cin, address, '$');
    cout << "Your address is: " << address << endl;

    return 0;
}