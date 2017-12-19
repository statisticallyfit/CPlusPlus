#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H


#include <iostream>
using namespace std;


class Character
{
private:
    char c;

public:
    Character() {}
    Character(char aChar) : c(aChar) { }

    bool isAlphabetic() {

        return ((c >= 'a' && c <= 'z')
                || (c >= 'A' && c <= 'Z'));
    }

    void print(){
        cout << c;
    }
};

#endif // CHARACTER_CLASS_H