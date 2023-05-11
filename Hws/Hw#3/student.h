#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student{
 //member variables:
 private:
    string lastName;
    string firstName;
    string standing;
    int credits;
    double gpa;
    string dob;
    string matriculationDay;
 public:
    //constructors:
    Student(string ln, string fn, string konoStando, int creds, int gangplankAverage, string dobby, string mday);
    Student(string ln, string fn, int creds, int gangplankAverage, string dobby, string mday);//standing does not really NEED to be included
    Student();
    //methods/functions below (and above technically):
    string lastNameGet();
    string firstNameGet();
    string standingGet();
    int creditsGet();
    double gpaGet();
    string dobGet();
    string matriculationDayGet();
    //accessors ^
    void lastNameSet(string ln);
    void firstNameSet(string fn);
    void standingSet(string standing);
    void creditsSet(int credit);
    void gpaSet(double gp);
    void dobSet(string dobby);
    void matriculationDaySet(string mday);
    //mutator functions^
    bool isStudent();
   //  const bool operator ==(const Student& west) const; //fix this function in future
    bool compare(Student Kanye);
    void input();
    void output();
};
#endif