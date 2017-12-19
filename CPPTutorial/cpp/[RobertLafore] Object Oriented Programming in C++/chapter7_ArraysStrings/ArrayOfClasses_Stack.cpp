#include <iostream>
using namespace std;

// Left off at page 285

class Stack {

private:
    enum {MAX = 10};
    int stack[MAX];
    int topItemNum;

public:
    Stack() {
        topItemNum = 0;
    }
    void push(int item) {
        // increments topItemNum then adds item at that index
        stack[++topItemNum] = item;
    }
    int pop() {
        // first returns the item then decrements topItemNum
        return stack[topItemNum--];
    }
};



int main() {

    Stack s1;

    s1.push(11);
    s1.push(22);
    cout << "1: " << s1.pop() << endl; //22
    cout << "2: " << s1.pop() << endl; //11
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    cout << "3: " << s1.pop() << endl; //66
    cout << "4: " << s1.pop() << endl; //55
    cout << "5: " << s1.pop() << endl; //44
    cout << "6: " << s1.pop() << endl; //33

    return 0;
}