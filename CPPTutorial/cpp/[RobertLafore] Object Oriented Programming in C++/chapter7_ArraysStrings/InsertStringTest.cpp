#include <iostream>
#include <string>

using namespace std;


int main() {

    string result = "to be the question";
    string s2 = "the ";
    string s3 = "or not to be";

    result.insert(6, s2);
        cout << result << endl;
    result.insert(6, s3, 3, 4);
        cout << result << endl;
    result.insert(10, "that is cool", 8); // from 0-8 of this other string
        cout << result << endl;
    result.insert(10, "to be ");
        cout << result << endl;

    return 0;
}