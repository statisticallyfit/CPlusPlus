#include <iostream>
using namespace std;



class Student
{
private:
    string schoolName;
    string highestDegree;
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
    string name;
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



class Manager
{
private:
    string title;
    double dues;
    Employee emp;
    Student stu;

public:
    void getData() {
        emp.getData();
        cout << "\tEnter title: ";          cin >> title;
        cout << "\tEnter golf club dues: "; cin >> dues;
        stu.getEdu();
    }

    void putData() const{
        emp.putData();
        cout << "\n\tTitle: " << title;
        cout << "\n\tGolf club dues: " << dues;
        stu.putEdu();
    }
};




class Scientist
{
private:
    int numPublications;
    Employee emp;
    Student stu;

public:
    void getData() {
        emp.getData();
        cout << "\tEnter number of pubs: "; cin >> numPublications;
        stu.getEdu();
    }

    void putData() const {
        emp.putData();
        cout << "\n\tNumber of publications: " << numPublications;
        stu.putEdu();
    }
};



class Laborer
{
private:
    Employee emp;
public:
    void getData() {
        emp.getData();
    }

    void putData() const {
        emp.putData();
    }
};



int main()
{
    Manager m1;
    Scientist s1, s2;
    Laborer l1;

    cout << endl;
    cout << "\nEnter data for manager 1";
    m1.getData();
    cout << "\nEnter data for scientist 1";
    s1.getData();
    cout << "\nEnter data for scientist 2";
    s2.getData();
    cout << "\nEnter data for laborer 1";
    l1.getData();

    cout << "\nData on manager 1";
    m1.putData();
    cout << "\nData on scientist 1";
    s1.putData();
    cout << "\nData on scientist 2";
    s2.putData();
    cout << "\nData on laborer 1";
    l1.putData();
    cout << endl;

    return 0;
}