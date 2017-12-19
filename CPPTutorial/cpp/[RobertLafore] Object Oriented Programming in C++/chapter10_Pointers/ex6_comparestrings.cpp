#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

//template <typename CHAR_TYPE>
int compareStrings(char *s1, char *s2){

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = (len1 < len2) ? len1 : len2;

/*    s1 = const_cast<char*>(s1);
    s2 = const_cast<char*>(s2);*/
    // @todo: is it possible to const-cast here rather than in main function?

    for (char *p1 = s1, *p2 = s2;
            p1 < s1 + len, p2 < s2 + len;
            p1++, p2++){

        if (*p1 < *p2){ // these are chars
            return -1;
        } else if (*p1 > *p2){
            return 1;
        }
    }

    if (len1 == len2){
        return 0;
    } else if (len1 < len2){
        return -1;
    } else {
        return 1;
    }
}


int main() {

    assert(compareStrings(const_cast<char*>("bat"), const_cast<char*>("cat")) == -1);
    assert(compareStrings(const_cast<char*>("zoo"), const_cast<char*>("boo")) == 1);
    assert(compareStrings(const_cast<char*>("hi there"), const_cast<char*>("hi there")) == 0);

    assert(compareStrings(const_cast<char*>("bat"), const_cast<char*>("batting")) == -1);
    assert(compareStrings(const_cast<char*>("batting"), const_cast<char*>("bat")) == 1);

    return 0;
}