#include <iostream>
using namespace std;

class RaceCar {

private:
    static int carCount;

public:
    RaceCar(){
        carCount++;
    }

    int getCarCount(){
        return carCount;
    }
};
// initialize
int RaceCar::carCount = 0;



int main() {

    RaceCar r1, r2, r3;

    cout << "Count is " << r1.getCarCount() << endl;
    cout << "Count is " << r2.getCarCount() << endl;
    cout << "Count is " << r3.getCarCount() << endl;

    RaceCar r4;
    cout << "Count is " << r4.getCarCount() << endl;

    return 0;
}