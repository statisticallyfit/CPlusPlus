#ifndef GUARD_StudentInfo_h
#define GUARD_StudentInfo_h

// StudentInfo.h header file
// need to write include statements only for things used by declarations
#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
    std::string name;
    double final;
};

bool compare(const StudentInfo&, const StudentInfo&); //just the variable types
std::istream& read(std::istream&, StudentInfo&);
std::istream& readHomework(std::istream&, std::vector<double>&);

#endif