#include <iostream>
#include <cstring>
using namespace std;


int main() {

    const char *str = "a short string";
    int len = strlen(str);

    char *ptr = new char[len + 1];

    strcpy(ptr, str);

    cout << "ptr = " << ptr << endl;
    delete[] ptr;
    cout << "ptr = " << ptr << endl;

    return 0;
}