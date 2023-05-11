#include <iostream>
#include <string>
#ifndef ROSTER_H
#define ROSTER_H
#define MAX_CAPACITY  10// I would suggest making MAX_CAPACITY 2 or 3 to test functions easier
#include "student.h"

using namespace std;
//if you see any errors, then read chapter 10 of savitch book 
//review how MACROS work
//you can also search this up
class Roster{
   //member variables
   private:
      string courseName;
      string courseCode;
      string instructorName;
      int numberCreds;
      Student studList[MAX_CAPACITY];
   public:
      Roster();
      Roster(string cn, string cc, string in, int nc);
      // Roster(string cn, string cc, string in, int nc, Student array[MAX_CAPACITY]);//in case the user wants to set the roster to their own pre-created array
      //above constructor to be added in future
   //constructors
      string getCN();//getCourseName
      string getCC();//getCourseCode
      string getIN();//getInstructorName
      int getNC();//getNumberCredits
   //accessors
      void setCN(string cn);//setCourseName
      void setCC(string cc);//setCourseCode
      void setIN(string in);//setInstructorName
      void setNC(int nc);//setNumberCreds
   //mutators 
      void addStudent(Student kanye);//addStudent
      void deleteStudent(Student west);//deleteStudent
      bool searchStudent(Student lilNasX);//searchStudent
      Student searchStudent(string fn);//overloaded searchStudent function
      void input();//allow user to input students in roster
      void input(int numberStudents);//overloaded function that allows user to pick how many students to input
      void output();//output all students in a roster
      //consider using iomanip for output
      //student roster management functions

};
#endif
