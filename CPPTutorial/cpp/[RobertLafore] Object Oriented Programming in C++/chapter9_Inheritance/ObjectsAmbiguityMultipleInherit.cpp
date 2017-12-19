#include <iostream>
using namespace std;


class A
{
public:
    void show() {
        cout << "Class A\n";
    }
};


class B
{
public:
    void show() {
        cout << "Class B\n";
    }
};


class C : public A, public B
{

};



int main()
{
    C c;
    // c.show(); // ambiguous, will not compile
    c.A::show();
    c.B::show();

    return 0;
}