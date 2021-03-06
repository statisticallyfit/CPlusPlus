#include <iostream>

using namespace std;


class CivilianTime;

class MilitaryTime;


class CivilianTime {

private:
    bool PM;
    int hours;
    int minutes;
public:
    CivilianTime() : PM(true), hours(0), minutes(0) { }

    CivilianTime(bool pm, int h, int m) : PM(pm), hours(h), minutes(m) { normalize(); }

    CivilianTime(MilitaryTime mt) {

        int militaryHours = mt.getHours();
        PM = mt.getHours() < 12 ? false : true;

        minutes = mt.getSecs() < 30 ? mt.getMins() : mt.getMins() + 1;
        if (minutes == 60) {
            minutes = 0;
            //++militaryHours;
            militaryHours++;
            if (militaryHours == 12 || militaryHours == 24) {
                PM = !PM;    // toggle am/pm
            }
        }
        hours = (militaryHours < 13) ? militaryHours : militaryHours - 12;
        if (hours == 0) {
            hours = 12;
            PM = false;
        }
    }

    void show() const {
        cout << hours << ":";
        if (minutes < 10)
            cout << "0"; //extra zero for "01"
        cout << minutes << " ";
        string amOrPm = PM ? "p.m." : "a.m.";
        cout << amOrPm;
    }

    void normalize() {
        if (PM) {
            hours += 12; //inside if
        }

        // normalizing
        while (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        // not counting days.months.years
        while (hours > 23) {
            hours -= 12; // move a day back
        }

        // now converting back to civilian time
        if (hours > 12) {
            hours -= 12;
            PM = true;
        } else {
            PM = false;
        }
    }
};


class MilitaryTime {

private:
    int hours;      // 0 to 23
    int minutes;    // 0 to 59
    int seconds;    // 0 to 59
public:
    MilitaryTime() : hours(0), minutes(0), seconds(0) { }

    MilitaryTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) { normalize(); }

    int getHours() const { return hours; }
    int getMins() const { return minutes; }
    int getSecs() const { return seconds; }

    void show() const {
        if (hours < 10)
            cout << "0";
        cout << hours << ":";
        if (minutes < 10)
            cout << "0";
        cout << minutes << ":";
        if (seconds < 10)
            cout << "0";
        cout << seconds;
    }

    void normalize() {
        while (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60) {
            minutes -= 60;
            hours++;
        }
        // not counting days.months.years
        while (hours > 23) {
            hours -= 12; // move a day back
        }
    }
};


int main() {

    int h, m, s;

    while (true) {

        cout << "Enter 24-hour time: \n";
        cout << "   Hours (0 to 23): ";
        cin >> h;
        if (h > 23) return 1; //quit program
        cout << "   Minutes: ";
        cin >> m;
        cout << "   Seconds: ";
        cin >> s;

        MilitaryTime t24(h, m, s);
        cout << "You entered: ";
        t24.show();

        CivilianTime t12 = t24; // uses the conversion operator
        cout << "\n12-hour time: ";
        t12.show();
        cout << endl << endl;
    }
}