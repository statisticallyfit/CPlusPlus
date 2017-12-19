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


int main(){

    // Ask for a list of words
    cout << "Please enter a list of words one by one: ";

    const string stopSignal = "STOP";
    vector<string> wordList;
    string aWord;

    while (cin >> aWord) {
        if(aWord == stopSignal){
            break;
        }
        wordList.push_back(aWord);
    }
    cout << endl;

    // Create word length vector
    typedef vector<string>::size_type vecSizeType;
    vecSizeType wordListLength = wordList.size();

    typedef string::size_type stringSizeType;
    vector<stringSizeType> wordLengths;
    wordLengths.resize(wordListLength);

    // Get lengths of words
    for(int i = 0; i < wordList.size(); i++) {
        wordLengths[i] = wordList[i].length();
    }

    // Sort lengths vector and return first and last elements
    sort(wordLengths.begin(), wordLengths.end());

    cout << "Length of shortest word: " << wordLengths[0];
    cout << "\nLength of longest word: " << wordLengths[wordLengths.size() - 1] << "\n";

    return 0;
}