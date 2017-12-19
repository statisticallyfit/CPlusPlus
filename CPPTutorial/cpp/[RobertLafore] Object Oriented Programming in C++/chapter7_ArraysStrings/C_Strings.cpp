#include <iostream>
#include <iomanip>  // for setw()
using namespace std;


int main() {

    // Test 1
    const int MAX = 2000;
    char s1[MAX];

    cout << "Enter a string: ";
    //cin >> setw(MAX) >> str; // no more than (MAX - 1) chars is allowed
    cin.get(s1, MAX); //gets word with spaces
    cout << "You entered: " << s1 << endl;

    // Test 2
    char s2[] = "Farewell! Thou are too dear for my possessing!";
    cout << "Next string: " << s2 << endl;


    // Test 3: read multiple lines, terminate on $ character
    char s3[MAX];
    cout << "\nEnter a string: \n";
    cin.get(s3, MAX, '$');
    cout << "You entered:\n" << s3 << endl;

    return 0;
}