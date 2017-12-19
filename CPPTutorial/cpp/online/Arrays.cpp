#include <iostream>
#include <array>
using namespace std;


const int HEIGHT = 3;
const int WIDTH = 5;

void print(int[]);
void print(int[][WIDTH]);
void builtInArrayExample();
void containerLibArrayExample();

int multiArray[HEIGHT][WIDTH];
int array[HEIGHT * WIDTH];
int n, m;


int main() {
    /*for(n = 0; n < HEIGHT; n++) {
        for(m = 0; m < WIDTH; m++) {
            multiArray[n][m] = (n+1)*(m+1);
        }
    }

    for(n = 0; n < HEIGHT; n++) {
        for(m = 0; m < WIDTH; m++) {
            array[n*WIDTH + m] = (n+1)*(m+1);
        }
    }

    cout << "Printing the multi array: " << endl;
    print(multiArray);
    cout << "Printing the single array: " << endl;
    print(array);*/

    builtInArrayExample();
    containerLibArrayExample();
}

void print(int array[]){
    for(int i = 0; i < HEIGHT * WIDTH; i++){
        cout << array[i] << endl;
    }
}

void print(int array[][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            cout << array[i][j] << endl;
        }
    }
}

void builtInArrayExample() {
    int array[3] = {10, 20, 30};

    for(int i = 0; i < 3; ++i)
        ++array[i];
    for(int elem : array)
        cout << elem << "\n";
}

void containerLibArrayExample() {
    std::array<int, 3> myArray {{10, 20, 30}};

    for(int i = 0; i < myArray.size(); ++i)
        ++myArray[i];
    for(int elem : myArray)
        cout << elem << "\n";
}