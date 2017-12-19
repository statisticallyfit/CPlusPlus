#include <iostream>
using namespace std;


const int LEN = 80; // max length of names




class Student
{
private:
    char schoolName[LEN];
    char highestDegree[LEN];
public:
    void getEdu(){
        cout << "\tEnter name of school or university: ";
        cin >> schoolName;
        cout << "\tEnter highest degree earned\n";
        cout << "\t\t(highschool, bachelor's, master's PhD): ";
        cin >> highestDegree;
    }

    void putEdu() const {
        cout << "\n\tSchool or university: " << schoolName;
        cout << "\n\tHighest degree earned: " << highestDegree;
    }
};




class Employee
{
private:
    char name[LEN];
    unsigned long number;

public:
    void getData() {
        cout << "\n\tEnter last name: "; cin >> name;
        cout << "\tEnter number: "; cin >> number;
    }

    void putData() const {
        cout << "\n\tName: " << name;
        cout << "\n\tNumber: " << number;
    }
};



// multiple inheritance
class Manager : private Employee, private Student
{
private:
    char title[LEN];
    double dues;

public:
    void getData() {
        Employee::getData();
        cout << "\tEnter title: ";          cin >> title;
        cout << "\tEnter golf club dues: "; cin >> dues;
        Student::getEdu();
    }

    void putData() const{
        Employee::putData();
        cout << "\n\tTitle: " << title;
        cout << "\n\tGolf club dues: " << dues;
        Student::putEdu();
    }
};




class Scientist : private Employee, private Student
{
private:
    int numPublications;

public:
    void getData() {
        Employee::getData();
        cout << "\tEnter number of pubs: "; cin >> numPublications;
        Student::getEdu();
    }

    void putData() const {
        Employee::putData();
        cout << "\n\tNumber of publications: " << numPublications;
        Student::putEdu();
    }
};





class Laborer : public Employee
{

};




class Foreman : public Laborer
{
private:
    float quotas; // percent of quotas met successfully
public:
    void getData() {
        Laborer::getData();
        cout << "\tEnter quotas: "; cin >> quotas;
    }

    void putData() const {
        Laborer::putData();
        cout << "\n\tQuotas: " << quotas;
    }
};




int main()
{
    Manager m1, m2;
    Scientist s1;
    Laborer l1;
    Foreman f1;

    // Enter data for some employees
    cout << endl;
    cout << "\nEnter data for manager 1";
    m1.getData();
    cout << "\nEnter data for manager 2";
    m2.getData();
    cout << "\nEnter data for scientist 1";
    s1.getData();
    cout << "\nEnter data for laborer 1";
    l1.getData();
    cout << "\nEnter data for foreman 1";
    f1.getData();

    // Display data for several employees
    cout << "\nData on manager 1";
    m1.putData();
    cout << "\nData on manager 2";
    m2.putData();
    cout << "\nData on scientist 1";
    s1.putData();
    cout << "\nData on laborer 1";
    l1.putData();
    cout << "\nData on foreman 1";
    f1.putData();
    cout << endl;

    return 0;
}