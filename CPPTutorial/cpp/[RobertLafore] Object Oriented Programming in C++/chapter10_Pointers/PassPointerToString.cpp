#include <iostream>
using namespace std;



void displayString(const char *pointerToString) {
    while (*pointerToString) { // while not at null char \0
        cout << *pointerToString++;
    }
    cout << endl;
}


int main() {
    //considered const already..
    char s1[] = "Idle people have the least leisure";

    const char *s2 = "Curiosity kills the cat";

    displayString(s1);
    displayString(s2);

    return 0;
}