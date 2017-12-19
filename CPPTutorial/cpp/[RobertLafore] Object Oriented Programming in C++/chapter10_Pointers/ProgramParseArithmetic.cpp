#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80;     // length of expressions in chars
const int MAX = 40;     // size of stack


class Stack {
private:
    char stack[MAX];
    int top = 0;            // num at stack top
public:
    Stack() : top(0) { }
    void push(char var){ stack[++top] = var; }
    char pop() { return stack[top--]; }
    int getTop(){ return top; }
};


class Expression {
private:
    Stack s;
    char *pointerToString;
    int len;                // length of input string

public:
    Expression(char *strPtr) {
        pointerToString = strPtr;
        len = strlen(strPtr);
    }

    void parse () {
        char c;
        char lastValue;
        char lastOp;

        for (int i = 0; i < len; i++) {
            c = pointerToString[i];

            if (c >= '0' && c <= '9') {             // if digit
                s.push(c - '0');                    // save it
            } else if (c == '+' || c == '-' || c == '*' || c == '/') //if it is operator
            {
                if (s.getTop() == 1){               // if the first operator
                    s.push(c);                      // save it
                } else {                            // else if not the first operator,
                    lastValue = s.pop();            // get last value, get last operator
                    lastOp = s.pop();

                    if ( (c == '*' || c == '/') &&  // ...
                            (lastOp == '+' || lastOp == '-') ) {
                        s.push(lastOp);             // restore last op and value
                        s.push(lastValue);
                    } else {
                        switch (lastOp) {
                            case '+' : s.push(s.pop() + lastValue); break;
                            case '-' : s.push(s.pop() - lastValue); break;
                            case '*' : s.push(s.pop() * lastValue); break;
                            case '/' : s.push(s.pop() / lastValue); break;
                            default : cout << "\nUnknown operator"; break;
                        }
                    }
                    s.push(c); // after resolving last op and last val, save current op
                }
            } else {
                cout << "\nUnknown input character";
            }
        }
    }

    int solve() {
        char lastValue;

        while (s.getTop() > 1) {
            lastValue = s.pop();
            switch (s.pop()) { // lastOp
                case '+' : s.push(s.pop() + lastValue); break;
                case '-' : s.push(s.pop() - lastValue); break;
                case '*' : s.push(s.pop() * lastValue); break;
                case '/' : s.push(s.pop() / lastValue); break;
                default : cout << "\nUnknown operator"; break;
            }
        }
        return int(s.pop());        // last item on the stack is answer
    }
};


int main()
{
    char goAgain;
    char string[LEN];

    cout << "\nEnter an arithmetic expression "
                    "\nof the form 2+3*4/4-3."
                    "\nNo number may have more than one digit."
                    "\nDon't use any spaces or parantheses.\n";

    do {
        cout << "\nGo: ";
        cin >> string;
        Expression *ep = new Expression(string);
        ep->parse();
        cout << "\nThe numerical value is: " << ep->solve();
        delete ep;

        cout << "\nAgain? (y/n): ";
        cin >> goAgain;
    } while (goAgain == 'y');

    return 0;
}


