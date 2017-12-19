#include <iostream>
using namespace std;



void sumArrayElements(int *a1, int *a2, int *result, int size) {

    for (int *p1 = a1, *p2 = a2;
         p1 < a1 + size;
         p1++, p2++){ // while not at null '\0' character, could also use p2

        *(result++) = *p1 + *p2; // @todo: cand you do this just using a1 and a2 not p1 and p2?
    }
}



int main() {

    int length = 0;
    cout << "Enter array size: ";
    cin >> length;

    int a1[length];
    int a2[length];
    int a3[length];

    cout << "Enter elements for array 1: ";
    for (int *p = a1; p < a1 + length; p++){
        cin >> *p;
    }

    cout << "Enter elements for array 2: ";
    for (int *p = a2; p < a2 + length; p++){
        cin >> *p;
    }

    // add arrays and put result in array 3
    sumArrayElements(a1, a2, a3, length);

    for (int *p = a3; p < a3 + length; p++){
        cout << *p << " ";
    }
}