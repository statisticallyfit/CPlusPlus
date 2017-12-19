#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



class Word {
    string word;
    int occurrences;

public:
    Word(string w, int o){
        word = w;
        occurrences = o;
    }

    void increment(){ occurrences++; }
    void increment(int amount) { occurrences += amount; }
    string getWord() { return word; }
    int getNumberOfOccurrences() { return occurrences; }
};


/**
 * Reads input of words
 */
vector<string> readInput() {
    string aWord;
    const string STOP = "STOP";
    vector<string> wordList;

    while (cin >> aWord) {
        if (aWord == STOP){
            break;
        }
        wordList.push_back(aWord);
    }
    return (wordList);
}

/**
 * Count how many times each word occurs in the vector
 * Returns a vector filled with Word objects
 * Each element = each object holds a word and its occurrence
 */
vector<Word> countOccurrences(const vector<string>& wordList) {

    typedef vector<string>::size_type vecSize;

    vector<Word> wordObjects;
    vector<string> tempWordList = wordList;
    sort(tempWordList.begin(), tempWordList.end());

    Word word(tempWordList[0], 1); // first word occurs at least once
    wordObjects.push_back(word);
    int pos = 0; // we are at index = 0 for wordObjects
    for (vecSize i = 1; i < tempWordList.size(); i++) {
        if (tempWordList[i] == tempWordList[i-1]){
            wordObjects[pos].increment();
        } else {
            Word newWord(tempWordList[i], 1);
            wordObjects.push_back(newWord);
            pos++;
        }
    }
    return wordObjects;
}


int main() {
    // input the words
    cout << "Input a list of words one by one: " << endl;
    vector<string> wordList = readInput();

    // count number of words in input
    cout << "Number of words in input: " << wordList.size() << "\n" << endl;

    // count how many times each word occurred.
    vector<Word> wordObjects = countOccurrences(wordList);

    // Print out output
    for (int i = 0; i < wordObjects.size(); i++) {
        cout << "Word: " << wordObjects[i].getWord() << endl;
        cout << "Occurrences: " << wordObjects[i].getNumberOfOccurrences() << "\n" << endl;
    }

    return 0;
}