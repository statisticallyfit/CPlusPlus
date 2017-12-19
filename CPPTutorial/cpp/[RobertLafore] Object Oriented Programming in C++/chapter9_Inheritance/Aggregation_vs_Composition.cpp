#include <iostream>


class Professor {};



// composition
class CollegeC
{
private:
    Professor *tim;
public:
    CollegeC() {
        tim = new Professor();
    }
    ~CollegeC() {
        delete tim;
    }
};



// aggregation
class CollegeA
{
private:
    Professor *teachingPosition;
public:
    CollegeA(Professor *tim) {
        teachingPosition = tim; // "hire" tim
    }
    ~CollegeA(){
        // nothing to delete; Tim continues to live on
        teachingPosition = 0;
    }
};