#include <iostream>
#include <string>
using namespace std;


enum DaysOfWeek {Sun, Mon, Tue, Wed, Thu, Fri, Sat};


enum DaysOfWeek matchDay(string givenDayStr){
    if (givenDayStr == "Monday")
        return Mon;
    else if (givenDayStr == "Tuesday")
        return Tue;
    else if (givenDayStr == "Wednesday")
        return Wed;
    else if (givenDayStr == "Thursday")
        return Thu;
    else if (givenDayStr == "Friday")
        return Fri;
    else if (givenDayStr == "Saturday")
        return Sat;
    else
        return Sun;
}


int main() {

    DaysOfWeek day1, day2;
    string d1, d2;

    cout << "Enter day1: ";
    cin >> d1;
    cout << "Enter day2: ";
    cin >> d2;

    day1 = matchDay(d1);
    day2 = matchDay(d2);

    int diff = day2 - day1;
    cout << "Days between = " << diff << endl;

    if (day1 < day2)
        cout << d1 << " comes before " << d2 << endl;
    else
        cout << d2 << " comes before " << d1 << endl;

    return 0;
}