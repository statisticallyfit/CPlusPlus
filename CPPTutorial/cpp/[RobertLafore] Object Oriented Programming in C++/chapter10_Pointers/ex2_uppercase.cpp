#include <iostream>
#include <string.h>

using namespace std;


void upIt(char *string){
    char letter;
    char *traverser = string;
    char *end = string + strlen(string);

    for (; traverser < end; traverser++){
        *traverser = toupper(*traverser);
    }
}


int main() {

    string inputString;

    cout << "\nEnter a string: " << endl;
    getline(cin, inputString);
    char *input = new char[inputString.length()];
    inputString.copy(input, inputString.length());

    upIt(input);

    cout << "\nTo uppercase: " << input << endl;
    delete[] input;

    return 0;
}