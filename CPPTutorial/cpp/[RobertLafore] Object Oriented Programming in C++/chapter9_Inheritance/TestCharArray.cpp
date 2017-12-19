#include <iostream>
#include <string.h>

using namespace std;

class STRING
{
private:
    char characters[3];

    /**
     * Copies the 'stuffToCopy' into 'characters'
     */
    void copy(const char stuffToCopy[]){
        strcpy(characters, stuffToCopy);
    }

public:
    STRING () { }
    STRING (const char str[]){
        copy(str);
    }
    STRING (STRING const *aStr) { //compiler complained it needed a pointer!! ??
        STRING arg = *aStr;
        for (int i = 0; i < arg.len(); i++){
            characters[i] = arg[i];
        }
    }

    void print(){
        cout << characters << endl;
    }

    int len(){
        return strlen(characters);
    }

    char operator [] (int i){
        return characters[i];
    }

    STRING operator + (STRING other) {
        char totalChars[len() + other.len()];
        int i = 0;
        for ( ; i < len(); i++){
            totalChars[i] = characters[i]; // first copy what 's' contains
        }
        for (int j = 0; j < other.len(); j++, i++){
            totalChars[i] = other[j]; // keep adding to totalChars the total of other
        }
        totalChars[i] = '\0'; //add null char

        return STRING(totalChars);
    }
};


int main()
{
    char small[5];
    char big[40];

    strcpy(small, "stars");
    strcpy(big, "the stars are shining bright tonight");

    STRING s1 = "\nlonger than set default";
    s1.print();
    s1 = "hi";
    s1.print();
    s1 = "the twinkle little star story i like to read";
    s1.print();

    return 0;
}