#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             // <iostream>
using std::cout;            // <iostream>
using std::endl;            // <iostream>
using std::setprecision;    // <iomanip>
using std::sort;            // <algorithm>
using std::streamsize;      // <ios>
using std::string;          // <string>
using std::vector;          // <string>



int main() {
    cout << "\n***************************************\n"
            "*** This program computes quartiles ***\n"
            "***************************************\n";
    cout << endl;


    //list to hold the numbers
    vector<int> v;
    int inputNumber;
    cout << "Enter your list of numbers: ";
    while(cin >> inputNumber) {
        v.push_back(inputNumber);
    }
    cout << endl;

    // create the size type and use it to define length of vector
    typedef vector<int>::size_type vSize;
    vSize length = v.size();
    vSize medianIndex, lowerIndex, upperIndex;
    double median = 0;
    double lower = 0;
    double upper = 0;

    if(length == 0)
    {
        cout << "You must enter some numbers! ";
        return 1;
    }
    else
    {
        sort(v.begin(), v.end());

        if (length % 4 == 0) //case [0 0 0]
        {
            medianIndex = length / 2;
            lowerIndex = medianIndex / 2;
            upperIndex = medianIndex + lowerIndex;

            median = (v[medianIndex] + v[medianIndex - 1]) / 2;
            lower = (v[lowerIndex] + v[lowerIndex - 1]) / 2;
            upper = (v[upperIndex] + v[upperIndex - 1]) / 2;
        }
        else if (length % 4 == 1) //case [0 1 0]
        {
            medianIndex = length / 2;
            lowerIndex = medianIndex / 2;
            upperIndex = medianIndex + lowerIndex + 1;

            median = v[medianIndex];
            lower = (v[lowerIndex] + v[lowerIndex - 1]) / 2;
            upper = (v[upperIndex] + v[upperIndex - 1]) / 2;
        }
        else if (length % 4 == 2) // case [1 0 1]
        {
            medianIndex = length / 2;
            lowerIndex = medianIndex / 2;
            upperIndex = medianIndex + lowerIndex;

            median = (v[medianIndex] + v[medianIndex - 1]) / 2;
            lower = v[lowerIndex];
            upper = v[upperIndex];
        }
        else if (length % 4 == 3) // case [1 1 1]
        {
            medianIndex = length / 2;
            lowerIndex = medianIndex / 2;
            upperIndex = medianIndex + lowerIndex + 1;

            median = v[medianIndex];
            lower = v[lowerIndex];
            upper = v[upperIndex];
        }
    }

    // print the results
    cout << "First quartile: " << lower
         << "\nMedian: " << median
         << "\nThird Quartile: " << upper;

    return 0;
}
