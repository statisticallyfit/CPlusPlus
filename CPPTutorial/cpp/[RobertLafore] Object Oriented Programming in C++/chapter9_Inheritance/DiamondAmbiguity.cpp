#include <iostream>



class A
{
public:
    void func();
};

class B : public A { };
class C : public A { };
class D : public B, public C { };


int main()
{
    D d;
    //d.func(); //ambiguous, won't compile
    return 0;
}