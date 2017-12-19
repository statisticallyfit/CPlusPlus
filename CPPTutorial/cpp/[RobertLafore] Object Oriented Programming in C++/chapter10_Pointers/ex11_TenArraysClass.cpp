// @todo: Understand exercise 11, don't get what it's asking...

/*
#include <iostream>
using namespace std;


const int NUM_ELEMENTS = 10;
const int NUM_ARRAYS = 10;


class ArrayPointerHolder {
private:
    int *matrix[NUM_ELEMENTS];
public:
    ArrayPointerHolder(int **m) {
        matrix = m;
    }

    void operator []
};



int main() {



    int *ap[NUM_ELEMENTS]; // an array of pointers to normal int arrays

    int arrayValue = 0;
    for (int i = 0; i < NUM_ARRAYS; i++){
        *(ap+i) = new int[NUM_ELEMENTS];
        for (int p = 0; p < NUM_ELEMENTS; p++){
            *(*(ap+i)+p) = arrayValue; //same as:   ap[i][p]
            cout << *(*(ap+i)+p) << " ";
            arrayValue += 10;
        }
        cout << endl;
    }

    // delete the pointers
    for (int i = 0; i < NUM_ARRAYS; i++){
        delete[] *(ap+i); // @todo: so this is deleting the array, not the actual memory location, right?
        cout << "Deleted array #" << i << endl;
    }

    return 0;
}*/
