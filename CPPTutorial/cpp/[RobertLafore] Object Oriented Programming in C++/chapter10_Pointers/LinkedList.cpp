#include <iostream>
#include <memory>
using namespace std;


struct Node {
    int value;
    Node *next;

    // Constructors
    Node (Node *n = 0) : next(n)
    { }
    Node (int v, Node *n = 0) : value(v), next(n)
    { }
};



class LinkedList {
private:
    Node *head;
public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList(){
        Node *current = head;

        while (current != NULL){
            Node *next = current->next; // so these pointer nodes in list are in memory together, adjacent?
            delete current;
            current = next;
            cout << "";
        }
        cout << "\nDestroyed linked list...\n";
    }

    void addTop(int dataValue){
        Node *newLink = new Node; // @todo: ---- need to use delete or is it automatic? ---> deleted by linkedlist destructor
        newLink->value = dataValue;
        newLink->next = head;
        head = newLink;
    }

    void addEnd(int dataValue){

        Node *newEnd = new Node(dataValue);
        if (head == NULL){
            head = newEnd;
        } else {
            Node *current = head;
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newEnd;
            cout << "";
        }
        // @todo: why do I have to initialize a pointer Node rightaway? Why doesn't it work this way:
        // @todo: .... initializing a normal Node then assigning its address to current->next ?
        /*Node *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        Node *end = head; // just to have a value here
        /*//*end = {dataValue, NULL};
        end->value = dataValue;
        end->next = current->next; // setting end's next to NULL
        current->next = end;
        print();*/
    }

    void print(){
        Node *current = head;
        while (current != NULL) {
            cout << current->value << endl;
            current = current->next;
        }
    }
};



int main() {
    LinkedList list; // adds to itself like a Stack, not Queue

    /*list.addTop(25);
    list.addTop(36);
    list.addTop(49);
    list.addTop(64);

    cout << "Printing after addTop: " << endl;
    list.print();*/

    cout << "Printing after addEnd 1 and 2: " << endl;
    list.addTop(5);
    list.addTop(6);
    list.addTop(7);
    list.addEnd(8);
    list.addEnd(1);
    list.addEnd(2);
    list.addEnd(3);
    list.addEnd(4);

    list.print();

    /*cout << "Printing after addEnd 99: " << endl;
    list.addEnd(99);
    list.print();*/

    /*list.addEnd(49);
    list.addEnd(64);

    list.print();*/

    return 0;
}