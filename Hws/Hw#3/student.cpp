#include "student.h"
#include <string>
#include <iostream>

    Student::Student(string ln, string fn, int creds, int gangplankAverage, string dobby, string mday){//if the standing is not included, no big deal
        lastName=ln;
        firstName=fn;
        credits=creds;
        if (credits>=105){
            standingSet("Upper Senior");
        }else if(credits<105 && credits>=90){
            standingSet("Lower Senior");
        }else if(credits<90 && credits>=75){
            standingSet("Upper Junior");
        }else if(credits<75 && credits>=60){
            standingSet("Lower Junior");
        }else if(credits<60 && credits>=45){
            standingSet("Upper Sophomore");
        }else if (credits<45&& credits>=30){
            standingSet("Lower Sophomore");
        }else if (credits<30 && credits>=15){
            standingSet("Upper Freshman");
        }else if (credits<15 && credits>=0){
            standingSet("Lower Freshman");
        }
        gpa=gangplankAverage;
        dob=dobby;
        matriculationDay=mday;
    }
    Student::Student(string ln, string fn, string konoStando, int creds, int gangplankAverage, string dobby, string mday){//takes all parameters as specified in instructions
        lastName=ln;
        firstName=fn;
        credits=creds;

        standing=konoStando;
   
        gpa=gangplankAverage;
        dob=dobby;
        matriculationDay=mday;
    }
    Student::Student(){ 
        lastName="";
        firstName="";
        standing="";
        credits=0;
        gpa=0.0;
        dob="";
        matriculationDay="";
    }
    string Student::lastNameGet(){  
        return lastName;
        }
    string Student::firstNameGet(){
        return firstName;
    }
    string Student::standingGet(){
        return standing;
    }
    int Student::creditsGet(){
        return credits;
    }
    double Student::gpaGet(){
        return gpa;
    }
    string Student::dobGet(){
        return dob;
    }   
    string Student::matriculationDayGet(){
        return matriculationDay;
    }
    void Student::lastNameSet(string ln){
        bool valid=true;
        for (int i=0;i< ln.length();i++){
        if (isdigit(ln[i])){
            cout<<"please enter a valid name bro"<<endl;
            exit(1);
            valid=false;
        }
    }
        if (valid){
        lastName=ln;
    }

    }
    void Student::firstNameSet(string fn){
        bool valid=true;
        for (int i=0;i< fn.length();i++){
        if (isdigit(fn[i])){
            cout<<"please enter a valid name bro"<<endl;
            exit(1);
            valid=false;
        }
    }
        if (valid){
            firstName=fn;
        }

    }
    void Student::standingSet(string stand){
          standing=stand;
    }
    void Student::creditsSet(int credit){
        if (credit<0){
            cout<<"why do you have a negative # of credits? That doesn't even make sense!"<<endl;
            exit(0);
        }else{
        credits=credit;
        if (credits>=105){
                standingSet("Upper Senior");
            }else if(credits<105 && credits>=90){
                standingSet("Lower Senior");
            }else if(credits<90 && credits>=75){
                standingSet("Upper Junior");
            }else if(credits<75 && credits>=60){
                standingSet("Lower Junior");
            }else if(credits<60 && credits>=45){
               standingSet("Upper Sophomore");
            }else if (credits<45&& credits>=30){
                standingSet("Lower Sophomore");
            }else if (credits<30 && credits>=15){
                standingSet("Upper Freshman");
            }else if (credits<15 && credits>=0){
                standingSet("Lower Freshman");
            }
        }
    }
    void Student::gpaSet(double gp){
        if (gp>100.0){
               cout<<"its not possible to have 100+ gpa?"<<endl;
            exit(1);
        }else if (gp<0.0){
            cout<<"how do you even have a negative gpa?!"<<endl;
            exit(1);
        }else{
            gpa=gp;
        }
    }
    void Student::dobSet(string dobby){
        dob=dobby;
    }
    void Student::matriculationDaySet(string mday){
        matriculationDay=mday;
    }
    bool Student::isStudent(){
        if (firstNameGet()==""&&
            lastNameGet()==""&&
            standingGet()==""&&
            creditsGet()==0  &&
            gpaGet() == 0.0  &&
            dobGet()    == ""&&
            matriculationDayGet()==""
            ){
                return false;
            }else{
                return true;
            }
    }
    // const bool Student::operator ==(const Student& kanye) const{
    //     if (firstNameGet()==kanye.firstNameGet()&& (dobGet()==kanye.dobGet()) && (lastNameGet()==kanye.lastNameGet())){
    //         return true;
    //     }else{
    //         return false;
    //     }
    //     return false;
    // } //Modify this function in future so that it works
      bool Student::compare(Student kanye){
        if (firstNameGet()==kanye.firstNameGet()&& (dobGet()==kanye.dobGet()) && (lastNameGet()==kanye.lastNameGet())){
            return true;
        }else{
            return false;
        }
        return false;
    } //Modify this function in future so that it works
    void Student::input(){
            cout<< "please enter lastName"<<endl;
            string ln;
            getline(cin,ln);
            lastNameSet(ln);

            cout<<"please enter firstName"<<endl;
            string fn;
            getline(cin,fn);
            firstNameSet(fn);

            string doob;
            cout<<"please enter your date of birth:"<<endl;
            getline(cin, doob);
            dobSet(doob);

            string mday;
            cout<<"Please enter date of Matriculation: "<<endl;
            getline(cin,mday);
            matriculationDaySet(mday);
            int creed;
            cout<<"please enter integer # of credits for student: "<<endl;
            cin>>creed;
            creditsSet(creed);

            double geepee;
            cout<<"please enter your gpa with decimal points included (as a double): "<<endl;
            cin>>geepee;
            gpaSet(geepee);
            cin.ignore();


    }
    void Student::output(){
        cout<< "last name: "<<lastName<<endl;
        cout<<" first name: "<<firstName<<endl;
        cout<< "standing: "<<standing<<endl;
        cout<< "credits: "<<credits<<endl;
        cout<< "gpa: "<<gpa<<endl;
        cout<< "dob: "<<dob<<endl;
        cout<< "matriculationDay: "<<matriculationDay<<endl<<endl;

    }

