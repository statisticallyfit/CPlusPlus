#include <iostream>
using namespace std;
#include <assert.h>
#include <stdbool.h>
//#include <boost/log/trivial.hpp>




// Prototyping classes so no method errors
class Date;
class Time;
class Calendar;



class Date {

private:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0)
    {}
    Date(int d, int m, int y) : day(d), month(m), year(y)
    {}
    void setDay(int d) {day = d; }
    void setMonth(int m) {month = m; }
    void setYear(int y) {year = y; }
    int getDay() {return day; }
    int getMonth() {return month; }
    int getYear() {return year; }

    bool isLeapYear() {
        return ((year % 4 == 0 && year % 100 != 0) ||
                year % 400 == 0);
    }

    int findDaysInMonth(){
        const int dayAtMonthEnd[13] = {0, 31, 28, 31, 30, 31, 30,
                                       31, 31, 30, 31, 30, 31};
        return (isLeapYear() && month == 2) ? 29 : dayAtMonthEnd[month];
    }

    Date subtract(Date other) {
        Date diff;
        if (isLess(other)){
            diff.setMonth(other.getMonth() - getMonth());
            diff.setDay(other.getDay() - getDay());
            diff.setYear(other.getYear() - getYear());
        } else {
            diff.setMonth(getMonth() - other.getMonth());
            diff.setDay(getDay() - other.getDay());
            diff.setYear(getYear() - other.getYear());
        }

        return diff;
    }

    bool isLess(Date other) {
        return toSeconds() < other.toSeconds();
    }

    long long int toSeconds() {
        long long int daysInYear = (isLeapYear()) ? 366 : 365;
        daysInYear *= year;
        long long int daysInMonth = findDaysInMonth() * month;
        long long int totalDays = day + daysInMonth + daysInYear;
        return (totalDays * 24 * 3600); //number of seconds
    }

    bool isEqual(Date other) {
        return (year == other.getYear() &&
                month == other.getMonth() &&
                day == other.getDay());
    }

    void show() {
        printf("%.2i/%.2i/%.2i\n", day, month, year);
    }
};



class Time {

private:
    int hour;
    int minutes;
    int seconds;

public:
    Time() : hour(0), minutes(0), seconds(0)
    {}
    Time(int h, int m, int s) : hour(h), minutes(m), seconds(s)
    {}
    void set(int h, int m, int s) {hour = h; minutes = m; seconds = s; }
    void setHour(int h) {hour = h; }
    void setMin(int m) {minutes = m; }
    void setSec(int s) {seconds = s; }
    int getHour() {return hour; }
    int getMin() {return minutes; }
    int getSec() {return seconds; }

    bool isLess(Time other) {
        return toSeconds() < other.toSeconds();
    }

    long int toSeconds() {
        return ((long) seconds + minutes * 60 + hour * 3600);
    }

    bool isEqual(Time other) {
        return (hour == other.getHour() &&
                minutes == other.getMin() &&
                seconds == other.getSec());
    }

    void show() {
        printf("%.2i:%.2i:%.2i\n", hour, minutes, seconds);
    }

    /**
     * Calculates elapsed time between two Times
     * Times are assumed 1 day apart
     */
    Time elapsedTime(Time other) {

        Time elapsed;

        // get individual s
        long double s1 = (long double) toSeconds();
        long double s2 = (long double) other.toSeconds();

        long double elapsedSeconds = (s2 > s1) ? s2 - s1 : s1 - s2;

        // convert back to hh:mm:ss

        // HourMin: separate decimal and change it to m
        /*long double hourMin = elapsedSeconds / 3600;
        elapsed.setHour((int) hourMin);
        long double minSec = 60 * (hourMin - (int) hourMin); // get decimal part (min in hour form)
        elapsed.setMin((int) minSec);
        long double secMillisec = 60 * (minSec - (int) minSec);
        elapsed.setSec((int) secMillisec); // millisec are ignored*/

        int h, m, s;
        while (elapsedSeconds >= 3600) {
            elapsedSeconds -= 3600;
            h++;
        }
        while (elapsedSeconds >= 60) {
            elapsedSeconds -= 60;
            m++;
        }
        s = elapsedSeconds;

        elapsed.set(h, m, s);

        return elapsed;
    }
};




