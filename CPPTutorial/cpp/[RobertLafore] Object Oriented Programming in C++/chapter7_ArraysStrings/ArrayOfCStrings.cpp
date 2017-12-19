#include <iostream>
using namespace std;


int main() {

    const int DAYS = 7;
    const int MAX = 10; //since Wednesday is longest letters PLUS \0 character

    char weekdays[DAYS][MAX] = {"Sunday", "Monday", "Tuesday",
                                "Wednesday", "Thursday",
                                "Friday", "Saturday"};
    for (int i = 0; i < DAYS; i++){
        cout << weekdays[i] << endl;
    }

    return 0;
}