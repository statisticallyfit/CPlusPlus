#include <iostream>
using namespace std;


class Counter {

private:
    unsigned int count;
public:
    Counter() : count(0)
    {}
    Counter(int c) : count(c)
    {}

    unsigned int getCount() const { return count; }
    void setCount(int c) { count = c; }

    // prefix
    Counter operator ++ (){
        //increment count, then return temp object with count value
        return Counter(++count);
        /*++count;
        Counter temp(count);
        return temp;*/
    }

    // postfix
    Counter operator ++ (int) {
        // return object then increment count
        return Counter(count++);
        /*count++;
        Counter temp(count);
        return temp;*/
    }
};


int main() {

    Counter c1, c2, temp;

    cout << "BEFORE: ";
    cout << "\nc1 = " << c1.getCount();
    cout << "\nc2 = " << c2.getCount();

    /** Testing the prefix operator */
    ++c1;
    temp = ++c2;

    cout << "\n\n\nAFTER: ";
    cout << "\nPrefix Operator: ";
    cout << "\nc1 = " << c1.getCount();
    cout << "\nc2 = " << c2.getCount();
    cout << "\ntemp = " << temp.getCount();

    c1.setCount(0);
    c2.setCount(0);
    temp.setCount(0);

    /** Testing the postfix operator */
    c1++;
    temp = c2++;

    cout << "\n\nPostfix Operator: ";
    cout << "\nc1 = " << c1.getCount();
    cout << "\nc2 = " << c2.getCount();
    cout << "\ntemp = " << temp.getCount(); cout << endl;

    return 0;
}