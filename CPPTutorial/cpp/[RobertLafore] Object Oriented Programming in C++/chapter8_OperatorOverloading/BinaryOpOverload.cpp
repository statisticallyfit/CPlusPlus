#include <iostream>
using namespace std;



/**
 * TODO: Don't know why putting const double MTF = 3.28... with the operator double() code
 * TODO: compile. Taking const out works.
 *
 * TODO: Error1: error: use of deleted function ‘Distance& Distance::operator=(Distance&&)’
 * TODO: Error2: note: ‘Distance& Distance::operator=(Distance&&)’ is implicitly deleted because the default definition would be ill-formed:
   TODO: class Distance {
 */



class Distance;


class Distance {

private:
    /*const*/ double MTF = 3.280833; // meters to feet
    int feet;
    double inches;

public:
    Distance() : feet(0), inches(0.0)//, MTF(3.280833F)
    {}

    Distance(double meters) //: MTF(3.280833F)
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
        feet = feet + other.getFeet();
        inches = inches + other.getInches();
        simplify();

        Distance d(feet, inches);
        feet = fOld;
        inches = iOld;

        return d;
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
        if (inches >= 12.0){
            inches -= 12.0;
            feet++;
        }
    }

};


int main() {

    /*Distance d1, d3, d4;
    d1.input();

    Distance d2(6, 2.5);

    // Testing addition
    d3 = d1 + d2;
    d4 = d1 + d2 + d3;

    cout << "d1 = "; d1.show(); cout << endl;
    cout << "d2 = "; d2.show(); cout << endl;
    cout << "d3 = "; d3.show(); cout << endl;
    cout << "d4 = "; d4.show(); cout << endl;

    // Testing < operator
    if (d1 < d2){
        cout << "\nd1 = "; d1.show(); cout << " is less than d2 = "; d2.show();
    } else {
        cout << "\nd1 = "; d1.show(); cout << " is greater than or equal to d2 = "; d2.show();
    }
    cout << endl;

    // Testing the += operator
    d1.input();
    d2.input();
    cout << "\n\nBefore: "; d1.show(); cout << endl; d2.show();
    d1 += d2;
    cout << "\nAfter: "; d1.show(); cout << endl; d2.show();
*/

    // Testing the casting operator
    double metersResult;
    Distance d5(2.35F); // using the meters constructor
    cout << "d5 = "; d5.show(); cout << endl;
    // METHOD 1: of using the conversion operator
    metersResult = static_cast<double>(d5); // uses conversion operator
    cout << "d5 = " << metersResult << " meters" << endl;

    // METHOD 2: of using the conversion operator
    Distance d6(5, 10.25); //using the feet, inches constructor
    metersResult = d6; //also uses conversion operator
    cout << "d6 = " << metersResult << " meters" << endl;

    //d6 = metersResult; //error, won't convert

    return 0;
}