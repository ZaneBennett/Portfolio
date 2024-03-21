#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Course.h"
#include "StudentCourses.h"

using namespace std;

void displayInfo(StudentCourses);

int main()
{
    /*
     Task I.     Declare cList to be an array of type Course of size 3, using initialization list
     The content must be the following:
     COSC1136, COSC1336, and MATH1122
    */

    Course cList[3] = { Course("COSC1136"), Course("COSC1336"), Course("MATH1122")};

    /*
     Task II.     Use your own name along with the cList array to instantiate an object of type
     StudentCourse.
     Call this object newStudent.
    */

    StudentCourses newStudent = { StudentCourses("Zane Bennett", cList, 3) };

    /*
     Task III.     Define a method in this file called displayInfo that receives an object of type
     StudentCourses and displays the full information of this object.
     Call this function here.
    */
    cout << "Task III:";
    displayInfo(newStudent);

    /*
     Task IV.    Declare a vector of type StudentCourses, called infoList.
     Populate this vector via the file called lab12_Data.txt of unknown size.
     Each student's information is given on two lines in the following pattern:
     First line contains full name of the student
     Next line starts with the number of courses, followed by the names of the courses:
     Example:
     Kim Rollins
     2 COSC3331 ENGL2235
     These are the steps that you MUST take for this task:
     Declare a Course and a StudentCourses object via default constructor
     Set up a loop to read the file
     Read the full name of the student and the number of courses
     Use push_back function to instantiate AND add the object based on the above 2 pieces information
     Note that this object is added to the vector but is not fully populated; so, use the object
     that is already in the vector and populate its Course array via proper method calls and further
     reading the file.
     Repeat for as many lines as we have in the file.
     */

    vector <StudentCourses>infoList;

    ifstream infile;

    infile.open("lab12_Data.txt");

    int newVar;
    
    StudentCourses temp;

    string tem;

    while (getline(infile, tem))
    {
        infile >> newVar;

        StudentCourses temp = { StudentCourses(tem, newVar) };

        for (int j = 0; j < newVar; j++)
        {
            infile >> tem;
            temp.setCourse(tem, j);
        }

        infile.ignore();
        infoList.push_back(temp);
    
    }

     /*
      Task V.    Display the full content of your infoList vector via calling the displayInfo method.
     */
    cout << "\n\nTask V:";
    for (int i = 0; i < infoList.size(); i++)
    {
        displayInfo(infoList[i]);
    }
     /*
      Task VI.   Student Ella Maine would like to enroll in ALL courses YOU are enrolled in(at the beginning
      of this program the newStudent object has your name on it!)
      We would like to use copy constructor to make this happen. So go ahead and define a programmer-defined
      copy constructor for class StudentCourses.
      When you are done, use it to instantiate Ella's object as a clone of yours.
      Next call the proper method to override your duplicated name by Ella's full name.
      Display Ella's object to check the accuracy of your work for this task.
      */
    cout << "\n\nTask VI:";
    StudentCourses newObject;
    newObject = StudentCourses(newStudent);
    newObject.setStudentName("Ella Maine");
    displayInfo(newObject);

      /*
       Task VII.  The course PHYS1199 is now called PHYS1437, in order to make this change do the following:
       Instantiate an object of type Course called newCourse. Set the name of this new course to PHYS1437.
       Iterate over the vector, find any occurrence of course PHYS1199, and update it by copying the newCourse
       to the old course with the old name. Note that we are looking for assigning one object to another, not
       just copying names.
       Display the full information on the StudentCourses objects that were
       modified.
       */
    vector <StudentCourses> container;
    Course newCourse = {Course("PHYS1437")};
    for (int i = 0; i < infoList.size(); i++)
    {
        for (int j = 0; j < infoList[i].getNumCourses(); j++)
        {
            if (infoList[i].getCourse(j).getCourseName() == "PHYS1199")
            {
                infoList[i].setCourse(newCourse.getCourseName(), j);
                container.push_back(infoList[i]);
            }
        }
    }
    cout << "\n\nTask VII:";
    for (int i = 0; i < container.size(); i++)
    {
        displayInfo(container[i]);
    }

       /*
        Task VIII. Correction: The courses assigned for Silvia Jones and Kim Rollins must be swapped.
        Give the segment of code that does that. Also display the information on these students to check
        the accuracy of your work for this task.
        Note that you MUST look for these names, do not use hard coded indices by looking at the file.
        */
    int silIn = 0, kimIn = 0;
    for (int i = 0; i < infoList.size(); i++)
    {
        if (infoList[i].getStudentName() == "Silvia Jones")
        {
            silIn = i;
        }

        if (infoList[i].getStudentName() == "Kim Rollins")
        {
            kimIn = i;
        }
    }

    for (int i = 0; i < infoList[silIn].getNumCourses(); i++)
    {
        Course temp = {Course(infoList[silIn].getCourse(i))};
        infoList[silIn].setCourse(infoList[kimIn].getCourse(i), i);
        infoList[kimIn].setCourse(temp.getCourseName(), i);
    }

    cout << "\n\nTask VIII";

    displayInfo(infoList[silIn]);

    displayInfo(infoList[kimIn]);

    return 0;
}

void displayInfo(StudentCourses sc)
{

    cout << "\n\n       Name:\t" << sc.getStudentName() << endl;
    cout << "Course List:\t";

    for (int i = 0; i < sc.getNumCourses(); i++)
    {
        cout << sc.getCourse(i).getCourseName() << " ";
    }

}