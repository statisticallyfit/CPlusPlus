#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std; // using setprecision, string, and streamsize in std namespace

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

    //the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    //read into this variable:
    double x;

    /*
     * invariant: we have read count grades so far and
     * sum is the sum of the first count grades
     */
    while(cin >> x) {
        count++;
        sum += x;
    }

    //write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is: " << setprecision(3)
            << 0.2 * midterm + 0.4 * final + 0.4 * sum/count
            << setprecision(prec) << endl; //just resetting precision to previous value

    return 0;
}