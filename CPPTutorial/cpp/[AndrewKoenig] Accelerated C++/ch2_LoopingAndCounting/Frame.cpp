// Andrew Koenig book

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter your first name: ";

    string name;
    cin >> name;

    // build the message
    const string greeting = "Hello, " + name + "!";

    int rowSpaces = 0, colSpaces = 0;
    cout << "How many row spaces?: ";
    cin >> rowSpaces;
    cout << "How many column spaces?: ";
    cin >> colSpaces;
    const int rows = rowSpaces * 2 + 3; // total rows including spaces
    const string::size_type cols = greeting.size() + colSpaces * 2 + 2;
    cout << endl;

    //write the rows of output
    // invariant: we have written r rows so far
    for(int r = 0; r != rows; r++) {
        string::size_type c = 0;

        //invariant: we have written c characters so far in the current row
        while(c != cols) {
            // is it time to write the greeting?
            if(r == rowSpaces + 1 && c == colSpaces + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                //are we on the border?
                if(r == 0 || r == rows - 1 || c == 0 || c == cols-1) {
                    cout << "*";
                    //c++;
                } else {
                    //long amount = 2 * colSpaces + greeting.size();
                    //string spaces(amount, ' ');
                    //cout << spaces;
                    cout << " ";
                    //c += amount;
                }
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}