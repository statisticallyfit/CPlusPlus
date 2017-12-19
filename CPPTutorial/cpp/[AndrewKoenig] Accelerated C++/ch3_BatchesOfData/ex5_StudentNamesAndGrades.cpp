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


    // Create variables
    string input = "";
    const string stopSignal = "STOP";
    vector<string> studentNames;

    double homeworkScore = 0;
    double totalScore = 0;
    const int numScoresPerStudent = 5;
    vector<double> meanScores;
    //meanScores.resize(numScoresPerStudent);

    cout << "Enter a student name: ";
    while(cin >> input){
        if(input == stopSignal)
            break;

        studentNames.push_back(input);

        // Read in the scores for this student
        cout << "Enter 5 homework scores one by one: ";
        for(int i = 0; i < numScoresPerStudent; i++){
            cin >> homeworkScore;
            totalScore += homeworkScore;
        }
        // Create the vector of mean score for each student
        meanScores.push_back(totalScore / 5);

        cout << "Enter a student name: ";
    }
    cout << endl;

    // Present the information
    for(int i = 0; i < studentNames.size(); i++) {
        cout << "Student name: " << studentNames[i] << "\n";
        cout << "Mean score: " << meanScores[i] << "\n\n";
    }

    return 0;
}