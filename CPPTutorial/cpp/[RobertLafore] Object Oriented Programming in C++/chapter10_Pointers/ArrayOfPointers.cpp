#include <iostream>
using namespace std;

const int DAYS = 7;



int main() {

    // @todo: ---- why need to write "const" in front to avoid deprecated conversion error?
    const char *arrStrPtrs[DAYS] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};

    for (int i = 0; i < DAYS; i++){
        cout << arrStrPtrs[i] << endl;
    }

    return 0;
}