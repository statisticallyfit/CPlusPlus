/*
#include <iostream>
using namespace std;


// Program goal: model pointer memory storage



float floatMemory[10]; // holds float values
int pointerMemory[10]; // holds the "pointers" or float indexes
int *fMemTop = floatMemory;        // points to next location in fmemory where float can be stored
int *pMemTop = pointerMemory;        // points to next location in pmemory where float indexes can be stored


class Float {

private:
    int indexAddress; // index where float value is stored in fmemory

public:
    Float(float floatValue){
        floatMemory[*fMemTop] = floatValue;
        fMemTop++;
    }


};*/
