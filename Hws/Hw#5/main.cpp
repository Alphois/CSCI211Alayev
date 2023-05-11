#include "roster.h"
#include "student.h"
#include <string>
using namespace std;

int main(){
   Roster CSCI211("Object Oriented Programming in C++","CSCI 211", "Yosef The Great", 4);//1. create a roster object
  //will initialize with used=0, and capacity=0

   //2. append 2 objects to it.
  //  cout<< "pls input into roster object: "<<endl<<endl;
  //  cin>>CSCI211;
  //  cout<<"first output to view roster object: "<<endl<<endl;
  //  cout<<CSCI211<<endl;
   //how to test sorting algorithm:
    //1) make student object with name Auruv
    //2) make student object with name Buruv
    //3) add the second object first
    //4) then add the first object
   //3. Test the add function with student Shmurda, Bobby (<LastName FirstName>Format)

    //reminder:student constructor takes input in format: ID, lastName firstName, standing, credits, GPA, Date of birth, Matriculation day
    Date BobbyDOB(9,1,2004);
    Date BobbyMday(11,25,2000);
    Student Bobby("21979550", "Buruv", "Bobby",106,98.5, BobbyDOB, BobbyMday);
    CSCI211.addStudent(Bobby);
    cout<< "Now we are testing to see if Bobby was successfully added to the array:"<<endl;
    cout<<CSCI211;
     Date FlayDOB(9,1,2004);
    Date FlayMday(11,25,2000);
    Student Matthew("23998894","Zuruv", "Bobby",55,98.5, FlayDOB,FlayMday );

    CSCI211.addStudent(Matthew);
    Student Flay("23998894","Auruv", "Bobby",55,98.5, FlayDOB,FlayMday );

    CSCI211.addStudent(Flay);
    cout<< "Now check, is the roster in sorted order?"<<endl;
    cout<<CSCI211;
    //to test out bracket operator overload:
    cout<<"to test out bracket operator overload and assignment operator overload: (should be same thing printed twice)"<<endl;
    Roster CSCI212(CSCI211);
    for (int i=0;i< CSCI212.used;i++){
      cout<<CSCI212[i];
    }
    cout<<"test out copy constructor next assignment(?)"<<endl;
    // if (CSCI211.searchStudent(Bobby)){
    //   cout <<"Confirmed via searchStudent function: Bobby is there!"<<endl;//if Bobby is not in the output function and this prints out, this is a problem.
    // }//if 
    
    // CSCI211.addStudent(Krishna);//should fail, the console is meant to print out "roster is full" and NOT add Krishna
    
    // cout<<endl<<"testing delete function"<<endl;
   
    // CSCI211.deleteStudent(Bobby);//test Remove function
    // CSCI211.addStudent(Flay);
    // if (CSCI211.searchStudent(Flay)){
    //   cout<<"we were able to add Mr. Flay!"<<endl;
    // }
    // cout<<"second output to view roster object (Flay has been added, Bobby has been removed)"<<endl;
    // cout<<CSCI211;
    // //verify that setters/getters work:
    //   //setter verification
    // CSCI211.setCN("Object Oriented Programming in Java");
    // CSCI211.setCC("CSCI212");
    // CSCI211.setIN("Kenneth the Lord");
    // CSCI211.setNC(4);
    // CSCI211.addStudent(Bobby);
    //   //getter verification
    // cout<<"verify Course Name get works: "<< CSCI211.getCN()<<endl<<
    //   "verify Course Code get works: " <<CSCI211.getCC()<<endl<<
    //   "verify Course Instructor get works: " <<CSCI211.getIN()<<endl<<
    //   "verify Course Credits get works: " <<CSCI211.getNC()<<endl;
    
    
    // Student beta=CSCI211.searchStudent("Bobby");
    // cout<<"verify that search student with name of student input works "<<endl<<endl;
    // cout<<beta<<endl;    
    //testing of second constructor for roster function
    /*===================== 
    Student arividerci[MAX_CAPACITY];
    Student* c=arividerci;
    string test="k";
    for (int i=0;i<MAX_CAPACITY;i++){
      Student Flay(test, "Bobby",55+i,98.5, "September 1st, 2005", "June 18,2022");      
    }
    Roster CSCI212("Object Oriented Programming in Java", "CSCI 212", "Kenneth the Lord",4, c);
    CSCI212.output(); 
    ======================*/
    return 0;
}

  
      