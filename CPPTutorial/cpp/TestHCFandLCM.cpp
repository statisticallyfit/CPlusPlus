#include <iostream>
using namespace std;


int main() {
    int a, b, c;

    printf("Enter two numbers.\n\n");
    printf("Enter first number: ");
    scanf("%i", &a);
    printf("Enter second number: ");
    scanf("%i", &b);

    c = a * b;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    cout << "HCF = " << a << endl;
    cout << "LCM = " << c / a << endl;

    return 0;
}