#include <iostream>
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

void fancyDist(Distance d) {
    cout << "(in feet and inches) = ";
    d.show();
    cout << endl;
}



int main() {

    Distance d1(2.35F); //uses meters to distance constructor
    //Distance d2 = 2.35F; //ERROR if constructor is explicit

    cout << "\nd1 = "; d1.show();
    //cout << "\nd2 = "; d2.show();

    double meters = 3.0F;
    cout << "\nd1 = ";
    //fancyDist(meters); // error if ctor is explicit

    return 0;
}