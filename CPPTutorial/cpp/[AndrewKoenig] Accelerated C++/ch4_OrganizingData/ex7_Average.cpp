#include <iostream>
#include <vector>

using namespace std;



/**
 * Calculates average of numbers in vector<double>
 */
double average (const vector<double>& numbers) {
    double sum = 0;
    typedef vector<double>::size_type vecSize;

    for (vecSize i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    return (sum / numbers.size());
}


/**
 * Reads double input and stores them in vector<double>
 */
vector<double> readManyDoubles() {

    double input;
    vector<double> numbers;

    while (cin >> input) {
        numbers.push_back(input);
    }
    return numbers;
}

int main() {

    cout << "Input numbers one by one: " << endl;

    vector<double> numbers = readManyDoubles();

    cout << "Average: " << average(numbers) << endl;

    return 0;
}