#ifndef STRING__CLASS_H
#define STRING_CLASS_H


#include <iostream>
#include <string.h>
#include <vector>
#include "Character.h"

using namespace std;




class String
{
private:
    char *characters;

    void copyString(const char *s) {
        characters = new char[strlen(s) + 1];
        strcpy(characters, s);
    }

public:
    String() {
        characters[0] = '\0';
    }

    String(const char *s) {
        copyString(s); // @todo: ---- understand why reassignment did not work (body of copyString here), without = operator
    }

    ~String(){
        cout << "Deleting str.\n";
        delete[] characters;
    }

    void operator = (const char *s) {
        delete [] characters;
        copyString(s);
    }

    char operator [] (int i){
        return characters[i];
    }

    String operator + (String other) {
        char totalChars[length() + other.length()];
        int i = 0;
        for ( ; i < length(); i++){
            totalChars[i] = characters[i]; // head copy what 's' contains
        }
        for (int j = 0; j < other.length(); j++, i++){
            totalChars[i] = other[j]; // keep adding to totalChars the total of other
        }
        totalChars[i] = '\0'; //add null char

        return String(totalChars);
    }

    void print() {
        cout << characters << endl;
    }

    int length() {
        return strlen(characters);
    }

    bool equals(String other)
    {
        int i = 0;
        while (characters[i] == other[i] &&
               characters[i] != '\0' && other[i] != '\0'){
            ++i;
        }
        return (characters[i] == '\0' && other[i] == '\0');
    }

    /**
     * Returns -1 if head word is past the second
     * Returns 1 if head word is next second
     * Returns 0 if they are the same
     */
    int compare (String other)
    {
        int i = 0, answer;

        while (characters[i] == other[i] && characters[i] != '\0' && other[i] != '\0'){
            i++;
        }

        if (characters[i] < other[i]){
            answer = -1;
        } else if (characters[i] > other[i]){
            answer = 1;
        } else {
            answer = 0;
        }

        return answer;
    }


    String substring (int startIndex,
                      int numChars)
    {
        char resultString[length()];
        int lastIndex = length() - 1;
        startIndex = (startIndex < 0) ? 0 : startIndex;
        int stopIndex = 0;

        if (startIndex + numChars - 1 > lastIndex) {
            stopIndex = lastIndex;
        } else {
            stopIndex = startIndex + numChars - 1;
        }

        int i = startIndex;
        for ( ; i <= stopIndex; i++) {
            resultString[i - startIndex] = characters[i];
        }
        resultString[i - startIndex] = '\0';

        return String(resultString);
    }


     /**
      * @todo: ---- potential problem with String found constructor
      * Finds a piece of a searchstring in the instance variable. Returns
      * the found string's start index in the instance variable.
      */
     int find (String locate)
     {
         String found;

         for (int i = 0; i < length(); i++)
         {
             int len = locate.length();
             found = substring(i, len);

             if (found.equals(locate)){
                 return i;
             }
         }
         return -1; // string not found in source
     }


    void remove (int startIndex, int numChars)
    {
        int lastIndex = length() - 1;
        startIndex = (startIndex < 0) ? 0 : startIndex;
        int stopIndex = 0;

        // Getting the bound Indexes of the bit to pop
        if (startIndex + numChars - 1 > lastIndex) {
            stopIndex = lastIndex;
        } else {
            stopIndex = startIndex + numChars - 1;
        }

        // Copy over stuff next stopIndex over the bit to pop
        // and clean remainder with \0
        char temp[length()];
        strcpy(temp, characters);

        for (int i = stopIndex + 1; i <= lastIndex; i++)
        {
            temp[startIndex] = temp[i];
            startIndex++;
        }
        temp[startIndex] = '\0';

        characters[0] = '\0'; //remove everything
        strcpy(characters, temp);
    }


    void insert (String put, int pos)
    {
        if (pos >= 0 && pos <= length())
        {
            String rememberTail = substring(pos, length() - pos);
            String rememberHead = substring(0, pos); // all chars before pos
            String total = rememberHead + put + rememberTail;

            // copy into 's'
            characters[0] = '\0'; // clear all
            // make total an array
            char temp[total.length()];
            for (int i = 0; i < total.length(); i++){
                temp[i] = total[i];
            }
            strcpy(characters, temp); //the big idea
        }
    }


    bool replace (String what, String with)
    {
        int whatIndex = find(what);

        if (whatIndex != -1)
        {
            remove(whatIndex, what.length());
            insert(with, whatIndex);
            return true;
        }
        return false;
    }


    void replaceAll (String what, String with) {
        bool stillFound = true;
        do {
            stillFound = replace(what, with);
        } while (stillFound);
    }


    void concat(String other)
    {
        char temp[length() + other.length()];

        for (int i = 0; i < length(); i++) {
            temp[i] = characters[i];
        }
        for (int i = length(); i < other.length(); i++){
            temp[i] = other[i];
        }
        copyString(temp);
    }


    int toInteger(){

        int intValue, result = 0;
        int index = 0;
        bool wasNegative = false;

        if (characters[0] == '-') {
            wasNegative = true;
            index = 1;
        } else {
            index = 0;
        }

        for (int i = index; characters[i] >= '0' && characters[i] <= '9'; i++){
            intValue = characters[i] - '0';
            result = result * 10 + intValue;
        }

        if (wasNegative) {
            result *= -1;
        }

        return result;
    }


    void toUppercase ()
    {
        for (int i = 0; i < length(); i++)
        {
            Character c = characters[i];
            if (c.isAlphabetic())
            {
                if(!isupper(characters[i])){
                    char letter = characters[i] - 'a' + 'A';
                    characters[i] = letter;
                }
            }
        }
    }


    void toLowercase ()
    {
        for (int i = 0; i < length(); i++)
        {
            Character c = characters[i];
            if (c.isAlphabetic())
            {
                if(!islower(characters[i]))
                {
                    char letter = characters[i] - 'A' + 'a';
                    characters[i] = letter;
                }
            }
        }
    }


    /**
     * Returns leftmost characters in the instance variable.
     * The amount of leftmost chars = numOfLeftmost
     */
    String left (int numOfLeftmost)
    {
        if (numOfLeftmost <= length())
        {
            char leftChars[numOfLeftmost];
            for (int i = 0; i < numOfLeftmost; i++)
            {
                leftChars[i] = characters[i];
            }
            leftChars[numOfLeftmost] = '\0';

            return String(leftChars);
        }
        //else return empty string
        return String("");
    }


    String right (int numOfRightmost)
    {
        if (numOfRightmost <= length())
        {
            char rightChars[numOfRightmost];
            int startIndex = length() - numOfRightmost;

            for (int i = startIndex, j = 0; i < length(), j < numOfRightmost; i++, j++){
                rightChars[j] = characters[i];
            }
            rightChars[numOfRightmost] = '\0';
            return String(rightChars);
        }
        //else return empty string
        return String("");
    }


    /**
     * Returns middle 'num' chars of 's' starting from
     * character number 'targetIndex'
     */
    String mid (int midStartIndex, int numOfMiddlemost)
    {
        if (midStartIndex >= 0 && midStartIndex < length() &&
                numOfMiddlemost <= length())
        {
            return substring(midStartIndex, numOfMiddlemost);
        }
        return String("");
    }

    void readLine() {

        char letter;
        //char charArray[1];
        int i = 0;

        do {
            letter = getchar();
            characters[i] = letter;
            ++i;
        } while (letter != '\n');

        characters[i - 1] = '\0';
    }
};



#endif // STRING_CLASS_H
