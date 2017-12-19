#include <iostream>
using namespace std;


class TollBooth {

private:
    static unsigned int carCount;
    double moneyCollected;

public:
    TollBooth() : moneyCollected(0)
    {}
    TollBooth(unsigned int amount) : moneyCollected(amount)
    {}

    void payingCar(){
        carCount++;
        moneyCollected += 0.50;
    }

    void nonpayingCar(){
        carCount++;
    }

    const void display(){
        cout << "Car total: " << carCount << endl;
        cout << "Cash total: " << moneyCollected << endl;
    }
};
unsigned int TollBooth::carCount = 0;



int main() {

    TollBooth toll1(50); //initialize cash total to $50
    toll1.payingCar();
    toll1.nonpayingCar();
    toll1.display();

    TollBooth toll2;
    toll2.payingCar();
    toll2.nonpayingCar();
    toll2.display();

    return 0;
}