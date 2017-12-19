#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;         // <iostream>
using std::cout;        // <iostream>
using std::endl;        // <iostream>
using std::sort;        // <algorithm>
using std::string;      // <string>
using std::vector;      // <string>


int main() {

    // Declare constant to end while loop
    const string stopSignal = "STOP";

    // Ask for list of words and store in vector
    cout << "Enter a list of words one by one: ";
    vector<string> words;
    string aWord;
    while (cin >> aWord) {
        if(aWord == stopSignal){
            break;
        }
        words.push_back(aWord);
    }
    cout << endl;

    // Create the words type size and numDistinct variable
    typedef vector<string>::size_type vecSize;
    vecSize length = words.size();
    vecSize numDistinct;

    if(length == 0){
        numDistinct = 0;
    } else if(length == 1){
        numDistinct = 1;
    } else {
        sort(words.begin(), words.end());

        int firstIndex = 0;
        int consecIndex = 1;

        numDistinct = 1;

        for(int i = 0; i < words.size() - 1; i++){
            if(words[firstIndex] != words[consecIndex]){
                numDistinct++;
            }
            firstIndex++;
            consecIndex++;
        }
    }

    cout << "Number of distinct words is: " << numDistinct << endl;

    return 0;
}
