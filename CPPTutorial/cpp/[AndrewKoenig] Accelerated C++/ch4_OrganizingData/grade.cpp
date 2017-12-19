#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "StudentInfo.h"

using std::domain_error;
using std::vector;



double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


/*
 * Does not copy its argument because median does that
 * vector hw will not change in environment since it is const
 */
double grade(double midterm, double final, const vector<double>& hw) {
    if(hw.size() == 0){
        throw domain_error("Student has no homework grades");
    }
    return grade(midterm, final, median(hw));
}

/*
double grade(const StudentInfo& studentInfo) {
    return grade(studentInfo.midterm,
                 studentInfo.final,
                 studentInfo.homework);*/
}


