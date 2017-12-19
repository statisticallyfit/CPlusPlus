#include <iostream>
using namespace std;



int main() {

    const int NUM_ELEMENTS = 10;
    const int NUM_ARRAYS = 10;
    int a0[] = {  0,  10,  20,  30,  40,  50,  60,  70,  80,  90};
    int a1[] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    int a2[] = {200, 210, 220, 230, 240, 250, 260, 270, 280, 290};
    int a3[] = {300, 310, 320, 330, 340, 350, 360, 370, 380, 390};
    int a4[] = {400, 410, 420, 430, 440, 450, 460, 470, 480, 490};
    int a5[] = {500, 510, 520, 530, 540, 550, 560, 570, 580, 590};
    int a6[] = {600, 610, 620, 630, 640, 650, 660, 670, 680, 690};
    int a7[] = {700, 710, 720, 730, 740, 750, 760, 770, 780, 790};
    int a8[] = {800, 810, 820, 830, 840, 850, 860, 870, 880, 890};
    int a9[] = {900, 910, 920, 930, 940, 950, 960, 970, 980, 990};

    // an int array of 10 pointers that point to each of the ten arrays
    // @todo: why not work this way: ap[][10] = {a0, a1...}? Why need to write *a0 instead, when using this method?
    int *ap[] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

    for (int i = 0; i < NUM_ARRAYS; i++){
        for (int p = 0; p < NUM_ELEMENTS; p++){
            cout << ap[i][p] << " ";
        }
        cout << endl;
    }
}