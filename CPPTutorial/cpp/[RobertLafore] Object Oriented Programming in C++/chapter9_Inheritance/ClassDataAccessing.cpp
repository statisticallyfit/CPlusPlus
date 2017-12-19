#include <iostream>
using namespace std;



class A
{
private:
    int privDataA;
protected:
    int protDataA;
public:
    int pubDataA;
public:
    void print(){
        cout << "A!" << endl;
    }
};


class B : public A
{
public:
    void function(){
        //a = privDataA; //error, not accessible
        cout << "protDataA accessed from class B: " << protDataA << endl;
        cout << "pubDataA accessed from class B: " << pubDataA << endl;
        cout << "in class : print from B: "; A::print(); cout << endl;
    }
};


//private derivation effect is only evident from code of other functions (like 'main')
class C : private A
{
public:
    void function(){
        //privDataA // error
        cout << "protDataA accessed from class C: " << protDataA << endl;
        cout << "pubDataA accessed from class C: " << pubDataA << endl;
        cout << "in class : print from C: "; A::print(); cout << endl;
    }
};


int main()
{
    int integer;

    B b;
    //integer = b.privDataA; //error
    //integer = b.protDataA; //error since protected base member can only be accessed in derived class
    integer = b.pubDataA; // OK (A public to B)
    b.function();
    cout << "in main: "; b.print(); cout << endl;

    C c;
    //integer = c.privDataA; //error
    //integer = c.protDataA; //error, same reason as above
    //integer = c.pubDataA; // error (A is private to C)
    c.function();
    //c.print(); // error

    return 0;

}