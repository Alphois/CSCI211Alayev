#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

class Student{
 //instance variables:
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
    void input();
    void output();
};
    
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
    lastName="Bob";
    firstName="Flick";
    standing="Lower Freshman";
    credits=0;
    gpa=0.0;
    dob="January 1st, 2004";
    matriculationDay="July 15, 2022";
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
    


    double geepee;
    cout<<"please enter your gpa with decimal points included (as a double): "<<endl;
    cin>>geepee;
    gpaSet(geepee);


}
void Student::output(){
    cout<< "last name: "<<lastName<<" first name: "<<firstName<<endl;
    cout<< "standing: "<<standing<<endl;
    cout<< "credits: "<<credits<<endl;
    cout<< "gpa: "<<gpa<<endl;
    cout<< "dob: "<<dob<<endl;
    cout<< "matriculationDay: "<<matriculationDay<<endl<<endl;

}
int main(){
    Student krishna;
    // char y='Y';
    // while (y='Y'){
    Student Bobby("Shmurda", "Bobby","upper senior",106,98.5, "September 1st, 2004", "June 16,2022");
    
    Student Flay("Flay", "Bobby",55,98.5, "September 1st, 2005", "June 18,2022");
    Bobby.output();
    Flay.output();
    
        krishna.input();
        krishna.output();
        //accessor func testing
    cout<<"the following lines are for testing accessor functions"<<endl<<endl;
    cout<<krishna.dobGet()<<endl;
    cout<< krishna.creditsGet()<<endl;
    cout<<krishna.gpaGet()<<endl;
    cout<<krishna.lastNameGet()<<endl;
    cout<<krishna.firstNameGet()<<endl;
    cout<<krishna.matriculationDayGet();
    cout<<krishna.standingGet();
        //mutator function testing;
    krishna.dobSet("9/1/2004");
    krishna.creditsSet(95);
    krishna.gpaSet(95.5);
    krishna.lastNameSet("Christ");
    krishna.firstNameSet("Jeesse");
    krishna.matriculationDaySet("June 19th, 2022");
    int credits=krishna.creditsGet();
        if (credits>=105){
        krishna.standingSet("Upper Senior");
    }else if(credits<105 && credits>=90){
        krishna.standingSet("Lower Senior");
    }else if(credits<90 && credits>=75){
        krishna.standingSet("Upper Junior");
    }else if(credits<75 && credits>=60){
        krishna.standingSet("Lower Junior");
    }else if(credits<60 && credits>=45){
        krishna.standingSet("Upper Sophomore");
    }else if (credits<45&& credits>=30){
        krishna.standingSet("Lower Sophomore");
    }else if (credits<30 && credits>=15){
        krishna.standingSet("Upper Freshman");
    }else if (credits<15 && credits>=0){
        krishna.standingSet("Lower Freshman");
    }
    
        // cout<<"continue inputting students? ('Y'/'N')"<<endl;
        // cin>>y;
    
    // }
    return 0;
}