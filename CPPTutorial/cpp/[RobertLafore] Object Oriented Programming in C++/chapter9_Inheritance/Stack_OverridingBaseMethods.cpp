#include <iostream>
using namespace std;


class Stack
{
protected:
    enum { MAX = 3};
    int stack[MAX];
    int top;            // index to top of stack

public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        stack[++top] = value;
    }
    int pop(){
        return stack[top--];
    }
};


class SafeStack : public Stack{

public:
    void push(int value){
        if (top >= MAX - 1){ // see? top is protected so is available here in derived class
            cout << "\nError: stack is full";
            exit(1);
        }
        Stack::push(value);
    }
    int pop() {
        if (top < 0) {
            cout << "\nError: stack is empty\n";
            exit(1);
        }
        return Stack::pop();
    }
};


int main()
{
    SafeStack s1;

    s1.push(11);
    s1.push(22);
    s1.push(33);

    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop(); // oops popped one too many...
    cout << endl;

    return 0;
}