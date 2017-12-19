#include <iostream>
#include <string>
using namespace std;



class Person {
protected:
    string name;
public:
    void setName() {
        cout << "Enter name: "; cin >> name;
    }
    void printName() {
        cout << endl << name;
    }
    string getName() { return name; }
};


void swap(Person **pp1, Person **pp2) {
    if ( (*pp1)->getName() > (*pp2)->getName() ) {
        Person *tempPointerToPerson = *pp1;
        *pp1 = *pp2; //swapping pointers to a Person
        *pp2 = tempPointerToPerson;
        cout << "";
    }
}

void bubbleSort(Person **pp, int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++){
            swap(pp+i, pp+j);
        }
    }
}


void printArray(Person **pp, int n){ // first * means array, second * means pointer to Person
    for (int i = 0; i < n; i++){
        pp[i]->printName();
    }
}

int main(){
    Person *personPointers[100]; //array of pointers to person
    int numPeople = 0;
    char choiceInput;

    do {
        personPointers[numPeople] = new Person;
        personPointers[numPeople]->setName();
        numPeople++;
        cout << "Enter another (y/n)?";
        cin >> choiceInput;
    } while(choiceInput == 'y');

    cout << "\nUnsorted list: ";
    printArray(personPointers, numPeople);

    cout << "\nSorted list: ";
    bubbleSort(personPointers, numPeople);
    printArray(personPointers, numPeople);
    cout << endl;

    return 0;
}