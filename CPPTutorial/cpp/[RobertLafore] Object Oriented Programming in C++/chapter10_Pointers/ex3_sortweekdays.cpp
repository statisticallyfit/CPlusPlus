/*
#include <iostream>
#include <string.h>

using namespace std;

const int DAYS = 7;




void order(char *, char *);
void bubbleSort(char **, int);
void printArray(const char **, int);


void swapTwo(char **day1, char **day2) {
    //cout << *day1 << " " << *day2;
    if (strcmp(*day1, *day2) > 0) {
        char *temp = *day1;
        *day1 = *day2;
        *day2 = temp;
        //cout << *day1 << " " << *day2;
        //printArray(arr, len);
    }
}


void bubbleSort(*/
/*const*//*
 char **arr, int len){
    for (int i = 0; i < len-1; i++){
        for (int j = i+1; j < len; j++){
            swapTwo(arr + i, arr + j);
        }
    }
}

void printArray(*/
/*const*//*
 char *arr[], int numDays) {
    for (int i = 0; i < numDays; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}




int main() {

    const char *arrStrPtrs[DAYS] = {"Monday", "Tuesday", "Wednesday",
                                    "Thursday", "Friday", "Saturday", "Sunday"};

    //cout << *(arrStrPtrs+3);
    printArray(arrStrPtrs, DAYS);
    bubbleSort(arrStrPtrs, DAYS);
    cout << endl;
    printArray(arrStrPtrs, DAYS);

}

*/
