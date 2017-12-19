#include <iostream>
#include <cmath>
using namespace std;




class Distance;


class Distance {

private:
    /*const*/ double MTF = 3.280833; // meters to feet
    int feet;
    double inches;

public:
    Distance() : feet(0), inches(0.0)//, MTF(3.280833F)
    {}

    explicit Distance(double meters) //: MTF(3.280833F)
    {
        double roughFeet = MTF * meters;
        feet = (int) roughFeet;
        inches = 12 * (roughFeet - feet);
        simplify();
    }

    Distance(int f, double i) : feet(f), inches(i)//, MTF(3.280833F)
    {
        simplify();
    }

    void setDistance(int f, double i) { feet = f; inches = i; }
    int getFeet() { return feet; }
    double getInches() { return inches; }

    void input() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        simplify();
    }

    void show() const {
        cout << feet << "\'-" << inches << '\'';
    }

    Distance operator + (Distance other)  {
        int fOld = feet;
        double iOld = inches;
        feet += other.getFeet();
        inches += other.getInches();

        simplify();

        Distance result(feet, inches);
        feet = fOld;
        inches = iOld;

        return result;
    }

    Distance operator - (Distance other) {
        int fOld = feet;
        double iOld = inches;
        feet = abs(feet - other.getFeet());
        inches = abs(inches - other.getInches());

        simplify();

        Distance result(feet, inches);
        feet = fOld;
        inches = iOld;

        return result;
    }

    void operator += (Distance other) {
        feet += other.getFeet();
        inches += other.getInches();
        simplify();
    }

    bool operator < (Distance other) const {
        double thisTotalFeet = feet + inches / 12.0;
        double otherTotalFeet = other.getFeet() + other.getInches() / 12.0;
        return (thisTotalFeet < otherTotalFeet);
    }

    // converting from object to double typed meters!
    operator double() const {
        return (feet + inches / 12) / MTF; //convert to meters
    }

    void simplify(){
        while (inches >= 12.0){
            inches -= 12.0;
            feet++;
        }
    }
};

int main() {

    Distance d1, d2, result;

    d1.input();
    d2.input();

    /** Testing (-) operator */
    result = d1 - d2;
    cout << "\n"; d1.show(); cout << " MINUS "; d2.show(); cout << " = "; result.show();

    return 0;
}