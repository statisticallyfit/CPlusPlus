#include <iostream>
using namespace std;



class Distance {
private:
    int feet;
    float inches;
public:
    void getDist(){
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;
    }
    void showDist() {
        cout << feet << "\'-" << inches << '\"';
    }
};


int main() {

    Distance &d1 = *(new Distance);

    d1.getDist();
    d1.showDist();
    cout << endl;

    Distance d2 = *(new Distance);
    d2.getDist();
    d2.showDist();
    cout << endl;

    return 0;
}