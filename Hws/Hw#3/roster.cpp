#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

   Roster::Roster(){
      courseName="";
      courseCode="";
       instructorName="";
       numberCreds=0;
      for (int i=0; i<MAX_CAPACITY;i++){
         Student a;
         studList[i]= a;//invoke default constructor
      }
   }
   Roster::Roster(string cn, string cc, string in, int nc){
      courseName=cn;
      courseCode=cc;
      instructorName=in;
      numberCreds=nc;
      for (int i=0; i<MAX_CAPACITY;i++){
         Student a;
         studList[i]=a;
      }
   }
   //to be added in future
   /*===================
   Roster::Roster(string cn, string cc, string in, int nc, Student array[MAX_CAPACITY]){
      courseName=cn;
      courseCode=cc;
      instructorName=in;
      numberCreds=nc;
      for (int i=0; i<MAX_CAPACITY;i++){
         studList[i]=array[i];
      }
   }
   ====================*/
   string Roster:: getCN(){
      return courseName;
   }
   string Roster::getCC(){
      return courseCode;
   }
   string Roster::getIN(){
      return instructorName;
   }
   int Roster::getNC(){
      return numberCreds;
   }
   void Roster::setCN(string cn){
      courseName=cn;
   }
   void Roster::setCC(string cc){
      courseCode=cc;
   }
   void Roster::setIN(string in){
      instructorName=in;
   }
   void Roster::setNC(int nc){
      numberCreds=nc;
   }
   void Roster::addStudent(Student kanye){
      for (int i=0; i<MAX_CAPACITY;i++){
         if (!(studList[i].isStudent())){
            studList[i]=kanye;
            cout<<"student added to roster"<<endl;
            break;
         }
      }
      cout<<"roster is full"<<endl;
   }
   void Roster::deleteStudent(Student west){
      for (int i=0; i<MAX_CAPACITY;i++){
         if (studList[i].compare(west)){
            Student a;//create empty student using default constructor
            studList[i]=a; //assign it to index
            cout<<"student "<< west.firstNameGet()<<" "<<west.lastNameGet()<<" has been deleted"<<endl;
            break;
         }
      }
   }
   bool Roster::searchStudent(Student lilNasX){
      for (int i=0;i<MAX_CAPACITY;i++){
         if (studList[i].compare(lilNasX)){
            cout << "student " <<lilNasX.firstNameGet()<<" is in roster"<<endl;
            return true;
         }
      }
      cout << "student " <<lilNasX.firstNameGet()<<" is not in roster"<<endl;
      return false;
   }
   Student Roster::searchStudent(string fn){
      for (int i=0;i<MAX_CAPACITY;i++){
         if (studList[i].firstNameGet()==fn){
            cout << "student " <<fn<<" is in roster"<<endl;
            return studList[i];
         }
      }
      Student a;
      cout << "student " <<fn<<" is not in roster"<<endl;
      return a;
   }
   void Roster::input(){
      for (int i=0;i< MAX_CAPACITY;i++){
         if (!(studList[i].isStudent())){//if the student at this part of array is not a student
            studList[i].input();
         }
      }
   }
   void Roster::input(int numberStudents){//overloaded function that allows the user to decide how many students they want
      if (numberStudents>MAX_CAPACITY){
         cout<<"cannot have more than max capacity students in a roster"<<endl;
      }else{
      int counter=0;
       for (int i=0;i< MAX_CAPACITY;i++){
            if (counter<numberStudents){
               if (!(studList[i].isStudent())){//if the student at this part of array is not a student
                  cout<<"inputting student #"<<counter << ", please input following fields: "<<endl;
                  studList[i].input();//then allow user to input values
                  counter++;
               }//if
            }//if
         }//for  
      }//else
   }
   void Roster::output(){
      cout<<endl<<endl;
      cout<<"\t Course Name: " <<getCN()<<endl
                <<"\t Course Code: " <<getCC()<<endl
                <<"\t Instructor Name: "<<getIN()<<endl
                <<"\t Number Of Credits: "<< getNC()<< " credits"<< endl;
      for (int i=0; i< MAX_CAPACITY;i++){
         if (this->studList[i].isStudent()){//if there is student at that index 
            studList[i].output();//then print out his attributes
         }else{
            continue;
         }
         cout<<endl;
      }
   }

   