class Calendar {

private:
    Date date;
    Time time;

public:
    Calendar() : date(0, 0, 0), time(0, 0, 0)
    {}
    Calendar(Date d, Time t) : date(d.getDay(), d.getMonth(), d.getYear()),
                               time(t.getHour(), t.getMin(), t.getSec())
    {}
    void set(Date d, Time t) {date = d; time = t; }
    void setDate(Date d) {date = d;}
    void setTime(Time t) {time = t; }
    Date getDate() {return date; }
    Time getTime() {return time; }

    bool isEqual(Calendar other) {
        return date.isEqual(other.getDate()) &&
               time.isEqual(other.getTime());
    }

    bool isLess(Calendar other) {
        if (date.isEqual(other.getDate())){
            return time.isLess(other.getTime());
        }
        return date.isLess(other.getDate());
    }

    /**
     * Adds year's worth of seconds if number of leaps is odd, else nothing
     */
    long double correctForLeapYear(Calendar other, long double seconds){
        int numLeaps = 0;
        for (int y = date.getYear(); y <= other.getDate().getYear(); y++){
            Date maybe(0, 0, y);
            if (maybe.isLeapYear())
                numLeaps++;
        }
        if (numLeaps % 2 != 0)
            seconds += 24 * 3600; //extra seconds in 1 day
        return seconds;
    }

    Calendar elapsedPeriod(Calendar other) {

        Calendar elapsed;
        Date dateWithSameDay;
        Date dateDiff;
        long double secondsDiff = 0;

        dateWithSameDay.setDay(date.getDay());
        dateWithSameDay.setMonth(other.getDate().getMonth());
        dateWithSameDay.setYear(other.getDate().getYear());

        //dateDiff = dateWithSameDay.subtract(date);

        //secondsDiff = dateDiff.toSeconds();

        secondsDiff = (date.isLess(dateWithSameDay))
                      ? dateWithSameDay.toSeconds() - date.toSeconds()
                      : date.toSeconds() - dateWithSameDay.toSeconds();

        secondsDiff += 24 * 3600 * (other.getDate().getDay() - date.getDay());
        secondsDiff += other.getTime().toSeconds();
        secondsDiff -= time.toSeconds();

        secondsDiff = correctForLeapYear(other, secondsDiff);

        // Now going the other way: convert seconds to DateTime
        int seconds = secondsDiff;
        int hours = 0;
        int minutes = 0;
        int days = 0;
        int months = 0;
        int years = 0;

        while (seconds >= 60) {
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60){
            minutes -= 60;
            hours++;
        }
        while (hours >= 24){
            hours -= 12;
            days++;
        }
        while (days > 30){
            days -= 30;
            months++;
        }
        while (months >= 12){
            months -= 12;
            years++;
        }

        elapsed.setDate(Date(days, months, years));
        elapsed.setTime(Time(hours, minutes, seconds));

        /*long double yearMonth = secondsDiff / (365 * 24 * 3600);
        int resultYear = (int) yearMonth;
        long double monthDay = 12 * (yearMonth - (int) yearMonth);
        int resultMonth = (int) monthDay;
        long double dayHour = 30 * (monthDay - (int) monthDay);
        int resultDay = (int) dayHour;

        long double hourMin =  24 * (dayHour - (int) dayHour);//secondsDiff / 3600;
        int resultHour = (int) hourMin;
        long double minSec = 60 * (hourMin - (int) hourMin); // get decimal part (min in hour form)
        int resultMin = (int) minSec;
        long double secMillisec = 60 * (minSec - (int) minSec);
        int resultSec = (int) secMillisec; // millisec are ignored

        elapsed.setDate(Date(resultDay, resultMonth, resultYear));
        elapsed.setTime(Time(resultHour, resultMin, resultSec));*/

        return elapsed;
    }

    void show() {
        date.show();
        time.show();
    }
};





