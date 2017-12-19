#include <iostream>
using namespace std;

class Pair
{
private:
    int x;
    int y;

public:
    Pair() : x(0), y(0) { }
    Pair(int xCoord, int yCoord) : x(xCoord), y(yCoord) { }

    int getX() { return x; }
    int getY() { return y; }
};



class Stack
{
protected:
    enum { MAX = 30};
    int stack[MAX];
    int top;            // index to top of stack

public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        cout << "Pushing element: " << value << endl;
        stack[++top] = value;
    }
    int pop(){
        cout << "Popping element: " << stack[top] << endl;
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




class PairStack : public SafeStack
{
public:
    void push (Pair pair) {
        SafeStack::push(pair.getX());
        SafeStack::push(pair.getY());
    }

    void pop () {
        SafeStack::pop();
        SafeStack::pop();
    }
};



int main()
{
    PairStack pstk;
    pstk.push(Pair(-1, 2));
    pstk.push(Pair(3, 4));
    pstk.pop();
    pstk.pop();

    return 0;
}