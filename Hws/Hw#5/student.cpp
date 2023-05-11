#include "student.h"
#include <string>
#include <iostream>
using namespace std;

 
    Student::Student(string id,string ln, string fn, int creds, int gangplankAverage, Date dobby, Date mday){//takes all parameters as specified in instructions
        ID=id;
        lastName=ln;
        firstName=fn;
        credits=creds;
   
        gpa=gangplankAverage;
        dob=dobby;
        matriculationDay=mday;
    }
    Student::Student(){ 
        ID="000000000";
        lastName="";
        firstName="";
        standing="";
        credits=0;
        gpa=0.0;
        dob=Date();
        matriculationDay = Date();
    }
    string Student::lastNameGet()const {  
        return lastName;
        }
    string Student::firstNameGet()const{
        return firstName;
    }
    string Student::standingGet() const{
        return standing;
    }
    int Student::creditsGet() const {
        return credits;
    }
    double Student::gpaGet()const{
        return gpa;
    }
    Date Student::dobGet()const{
        return dob;
    }   
    Date Student::matriculationDayGet()const{
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
    void Student::dobSet(Date dobby){
        dob=dobby;
    }
    void Student::matriculationDaySet(Date mday){
        matriculationDay=mday;
    }
    bool Student::isStudent(){ //not used as of hw 5
        if (firstNameGet()==""){
                return false;
            }else{
                return true;
            }
    }
     bool Student:: operator != ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        if(x!=y){
            return true;
        }else{
            return false;
        }
        return false;
    }
     bool Student:: operator == ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        if(x==y){
            return true;
        }else{
            return false;
        }
    }
     bool Student:: operator > ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        if(x>y){
            return true;
        }else{
            return false;
        }
    }
     bool Student:: operator < ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        
        if(x<y){
            return true;
        }else{
            return false;
        }
    }
    bool Student:: operator <= ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        if(x<=y){
            return true;
        }else{
            return false;
        }
    }
    bool Student:: operator >= ( const Student& two) const{
        string x=lastName+firstName+ID;
        string y=two.lastName+two.firstName+two.ID;
        if(x>=y){
            return true;
        }else{
            return false;
        }
    }
   
    istream&  operator >>(istream& one,  Student& two){
            cout<< "please enter 8 digit Student ID#"<<endl;
            one>>two.ID;
            
            cout<< "please enter lastName"<<endl;
            one>>two.lastName;
            one.ignore();

            cout<<"please enter firstName"<<endl;
            one>> two.firstName;
            one.ignore();

            cout<<"please enter your date of birth:"<<endl;
            one>>two.dob;
            one.ignore();

            cout<<"Please enter date of Matriculation: "<<endl;
            one>> two.matriculationDay;
            one.ignore();
            
            cout<<"please enter integer # of credits for student: "<<endl;
            one>>two.credits;
            two.creditsSet(two.credits);//set standing through credit mutator
            cout<<"please enter your gpa with decimal points included (as a double): "<<endl;
            one>>two.gpa;
            one.ignore();

            return one;
      }
      ostream& operator <<(ostream& one , const Student& two){
        one<< "Last Name: "<<two.lastName<<endl
        << " First Name: "<<two.firstName<<endl
        << " ID #: " << two.ID<<endl
        << "Standing: "<<two.standing<<endl
        << "Credits: "<<two.credits<<endl
        << "Gpa: "<<two.gpa<<endl
        << "DOB: "<<two.dob<<endl
        << "Matriculation Day: "<<two.matriculationDay<<endl;

        return one;
        //consider using sstream libr
      }

    

    // void Student::output(){
    //     cout<< "last name: "<<lastName<<endl;
    //     cout<<" first name: "<<firstName<<endl;
    //     cout<< "standing: "<<standing<<endl;
    //     cout<< "credits: "<<credits<<endl;
    //     cout<< "gpa: "<<gpa<<endl;
    //     cout<< "dob: "<<dob<<endl;
    //     cout<< "matriculationDay: "<<matriculationDay<<endl<<endl;

    // }


