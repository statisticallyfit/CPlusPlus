#include <iostream>
using namespace std;

int greatestCommonDivisor(int num, int denom) {
    if (denom == 0){
        return num;
    }
    return greatestCommonDivisor(denom, num % denom);
}

int main() {

    int n1 = 0;
    int n2 = 0;

    printf("Enter two numbers: ");
    scanf("%i %i", &n1, &n2);

    printf("GCD: %i", greatestCommonDivisor(n1, n2));

    return 0;
}