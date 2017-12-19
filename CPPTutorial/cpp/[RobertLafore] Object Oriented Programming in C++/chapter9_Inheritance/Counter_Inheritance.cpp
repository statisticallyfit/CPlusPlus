#include <iostream>
using namespace std;


class Counter {

    // protected means derived class data member can change
    // this base class protected data member.
protected:
    unsigned int count;

public:
    Counter() : count(0) { }
    Counter(int c) : count(c) { }

    unsigned int getCount() const { return count; }
    void setCount(int c) { count = c; }

    /** ++x NOT same as x++ */
    Counter operator ++ () {
        return Counter(++count);
    }
};



class CountDown : public Counter {

public:
    CountDown() : Counter() {}
    CountDown(int c) : Counter(c) {}
    //CountDown(CountDown countDown) : Counter(countDown) {}

    /** Decr x PREFIX */
    CountDown operator -- () {
        return CountDown(--count);
    }
};




int main() {

    CountDown c1;
    CountDown c2(100);

    cout << "\nc1 = " << c1.getCount();
    cout << "\nc2 = " << c2.getCount();

    ++c1; ++c1; ++c1;
    cout << "\nc1 = " << c1.getCount();

    --c1; --c1;
    cout << "\nc1 = " << c1.getCount() << endl;
    --c2; --c2;
    cout << "\nc2 = " << c2.getCount() << endl;

    CountDown c3 = --c2; // one-arg constructor is used here
    cout << "\nc3 = " << c3.getCount() << endl;

    return 0;
}