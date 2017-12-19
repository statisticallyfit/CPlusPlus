#include <iostream>
#include <vector>
#include <algorithm> // for find()

using namespace std;


int main() {
    vector<int> values = {10, 20, 30, 40};

    // Declare iterators
    vector<int>::const_iterator it1;
    vector<int>::const_iterator it2;

    it1 = find(values.begin(), values.end(), 30);
    it2 = find(values.begin(), values.end(), 0);

    if (it1 != values.end()) {
        cout << "Element is found" << endl;
    } else {
        cout << "Element NOT found" << endl;
    }

    return 0;
}