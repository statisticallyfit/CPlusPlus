#include <iostream>
#include <cstring>
using namespace std;


int main() {

    char s1[] = "Oh, Captain, my Captain! "
                "our fearful trip is done";
    const int MAX = 80;
    char s2[MAX];
    char s3[MAX];
    char s4[MAX];

    int i;
    for (i = 0; i < strlen(s1); i++){
        s2[i] = s1[i];
    }
    s2[i] = '\0'; //insert NULL at end

    cout << s2 << endl;

    // or copy the easy way:
    strcpy(s3, s1);
    cout << s3 << endl;

    // copy with equals?:
    //s4 = s3; // invalid
    //cout << s4 << endl;

    return 0;
}