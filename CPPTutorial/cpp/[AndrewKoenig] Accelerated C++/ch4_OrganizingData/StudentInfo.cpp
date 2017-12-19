// source file for StudentInfo-related functions
#include "StudentInfo.h"
#include "grade.h"
#include <stdexcept>

using std::istream;
using std::vector;
using std::domain_error;



/*
 * The predicate for the sort() by name
 */
bool compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name < s2.name;
}


/*
 * Read information for a StudentInfo object
 */
istream& read(istream& is, StudentInfo&s) {

    double midterm, final;
    vector<double> homework;

    // read and store name and midterm and final exam grades
    is >> s.name >> midterm >> final;

    // read and store homework grades
    readHomework(is, homework);

    // compute overall final grade and store in struct
    try
    {
        s.final = grade(midterm, final, homework);
    }
    catch (domain_error e)
    {
        s.final = -1;   // student has done no homework
    }

    return is;
}


/*
/*
 * Read homework grades from input stream into vector
 * The vector hw is changed in the original scope
 */
istream& readHomework(istream& in, vector<double>& hw){
    if(in) {
        //erase previous contents
        hw.clear();

        //read homework grades
        double aGrade;
        while(in >> aGrade) {
            hw.push_back(aGrade);
        }
        // clear the stream error status (but value is preserved_
        // so input works for next student
        in.clear();
    }
    return in;
}