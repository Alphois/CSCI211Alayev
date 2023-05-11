#include "roster.h"
#include "student.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int main(){
  //create the roster array:
  vector<Roster> rosters;
  ifstream rosterRead;
  rosterRead.open("rosters.txt");
  string iterator;//valid cause this iterator has different scope from other
  int rosterCounter;

  if (rosterRead.fail( )){
    cout << "Input file opening failed.\n";
    exit(1);
  }else{
    while (!rosterRead.eof()){
      getline(rosterRead, iterator);
      if (iterator=="end_roster|"){
        rosterCounter++;
      }
    }//by now you have determined how many rosters there are.
    //this is where the processing begins....
    //for first line, this is the actual roster info:
    rosterRead.close();
    rosterRead.open("rosters.txt");
    if (rosterRead.fail()){
      cout<<"failed to read roster";
      exit(0);
    }
    cout<<"retrieving current roster information..."<<endl;
    for (int i=0; i< rosterCounter;i++){
      string courseName;
      string courseCode;
      int numberCreds;
      string instructorName;

      getline(rosterRead, iterator, '|');
      if (iterator[0]=='\n'){
        courseName=iterator.substr(1,iterator.length()-1);
      }else{
        courseName=iterator;
      }
      getline(rosterRead, iterator, '|');
      courseCode=iterator;
      
      getline(rosterRead, iterator, '|');
      numberCreds=stoi(iterator);      

      getline(rosterRead, iterator);
      instructorName=iterator;

      Roster baal(courseName,courseCode, instructorName,numberCreds);
    
      while (iterator!="end_roster"){//this part handles all the students
        Student a;
        
        getline(rosterRead,iterator, '|');
        a.firstNameSet(iterator);
        
        getline(rosterRead,iterator, '|');
        a.lastNameSet(iterator);
        
        
        getline(rosterRead, iterator, '|');
        a.IDSet(iterator);
        
        
        getline(rosterRead,iterator, '|');
        a.standingSet(iterator);
        
        getline(rosterRead,iterator, '|');
        a.creditsSet(stoi(iterator));
        
        getline(rosterRead,iterator, '|');
        a.gpaSet(stod(iterator));

        Date b; 
        
        getline(rosterRead, iterator, '/');
        b.setMonth(stoi(iterator));

        
        getline(rosterRead, iterator, '/');
        b.setDay(stoi(iterator));

        getline(rosterRead, iterator, '|');
        b.setYear(stoi(iterator));

        Date c;
        getline(rosterRead, iterator, '/');
        c.setMonth(stoi(iterator));

        getline(rosterRead, iterator, '/');
        c.setDay(stoi(iterator));

        getline(rosterRead, iterator);
        c.setYear(stoi(iterator));


        a.dobSet(b);
        a.matriculationDaySet(c);
        baal.addStudent(a);

        //while loop iteration handling
        int len = rosterRead.tellg();//get current position

        // Read line
        getline(rosterRead, iterator,'|');
        // Return to position before "Read line" iff the next line is not end_roster
        if (iterator!="end_roster"){
          rosterRead.seekg(len-5*rosterCounter,std::ios_base::beg);
        }
      }
    rosters.push_back(baal);
    }//for loop
    //by now your vector of rosters should have completely read from the input file.
    rosterRead.close();
  }//else
  cout<<"Choose Mode:"<<endl
    <<"Supervisor Mode"<<endl
    <<"User Mode"<<endl
    <<"Exit"<<endl
    <<"type desired mode exactly as displayed"<<endl;

  string userResponse;
  getline(cin,userResponse);
  while (userResponse!="Exit"){
  if (userResponse=="Supervisor Mode"){
    ifstream instream;
    instream.open("database.txt");
    
    int lineCounter;

    string user;
    string pwd;
    string iterator;
    bool userValid=false;
    bool pwdValid=false;  
    cout<<"type Username: "<<endl;
    cin>>user;
    cout<<"type pwd: "<<endl;
    cin>>pwd;
    //what if a username is the same as a password?
    while(!instream.eof()){
      lineCounter++;
      getline(instream, iterator);
      if (lineCounter%2==1){//if its an odd #'d line (the first line is one)
        //then you check username
        if (user==iterator){
          userValid=true;
          getline(instream, iterator);
          if (pwd==iterator){
            pwdValid=true;
          }//pwd validation
        }//user validation 
      }//username line check
    }//end of while loop
    if (userValid==false||pwdValid==false){
      if (userValid==false){
        cout<< "wrong username! exiting!"<<endl;
        exit(0);
      }
      if (pwdValid==false){
        cout<< "wrong password! exiting!"<<endl;
        exit(0);
      }
    }//authenticator check
  //turn into hashmap?
    cout<<" In Supervisor Mode you have options to:"<<endl
      <<"1)	Create a new Roster "<<endl
      <<"2)	Drop a Roster (selected by course number)"<<endl
      <<"3)	Display Roster information (selected by course number)"<<endl
      <<"4)	Display all Rosters (in your system)"<<endl
      <<"5)	Select a Roster to perform following operations:"<<endl
      <<"    a) Insert new Student to a Roster"<<endl
      <<"    b) Remove a Student from a Roster"<<endl
      <<"    c) Update a Student in a Roster"<<endl
      <<"    d) List all Students in one Roster in sorted order"<<endl
      <<"6) Exit the program"<<endl;
      cout<<"here are the current rosters"<<endl;
      for (int i=0;i<rosters.size();i++){
        rosters[i].outputCourse();
      }
      cout<<"Select the number of the command you would like to use (1-5)"<<endl;
      //what commands can the user use?
      // create new Roster
      
     
      int command;
      cin>> command;
      cin.ignore();
      while (command!=6){
        if (command==1){//add a roster/class
          Roster a;
          cin>>a;
          rosters.push_back(a);
          for (int i=0;i<rosters.size();i++){
            rosters[i].outputCourse();
          }
        }
        if (command==2){
          cout<<"Please type the course code of the roster you which to drop"<<endl;
          string rosterDrop;
          cin>>rosterDrop;
          bool erased=false;
          for (int i=0;i<rosters.size();i++){
            if (rosters[i].getCC()==rosterDrop){
              rosters.erase(rosters.begin()+i-1,rosters.begin()+i);
            }
              erased=true;
          }
          if (erased){
            cout<<"roster has been deleted successfully"<<endl;
          }
          for (int i=0;i<rosters.size();i++){
            rosters[i].outputCourse();
          }
        }//if command is 2(delete a roster)
        if (command==3){
          string rosterView;
          cin>>rosterView;
          bool view=false;
          for (int i=0;i<rosters.size();i++){
            if (rosters[i].getCC()==rosterView){
              rosters[i].outputAll();
            }
          }
        }//if command is 3( view a specific roster)
        if (command==4){
          cout<<"displaying all rosters..."<<endl;
          for (int i=0;i<rosters.size();i++){
            rosters[i].outputAll();
          }
        }//if command is 4(view all rosters info)
        if (command==5){
          string rosterUpdater;
          cout<<"select a roster by typing in the course code to add/remove/update a student"<<endl;
          cin>> rosterUpdater;
          int indexOfRoster;
          for (int i=0;i<rosters.size();i++){
            if (rosters[i].getCC()==rosterUpdater){
              indexOfRoster=i;
            }
          }
          rosters[indexOfRoster].outputAll();
          int fiveCommand;
          cout<<"What would you like to do?"<<endl
              <<"    1) Insert new Student to a Roster"<<endl
              <<"    2) Remove a Student from a Roster"<<endl
              <<"    3) Update a Student in a Roster"<<endl
              <<"    4) List all Students in one Roster in sorted order"<<endl
              <<"    5) exit "<<endl;
          cout<<"enter the # of the command you would like to invoke: "<<endl;
          cin>>fiveCommand;
          while (fiveCommand!=5){
              if (fiveCommand==1){
                Student a;
                cout<<"enter student information to go into the roster with the code "<< rosters[indexOfRoster].getCC()<<endl;
                cin>>a;
                rosters[indexOfRoster].addStudent(a);
              }
              if (fiveCommand==2){
                string studentid;
                cout<<"enter student id of the student you would like to delete from roster with the code "<< rosters[indexOfRoster].getCC()<<endl;
                cin>>studentid;
                rosters[indexOfRoster].deleteStudent(studentid);
              }
              if (fiveCommand==3){
                Student a;
                string studentid;
                cout<<"enter student id of the student you would like to update from roster with code "<< rosters[indexOfRoster].getCC()<<endl;
                cin>>studentid;
                int indOfStudentUpdate=rosters[indexOfRoster].searchStudent(studentid);

                if (indOfStudentUpdate==-1){
                  cout<<"that student with id #"<< studentid<<" does not appear to be in the roster"<<endl;
                }else{
                  cout<<"enter student information you would like to have in place of the following student: "<<endl
                      <<rosters[indexOfRoster][indOfStudentUpdate]<<endl;
                  cin>>a;
                  rosters[indexOfRoster][indOfStudentUpdate]=a;
                  cout<<"Displaying updated Roster with code" << rosters[indexOfRoster].getCC()<<endl;
                  rosters[indexOfRoster].outputAll();
                }
              }
              if (fiveCommand==4){
                rosters[indexOfRoster].outputAll();
              }
            cout<<"please enter your next command/action for this Roster (1-5): "<<endl<<rosters[indexOfRoster]<<endl;
            cout<<"What would you like to do?"<<endl
              <<"    1) Insert new Student to this Roster"<<endl
              <<"    2) Remove a Student from this Roster"<<endl
              <<"    3) Update a Student in this Roster"<<endl
              <<"    4) List all Students in this Roster in sorted order"<<endl
              <<"    5) exit "<<endl;
          cout<<"enter the # of the command you would like to invoke: "<<endl;
          cin>> fiveCommand;
          }//while loop
        }
        cout<<" In Supervisor Mode you have options to:"<<endl
      <<"1)	Create a new Roster "<<endl
      <<"2)	Drop a Roster (selected by course number)"<<endl
      <<"3)	Display Roster information (selected by course number)"<<endl
      <<"4)	Display all Rosters (in your system)"<<endl
      <<"5)	Select a Roster to perform following operations:"<<endl
      <<"    a) Insert new Student to a Roster"<<endl
      <<"    b) Remove a Student from a Roster"<<endl
      <<"    c) Update a Student in a Roster"<<endl
      <<"    d) List all Students in one Roster in sorted order"<<endl
      <<"6) Exit the program"<<endl;
      cout<<"please enter your next command # (1-6): "<<endl;

        cin>>command;
      }
  }
  if (userResponse=="User Mode"){
    cout<<"You will be asked to select a Roster"<<endl
        << "1) you may insert a new Student after selecting the roster"<<endl
        << "2) remove a student after selecting the roster,"<<endl
        << "3) or update the Student in a roster. "<<endl
        << "4) exit "<<endl
        <<"displaying all currently available rosters"<<endl;
    for (int i=0;i<rosters.size();i++){
      rosters[i].outputAll();
    }
    string rosterUpdater;
    cout<<"select a roster by typing in the course code to add/remove/update a student"<<endl;
    cin>> rosterUpdater;
    int indexOfRoster;
    for (int i=0;i<rosters.size();i++){
      if (rosters[i].getCC()==rosterUpdater){
              indexOfRoster=i;
      }
    }
    int userCommand;
    cout<<"what command would you like to invoke on roster "<<rosters[indexOfRoster].getCC()<<"?(1-4)"<<endl
        << "1) you may insert a new Student after selecting the roster"<<endl
        << "2) remove a student after selecting the roster,"<<endl
        << "3) or update the Student in a roster. "<<endl
        << "4) exit "<<endl;
    cin>>userCommand;
    while(userCommand!=4){
      if (userCommand==1){
        Student a;
        cout<<"enter student information to go into the roster with the code "<< rosters[indexOfRoster].getCC()<<endl;
        cin>>a;
        rosters[indexOfRoster].addStudent(a);
      }
      if (userCommand==2){
                  string studentid;
                  cout<<"enter student id of the student you would like to delete from roster with the code "<< rosters[indexOfRoster].getCC()<<endl;
                  cin>>studentid;
                  rosters[indexOfRoster].deleteStudent(studentid);
      }
      if (userCommand==3){
        Student a;
        string studentid;
        cout<<"enter student id of the student you would like to update from roster with code "<< rosters[indexOfRoster].getCC()<<endl;
        cin>>studentid;
        int indOfStudentUpdate=rosters[indexOfRoster].searchStudent(studentid);

        if (indOfStudentUpdate==-1){
          cout<<"that student with id #"<< studentid<<" does not appear to be in the roster"<<endl;
        }else{
          cout<<"enter student information you would like to have in place of the following student: "<<endl
              <<rosters[indexOfRoster][indOfStudentUpdate]<<endl;
          cin>>a;
          rosters[indexOfRoster][indOfStudentUpdate]=a;
          cout<<"Displaying updated Roster with code" << rosters[indexOfRoster].getCC()<<endl;
          rosters[indexOfRoster].outputAll();
        }

      }//if user command is 3
      cout<<"what command would you like to invoke on roster "<<rosters[indexOfRoster].getCC()<<"?(1-4)"<<endl
        << "1) you may insert a new Student after selecting the roster"<<endl
        << "2) remove a student after selecting the roster,"<<endl
        << "3) or update the Student in a roster. "<<endl
        << "4) exit "<<endl;
      cin>>userCommand;
    }
  }//user mode
    cout<<"Choose Mode:"<<endl
    <<"Supervisor Mode"<<endl
    <<"User Mode"<<endl
    <<"Exit"<<endl
    <<"type desired mode exactly as displayed"<<endl;
  cin.ignore();
  getline(cin,userResponse);
  }//while loop for supervisor mode
  if (userResponse=="Exit"){
    ofstream output;

    output.open("rosters.txt");
    for (int i=0;i<rosters.size();i++){
      output<<rosters[i];
    }
    output.close();
    cout<<"implementing changes in file..."<<endl;
    exit(0);
  }
    return 0;
}

  
      