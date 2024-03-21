#ifndef COURSE
#define COURSE
#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
    string courseName;		// Course name

public:
    // Constructor
    Course(string course = "")
    {
        courseName = course;
    }

    void setCourseName(string course)
    {
        courseName = course;
    }

    string getCourseName() const
    {
        return courseName;
    }
};
#endif 