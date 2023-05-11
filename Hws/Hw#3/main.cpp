#include "roster.h"
#include "student.h"
#include <string>
using namespace std;

int main(){
   Roster CSCI211("Object Oriented Programming in C++","CSCI 211", "Yosef The Great", 4);//1. create a roster object
   //2. append 2 objects to it.
   CSCI211.input(MAX_CAPACITY-1);
   cout<<"first output to view roster object: "<<endl;
   CSCI211.output();
   //3. Test the add function with student Shmurda, Bobby (<LastName FirstName>Format)
    Student Krishna;
    //reminder:student constructor takes input in format: lastName firstName, standing, credits, GPA, Date of birth, Matriculation day
    Student Bobby("Shmurda", "Bobby","upper senior",106,98.5, "September 1st, 2004", "June 16,2022");
    CSCI211.addStudent(Bobby);
    cout<< "Now we are testing to see if Bobby was successfully added to the array:"<<endl;
    CSCI211.output();
    if (CSCI211.searchStudent(Bobby)){
      cout <<"Confirmed via searchStudent function: Bobby is there!"<<endl;//if Bobby is not in the output function and this prints out, this is a problem.
    }//if 
    
    CSCI211.addStudent(Krishna);//should fail, the console is meant to print out "roster is full" and NOT add Krishna
    
    cout<<endl<<"testing delete function"<<endl;
    Student Flay("Flay", "Bobby",55,98.5, "September 1st, 2005", "June 18,2022");
    CSCI211.deleteStudent(Bobby);//test Remove function
    CSCI211.addStudent(Flay);
    if (CSCI211.searchStudent(Flay)){
      cout<<"we were able to add Mr. Flay!"<<endl;
    }
    cout<<"second output to view roster object (Flay has been added, Bobby has been removed)"<<endl;
    CSCI211.output();
    //verify that setters/getters work:
      //setter verification
    CSCI211.setCN("Object Oriented Programming in Java");
    CSCI211.setCC("CSCI212");
    CSCI211.setIN("Kenneth the Lord");
    CSCI211.setNC(4);
    CSCI211.addStudent(Bobby);
      //getter verification
    cout<<"verify Course Name get works: "<< CSCI211.getCN()<<endl<<
      "verify Course Code get works: " <<CSCI211.getCC()<<endl<<
      "verify Course Instructor get works: " <<CSCI211.getIN()<<endl<<
      "verify Course Credits get works: " <<CSCI211.getNC()<<endl;
    
    
    Student beta=CSCI211.searchStudent("Bobby");
    cout<<"verify that search student with name of student input works "<<endl<<endl;
    beta.output();
    
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
    //the above is to be added when we do hw 4 and make dynamic arrays
    return 0;
}