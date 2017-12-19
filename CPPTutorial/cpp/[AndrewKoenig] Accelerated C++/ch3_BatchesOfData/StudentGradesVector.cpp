#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

/* using ...
 * setprecision
 * string
 * streamsize
 * sort
 * vector
 */
using namespace std;

int main() {
    //ask for and read student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    //ask for and read midterm and final grades
    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;

    //ask for homework grades
    cout << "Enter all homework grades, followed by end-of-file: ";

    //read into this variable:
    double x;
    vector<double> homework;

    /*
     * invariant: homework contains all the homework
     * grades read so far
     */
    while(cin >> x) {
        homework.push_back(x);
    }

    //check that student entered some homework grades
    //defines vectorSize as synonym to vector<double>::size_type (which can hold many elements)
    typedef vector<double>::size_type vectorSize;
    vectorSize size = homework.size(); //now vectorSize is a type
    if(size == 0) {
        cout << endl << "You must enter your grades. "
                                "Please try again." << endl;
        return 1;
    }

    //sort the grades in place
    sort(homework.begin(), homework.end());

    //compute the homeworkMedian homework grade
    vectorSize mid = size/2;
    double homeworkMedian;
    homeworkMedian = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
                           : homework[mid];

    //compute and write the final grade
    streamsize prec = cout.precision();
    cout << "Your final grade is: " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * homeworkMedian
         << setprecision(prec) << endl; //just resetting precision to previous value

    return 0;
}