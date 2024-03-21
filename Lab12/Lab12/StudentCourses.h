#ifndef STUDENTCOURSES_H
#define STUDENTCOURSES_H

// ******************************
// * Do you need anything here? *
// ******************************
#include "Course.h"
#include <string>
using namespace std;

class StudentCourses
{
private:
    string studentName;  // The student's name
    Course* courseList;  // Points to array of Course objects: aggregation example
    int numCourses;   // Number of courses

public:
    // Constructor
    StudentCourses(string name = "", int numCourses = 0)
    {
        studentName = name;
        this->numCourses = numCourses;
        courseList = new Course[numCourses];
    }

    // Overloaded Constructor
    StudentCourses(string name, Course* cPtr, int numCourses)
    {
        studentName = name;
        courseList = cPtr;
        this->numCourses = numCourses;
    }

    // ******************************
    // * Copy Constructor goes here *
    // ******************************

    StudentCourses(const StudentCourses &ok)
    {
        studentName = ok.studentName;
        numCourses = ok.numCourses;
        courseList = new Course[numCourses];
        for (int i = 0; i < numCourses; i++)
        {
            courseList[i] = ok.courseList[i];
        }
    }


    // Sets the course in specific index
    void setCourse(Course course, int index)
    {
        courseList[index] = course;
    }

    void setStudentName(string name)
    {
        studentName = name;
    }

    string getStudentName() const
    {
        return studentName;
    }

    int getNumCourses()
    {
        return numCourses;
    }

    // Get a specific course object.
    Course getCourse(int index) const
    {
        return courseList[index];
    }
};
#endif