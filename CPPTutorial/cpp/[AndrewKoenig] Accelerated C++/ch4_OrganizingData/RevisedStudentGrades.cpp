#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "StudentInfo.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;


// END OF FILE KEY: F6
int main()
{
    vector<StudentInfo> students;
    StudentInfo record;
    string::size_type maxlen = 0;       // the length of the longest name

    // read and store all the students data.
    // Invariant:  students contains all the student records read so far
    //   maxlen contains the length of the longest name in students
    while (read(cin, record)) { //now cin and record are changed in this environment
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<StudentInfo>::size_type i = 0;
         i != students.size(); ++i) {

        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        streamsize prec = cout.precision();

        // write the overall grade directly
        cout << setprecision(3)
                << students[i].final
                << setprecision(prec) << endl;
    }

    return 0;
}