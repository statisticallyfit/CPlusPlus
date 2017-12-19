#include <iostream>
using namespace std;


class Person;
//void swapTwo(Person**, Person**);
void sortByName(Person**, int);
void sortBySalary(Person**, int);
void printArray(Person**, int);


class Person {
protected:
    string name;
    float salary;
public:
    Person(string personName, float personSalary) :
            name(personName), salary(personSalary)
    { }
    void set() {
        cout << "Enter name: "; cin >> name;
        cout << "Enter salary: "; cin >> salary;
    }

    void print() {
        cout << name << ", " << salary << endl;
    }

    string getName() { return name; }
    float getSalary() { return salary; }
};



/*
void swapTwo(Person **pp1, Person **pp2) {
    Person *tempPointerToPerson = *pp1;
    *pp1 = *pp2; //swapping pointers to a Person
    *pp2 = tempPointerToPerson;
    cout << "";
}*/


void sortByName(Person **ppp, int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++){
            Person **pp1 = ppp + i;
            Person **pp2 = ppp + j;
            if ((*pp1)->getName() > (*pp2)->getName() ) {
                //swapTwo(pp1, pp2);
                Person *tempPointerToPerson = *pp1;
                *pp1 = *pp2; //swapping pointers to a Person
                *pp2 = tempPointerToPerson;
                cout << "";
            }
        }
    }
}


void sortBySalary(Person **ppp, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++){
            Person **pp1 = ppp + i;
            Person **pp2 = ppp + j;
            if ( (*pp1)->getSalary() > (*pp2)->getSalary() ) {
                Person *tempPointerToPerson = *pp1;
                *pp1 = *pp2;
                *pp2 = tempPointerToPerson;
            }
        }
    }
}


void printArray(Person **pp, int n){ // first * means array, second * means pointer to Person
    for (Person **pointer = pp; pointer < pp + n; pointer++){
        (*pointer)->print();
    }
}

int main()
{
    int numCurrentPeople = 7;
    Person p1("Marina", 95.90);
    Person p2("Jocelyn", 100);
    Person p3("Elizabeth", 10);
    Person p4("Sasha", 98);
    Person p5("Chiara", 34.67);
    Person p6("Bianca", 80);
    Person p7("Aisling", 20);

    Person *pp1 = &p1;
    Person *pp2 = &p2;
    Person *pp3 = &p3;
    Person *pp4 = &p4;
    Person *pp5 = &p5;
    Person *pp6 = &p6;
    Person *pp7 = &p7;

    Person *ppp[] = {pp1, pp2, pp3, pp4, pp5, pp6, pp7};

    cout << endl << "Unsorted list: " << endl;
    printArray(ppp, numCurrentPeople);

    cout << "\n\nSorted list by name: " << endl;
    sortByName(ppp, numCurrentPeople);
    printArray(ppp, numCurrentPeople);

    cout << "\n\nSorted by salary: " << endl;
    sortBySalary(ppp, numCurrentPeople);
    printArray(ppp, numCurrentPeople);

    /*int numCurrentPeople = 0;
    char choiceInput;

    do {
        ppp[numCurrentPeople] = new Person;
        ppp[numCurrentPeople]->set();
        numCurrentPeople++;
        cout << "Enter another (y/n)?";
        cin >> choiceInput;
    } while(choiceInput == 'y');*/

    /*cout << endl << "Unsorted list: " << endl;
    printArray(ppp, numCurrentPeople);

    cout << "\n\nSorted list: " << endl;
    sortByName(ppp, numCurrentPeople);
    printArray(ppp, numCurrentPeople);
    cout << endl;*/

    return 0;
}