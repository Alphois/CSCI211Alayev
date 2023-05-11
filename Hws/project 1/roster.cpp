#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

   Roster::Roster(){//not used
      courseName="";
      courseCode="";
       instructorName="";
       numberCreds=0;
       used=0;
       capacity=10;
       students=new Student[capacity];
   }
   Roster::Roster(string cn, string cc, string in, int nc){
      used=0;
      courseName=cn;
      courseCode=cc;
      instructorName=in;
      numberCreds=nc;
      capacity=1;
      students=new Student[capacity];
   }
   void Roster:: grow(){
      if (capacity<=0){
         capacity=1;
      }else{
         capacity*=2;
      }
      Student* tmp=new Student[capacity];
      for (int i=0; i<used;i++){
         tmp[i]=students[i];
      }
      delete [] students;
      this->students=tmp;
   }
   //to be added in future
   /*===================
   Roster::Roster(string cn, string cc, string in, int nc, Student array[capacity]){
      courseName=cn;
      courseCode=cc;
      instructorName=in;
      numberCreds=nc;
      for (int i=0; i<capacity;i++){
         students[i]=array[i];
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
   int Roster:: getUsed(){
      return this->used; 
   }
   //accessors
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
   void Roster::addStudent(const Student& kanye){
         if (used>=capacity){//if used is not maxcap
            grow();
         }
         students[used]=kanye;//used is the number of students in the array
         used++;
            //used-1 is the nearest empty index by this point
            cout<<"student added to roster"<<endl;
            sort();
   }   
   
   void Roster::deleteStudent(const Student& west){
      for (int i=0; i<capacity;i++){
         if (students[i]==(west)){
            int iterate=i;
            while(iterate<used-1){
               students[iterate]=students[iterate+1];
               iterate++;
               //start swapping previous index with index ahead until 
            }; //assign nullptr to index
            used--;
            cout<<"student "<< west.firstNameGet()<<" "<<west.lastNameGet()<<" has been deleted"<<endl;
            
         }
      }
   }
   void Roster::deleteStudent(string studentid){
      for (int i=0; i<used;i++){
         if (students[i].IDGet()==(studentid)){
            int iterate=i;
            while(iterate<used-1){
               students[iterate]=students[iterate+1];
               iterate++;
               //start swapping previous index with index ahead until 
            };
            used--;
            cout<<"student with ID #"<< studentid<<" has been deleted"<<endl;
            break;
         }
      }
   }
   bool Roster::searchStudent(const Student& lilNasX){
      for (int i=0;i<used;i++){
         if (students[i]==(lilNasX)){
            cout << "student " <<lilNasX.firstNameGet()<<" is in roster"<<endl;
            return true;
         }
      }
      cout << "student " <<lilNasX.firstNameGet()<<" is not in roster"<<endl;
      return false;
   }

   int Roster::searchStudent(string studentid){
      for (int i=0;i<used;i++){
         if (students[i].IDGet()==studentid){
            return i;
         }
      }
      cout << "student " <<studentid<<" is not in roster"<<endl;
      return -1;
   }
   void Roster::input(){
      for (int i=0;i< capacity;i++){
         if (!(students[i].isStudent())){//if the student at this part of array is not a student
            cin>>students[i];
         }
      }
   }
   void Roster::input(int numberStudents){//overloaded function that allows the user to decide how many students they want
      if (numberStudents>=capacity){
         cout<<"cannot have more than max capacity students in a roster"<<endl;
      }else{
      int counter=0;
       for (int i=0;i< capacity;i++){
            if (counter<numberStudents){
               if (!(students[i].isStudent())){//if the student at this part of array is not a student
                  cout<<"inputting student #"<<counter << ", please input following fields: "<<endl;
                  cin>>students[i];//then allow user to input values
                  counter++;
               }//if
            }//if
         }//for  
      }//else
   }
   void Roster::outputCourse(){
      cout<<"courseName:"<< courseName << "|"<< "courseCode: "<<courseCode<<'|'<< "Instructor Name: "<<instructorName<<"|"<<"Number of credits: " <<numberCreds<<endl;
   }
   void Roster::outputAll(){//not used as of hw 5
         cout<<"courseName:"<< courseName << "|"<< "courseCode: "<<courseCode<<'|'<<"Instructor Name: "<<instructorName<<"|"<<"Number of credits: " <<numberCreds<<endl;
        for (int i=0;i< used;i++){
            students[i].output();
            cout<<endl;
         }//if
         cout<<endl;
      }
   istream& operator >> (istream& one, Roster& two){
      cout<<"enter in course name: "<<endl;
      getline(one,two.courseName);
      cout<<"enter in course code: ";
      one>>two.courseCode;
      one.ignore();
      cout<<"enter in integer # of credits"<<endl;
      one>>two.numberCreds;
      one.ignore();
      cout<<"enter instructor name: "<<endl;
      getline(one, two.instructorName);
      // for (int i=0; i<two.used;i++){
      //    cout<< "enter in students: ";
      //    one>> two.students[i];
      // }
      return one;

   }
   ostream& operator << (ostream& one, const Roster& two){
         one<< two.courseName << "|"<< two.courseCode<<'|'<<two.numberCreds<<"|"<<two.instructorName<<endl;
        for (int i=0;i< two.used;i++){
               one<<two.students[i];
            }//for loop
            one<<"end_roster|"<<endl;
                     return one;

         }//for
 
   // To sort an array of size N in ascending order: 

// Iterate from arr[1] to arr[N] over the array. 
// Compare the current element (key) to its predecessor. 
// If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
   void Roster::sort(){
      for (int i=1; i< used;i++){
            Student key=students[i];//save the key

            //compare current element with predecessor
               if (key<students[i-1]){
                  //0  4 3 2
                  //i=1: key=4
                  //is 4 less than 0? -> no
                  //i=2: key= 3
                  // is 3 < 4? -> yes
                  //1st pass of while loop:
                  //saved=4;
                  //iterator=1
                  //if 3<4-> true
                  //saved=4
                  //key=3
                  //students[iterator]=students[iterator+1]
                  //my array should be: 0 4 4 2
                  //students[2]=ke
                  int iterator=i-1;
                  Student saved;
                  while (iterator>=0){
                     if (key<students[iterator]){
                        
                        saved=students[iterator];
                        students[iterator+1]=saved;
                        students[iterator]=key;//set the empty index to the student we saved; this "swaps" the two indices

                        iterator--;
                     }

                  }//by this point, iterator should be a value that is the greatest index of the sorted pile+1 (there should be no students
                  //at this index because of the swapping that occur in the while loop earlier)

               }
         }
      }
      //destructor
      Roster::~Roster(){
         delete [] students;
      }
      //  = operator overload
      const Roster& Roster:: operator=(const Roster& rightSide){
         if (this==&rightSide){
            return *this;
         }
         delete [] students;
         capacity=rightSide.capacity;
         used=rightSide.used;
         students= new Student[capacity];
         for (int i=0; i< capacity; i++){
            students[i]=rightSide.students[i];
         }
         return *this;
      }
      //copy constructor
      Roster::Roster(const Roster& construct){
         courseName=construct.courseName;
         courseCode=construct.courseCode;
         instructorName=construct.instructorName;
         numberCreds=construct.numberCreds;
         used=construct.used;
         capacity=construct.capacity;
         students=new Student[capacity];
         for (int i=0;i< capacity;i++){
            students[i]=construct.students[i];
         }
      }
      //bracket operator overload
      Student& Roster::operator [](int i){
         return students[i];
      }
   
   
   


