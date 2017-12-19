#include <iostream>
#include <string>
#include <sstream>
using namespace std;


/**
 * Not good since you don't check the input value type
 */
void firstExample(){
    int i;

    cout << "Please enter an integer value: ";
    cin >> i;
    cout << "The value you entered is " << i;
    cout << " and its double is " << i*2 << endl;
}


void secondExample(){
    string str;

    cout << "What's your name? ";
    getline(cin, str);
    cout << "Hello " << str << endl;
    cout << "What is your favorite team? ";
    getline(cin, str);
    cout << "I like " << str << " too!" << endl;
}

/**
 * stringstream used to convert strings to numbers and vice versa
 */
void stringStreamExample() {
    string str;
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin, str);
    stringstream(str) >> price;
    cout << "Enter quantity: ";
    getline(cin, str);
    stringstream(str) >> quantity;
    cout << "Total price: " << price * quantity << endl;
}


int main() {
    //firstExample();
    //secondExample();
    //stringStreamExample();
}