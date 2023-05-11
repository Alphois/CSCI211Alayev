#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "date.h"
using namespace std;
class Student{
 //member variables:
 private:
    string ID;
    string lastName;
    string firstName;
    string standing;
    int credits;
    double gpa;
    Date dob;
    Date matriculationDay;
 public:
    //constructors:
    Student(string id,string ln, string fn, int creds, int gangplankAverage, Date dobby, Date mday);//standing does not really NEED to be included
    Student();
    //methods/functions below (and above technically):
    string lastNameGet() const;
    string firstNameGet()const;
    string standingGet()const;
    int creditsGet()const;
    double gpaGet()const;
    Date dobGet() const;
    Date matriculationDayGet() const;
    //accessors ^
    void IDSet(string id);
    void lastNameSet(string ln);
    void firstNameSet(string fn);
    void standingSet(string standing);
    void creditsSet(int credit);
    void gpaSet(double gp);
    void dobSet(Date dobby);
    void matriculationDaySet(Date mday);

    
    //mutator functions^
    bool isStudent();
   //  const bool operator ==(const Student& west) const; //fix this function in future
       bool operator ==(const Student& two) const;
       bool operator !=( const Student& two) const;
       bool operator >( const Student& two) const;
       bool operator <( const Student& two) const;
       bool operator <=( const Student& two) const;
       bool operator >=( const Student& two) const;

      friend ostream& operator <<(ostream& one , const Student& two);
      friend istream& operator >>(istream& one,  Student& two);
  
   //  void input();
   //  void output();
};
#endif