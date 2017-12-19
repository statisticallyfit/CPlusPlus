#include <iostream>
using namespace std;



void swap(int*, int, int*, int*);
void bubbleSort(int*, int);
void printArray(int*, int);


void swap(int *arr, int len, int *num1, int *num2) {
    if (*num1 > *num2) {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
        printArray(arr, len);
    }
}


void bubbleSort(int *arr, int len){
    for (int i = 0; i < len-1; i++){
        for (int j = i+1; j < len; j++){
            swap(arr, len, arr + i, arr + j);
        }
    }
}


void printArray(int *arr, int len) {
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    const int LENGTH = 10;
    int array[LENGTH] = {37, 84, 62, 91, 11, 65, 57, 28, 19, 49};

    printArray(array, LENGTH);
    bubbleSort(array, LENGTH);
    printArray(array, LENGTH);

    return 0;
}