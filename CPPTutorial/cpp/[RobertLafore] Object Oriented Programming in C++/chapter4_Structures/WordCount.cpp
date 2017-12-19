/*
#include <iostream>
#include <ncurses.h> // for getche() to get character

using namespace std;


//enum itsAWord {NO, YES}; // NO = 0, YES = 1 (true)

int main() {

    itsAWord isWord = NO;  // set to false

    char c = 'a';
    int wordCount = 0;

    cout << "Enter a phrase: " << endl;

    do {
        c = getch();
        if (c == ' ' || c == '\r'){
            if (isWord == YES) {
                wordCount++;
                isWord = NO;
            }
        } else if (isWord == NO){
            isWord = YES;
        }
    } while (c != '\r');

    cout << "\n--- Word count is " << wordCount << "---\n" << endl;

    return 0;
}*/
