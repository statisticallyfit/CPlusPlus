#include <iostream>
using namespace std;

/**
 * Arguments are passed by reference.
 * Normally, if not pointers or objects, they are passed by value only
 * This function makes the ints act like Java Integer objects (they are changed)
 * More efficient than the copying by value
 */
void duplicate(int& a, int& b, int& c) {
    a *= 2;
    b *= 2;
    c *= 2;
}

/**
 * This method is more efficient because copies by reference
 * rather than by value
 * Actual arguments are not changed because of the const keyword
 * So the process is more efficient and values are not truly changed!
 *
 * inline tells compiler to insert the function's code when the function
 * is called. This is more efficient than the pathway the compiler takes
 * when the function has no inline keyword.
 */
inline string concatenate(const string& a, const string& b) {
    return a + b;
}



int divide(int a, int b = 2) {
    return (a / b);
}


/**
 * recursive
 */
long factorial(long number) {
    if(number > 1)
        return(number * factorial(number - 1));
    else
        return 1;
}



int main() {
    //duplicate()
/*    int x = 1, y = 3, z = 7;

    duplicate(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z;*/

    /*// concatenate() area
    string firstStr = "The little dog laughed to see such sport ";
    string secondStr = "and the dish ran away with the spoon!";
    cout << concatenate(firstStr, secondStr) << endl;
    cout << firstStr << endl;
    cout << secondStr << endl;*/


    /*//default parameter example
    cout << divide(12) << "\n";
    cout << divide(20, 4) << "\n";*/

    //recursive example
    long number = 9;
    cout << number << "! = " << factorial(number);

    return 0;
}