int main() {

    cout << "TEST TIME" << endl;
    cout << "Test 1: a few hours apart " << endl;
    Time t1(3, 45, 15);
    Time t2(9, 44, 3);
    Time EXP(5, 58, 48);
    t1.elapsedTime(t2).show();
    //assert(EXP.isEqual(t1.elapsedTime(t2)));

    cout << endl;
    cout << "Test 2: 59 seconds apart " << endl;
    t1.set(5, 8, 0);
    t2.set(6, 7, 0);
    EXP.set(0, 59, 0);
    t1.elapsedTime(t2).show();
    //assert(EXP.isEqual(t1.elapsedTime(t2)));

    /** Test 1: Simple midnight cross */
    cout << endl;
    cout << "TEST CALENDAR " << endl;
    cout << "Test 1: Simple midnight cross" << endl;
    Calendar c1;
    Calendar c2;
    Calendar EXPECT;
    c1.set(Date(2, 11, 2015), Time(22, 0, 0)); // 2/11/2015 and 11pm
    c2.set(Date(3, 11, 2015), Time(1, 5, 5)); // 3/11/2015 and 1:0:05am
    EXPECT.set(Date(0, 0, 0), Time(3, 5, 5));
    c1.elapsedPeriod(c2).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 2: short hours apart, same days */
    cout << endl;
    cout << "Test 2: short hours apart, same days" << endl;
    c1.set(Date(2, 11, 2015), Time(5, 6, 0)); //5:06 am on 11/2/2015
    c2.set(Date(2, 11, 2015), Time(7, 7, 0)); //7:07 am on 11/2/2015
    EXPECT.set(Date(0, 0, 0), Time(2, 1, 0));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 3: short hours apart, military time, same days */
    cout << endl;
    cout << "Test 3: short hours apart, military time, same days" << endl;
    c1.set(Date(2, 11, 2015), Time(17, 6, 0));
    c2.set(Date(2, 11, 2015), Time(19, 7, 0));
    EXPECT.set(Date(0, 0, 0), Time(2, 1, 0));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 4: 1 day apart */
    cout << endl;
    cout << "Test 4: 1 day apart" << endl;
    c1.set(Date(2, 11, 2015), Time(0, 0, 0));
    c2.set(Date(3, 11, 2015), Time(0, 0, 0));
    EXPECT.set(Date(0, 0, 0), Time(24, 0, 0));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 5: 1 day and some time apart */
    cout << endl;
    cout << "Test 5: 1 day and some time apart" << endl;
    c1.set(Date(2, 11, 2015), Time(5, 10, 43)); // 5:10:43 am on 2/11/2015
    c2.set(Date(3, 11, 2015), Time(12, 04, 05)); // 12:04:05 pm on 3/11/2015
    EXPECT.set(Date(1, 0, 0), Time(6, 53, 22));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 6: more days apart */
    cout << endl;
    cout << "Test 6: more days apart" << endl;
    c1.set(Date(2, 11, 2015), Time(5, 10, 43)); // 5:10:43 am on 2/11/2015
    c2.set(Date(7, 11, 2015), Time(12, 04, 05)); // 12:04:05 pm on 3/11/2015
    EXPECT.set(Date(5, 0, 0), Time(6, 53, 22));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 7: many months apart */
    cout << endl;
    cout << "Test 7: many months apart" << endl;
    c1.set(Date(2, 11, 2015), Time(2, 1, 59)); // 5:10:43 am on 2/11/2015
    c2.set(Date(7, 3, 2016), Time(12, 4, 5)); // 12:04:05 pm on 3/11/2015
    EXPECT.set(Date(5, 4, 0), Time(10, 2, 6));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    /** Test 8: many years apart */
    cout << endl;
    cout << "Test 8: many years apart" << endl;
    c1.set(Date(2, 11, 2015), Time(23, 1, 3)); // 5:10:43 am on 2/11/2015
    c2.set(Date(23, 4, 2020), Time(4, 5, 1)); // 12:04:05 pm on 3/11/2015
    EXPECT.set(Date(21, 5, 4), Time(18, 56, 3));
    c1.elapsedPeriod(c2).show();
    c1.getTime().elapsedTime(c2.getTime()).show();
    //assert(EXPECT.isEqual(c1.elapsedPeriod(c2)));

    return 0;
}