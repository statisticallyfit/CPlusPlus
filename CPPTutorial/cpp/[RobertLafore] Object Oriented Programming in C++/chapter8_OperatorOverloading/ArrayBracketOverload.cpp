#include <iostream>
//#include <process> //for exit(1)
using namespace std;

const int LIMIT = 100;



class SafeArray;


class SafeArray {

private:
    int array[LIMIT] = {0, 0, 0};

public:
    // Safe check 1 using put() and get() safe functions
    void put(int i, int element) {
        if (i < 0 || i >= LIMIT){
            cout << "\nWARNING: INDEX OUT OF BOUNDS!" << endl;
        } else {
            array[i] = element;
        }
    }

    int get(int i) const {
        if (i < 0 || i >= LIMIT){
            cout << "\nWARNING: INDEX OUT OF BOUNDS!" << endl;
        } else {
            return array[i];
        }
    }

    // Safe check 2 by returning by reference
    int& access(int i) {
        if (i < 0 || i >= LIMIT){
            cout << "WARNING: INDEX OUT OF BOUNDS!" << endl;
        }
        return array[i];
    }

    // Safe access 3 with [] operator
    int &operator [] (int i) {
        if (i < 0 || i >= LIMIT){
            cout << "WARNING: INDEX OUT OF BOUNDS!" << endl;
        }
        return array[i];
    }
};



int main() {


    // Safe access 1
    SafeArray safe1;

    for (int i = 0; i < LIMIT; i++)
        safe1.put(i, i*10);

    for (int i = 0; i < LIMIT; i++){
        int tempElement = safe1.get(i);
        cout << "Element " << i << " is " << tempElement << endl;
    }


    // Safe access 2
    SafeArray safe2;

    for (int i = 0; i < LIMIT; i++) {
        safe2.access(i) = i * 10; // left side of equals sign
    }

    for (int i = 0; i < LIMIT; i++){
        int temp = safe2.access(i); // right side of equals sign
        cout << "Element " << i << " is " << temp << endl;
    }


    // Safe access 3
    SafeArray safe3;
    for (int i = 0; i < LIMIT; i++) {
        safe3[i] = i*10;
    }
    for (int i = 0; i < LIMIT; i++){
        int temp = safe3[i];
        cout << "Element " << i << " is " << temp << endl;
    }

    return 0;
}