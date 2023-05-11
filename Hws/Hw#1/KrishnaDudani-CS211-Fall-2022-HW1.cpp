// Name this file as: <First-Name><Last-Name>-CS211-Fall-2022-HW1.cpp
// Fill up the code to fulfill the requirements.
// Make sure your program compiles and runs before submit it.
// Only .cpp file should be uploaded into BlackBoard.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// ======================
//   Function prototypes
// ======================
void print_primes(int num);
void print_perfect_nums(int num);
void print_leap_years(int start, int end);
void print_reverse(int num);
bool gaussPrime(int num);
bool purrFection(int num);
bool theGreatLeapForward(int year);
int reversingPolarity(int num);

// ======================
//   Function Definitions
// ======================
void print_primes(int num)
{
    for (int i=2;i<=num;i++){
        if (gaussPrime(i)){
            cout<<i<<endl;
        }
    }
    // --------------------------------
    // ----- IMPLEMENT THE FUNCTION -----
    // ----- print primes between 1 and num
    // --------------------------------
}
bool gaussPrime(int num){
    if (num>2){
    for (int i=2;i<num;i++){
        if (num%i==0){
           return false;
        }
    }
    }else if (num==1){
        return false; //1 is not a prime number
    }
    return true;
}

void print_perfect_nums(int num)
{
   
    for (int i=0;i<=num;i++){
        if (purrFection(i)){
            cout<<i<<endl;
        }
    }
    // --------------------------------
    // ----- IMPLEMENT THE FUNCTION -----
    // ----- print perfect numbers between 1 and num
    // --------------------------------
}
bool purrFection(int num){
    int total=0;
    for (int i=1;i<num;i++){
        if (num%i==0){
            total+=i;
        }
    }
    return (total==num);
}
void print_leap_years(int start, int end)
{
    // --------------------------------
    // ----- IMPLEMENT THE FUNCTION -----
    // ----- print leap year between start and end
    // --------------------------------
    for (int i=start;i<=end;i++){
        if (theGreatLeapForward(i)){
            cout<<i<<", ";
        }
    }
    cout<<endl<<"the above line are all the leap years within given range"<<endl;
}
bool theGreatLeapForward(int year){
    return ((year%100!=0&&year%4==0)||year%400==0);
}

void print_reverse(int num)
{
    // --------------------------------
    // ----- IMPLEMENT THE FUNCTION -----
    // ----- print reverse of num
    // --------------------------------
//     do{
//         cout<< "give positive int pls (or negative if ur a quitter): "<<endl;
//         cin>> num;
//         if (num>0){
//         cout<<reversingPolarity(num)<<endl;
//         }
//         else{
//             break;
//         }
//     }
//     while(-1*num>0);
     //it should fine to assign positive integer to num since it gets reassigned later anyway;
    do{//user input loop: while num is +
        cout<<endl<<"pls give positive intpls (or negative if ur a quitter): "<<endl;
        cin>>num;
        reversingPolarity(num);
    }while (num*-1<0);
}
int reversingPolarity(int num){
    // int total=0;
    // //this is just like integer palindrome problem from leetcode !!
    // while ( num!=0){
    //     total+=num%10;
    //     total*=10;
    //     num/=10;
    // }
    // return total;
    //1) Find the digits
    int tmp=num;
    while (num>0){//print out reverse portion
            cout<<num%10; //this gives a ones digit
            num/=10;//cut out current ones digit and move to next place
        }
    num=tmp;
    int multFactor;
    if (num%10==0){//if its a multiple of 10 then:
        return 0; //there is no reverse integer of 10, u can't just return "01"
        }
        int total=0;
    while (num>0){
            total+=num%10;
            num/=10;
            if (num!=0){
            total*=10;
            }
        }//ones digit
    
    return total;
}


// ======================
//     main function
// ======================
int main()
{
    int num;
    cout << "EXECUTE PRINT_PRIMES----- \n";
     cout<<"pls enter + int: ";
    cin>> num;
    print_primes(num);
    // Call print_primes

    cout << "EXECUTE PRINT_PERFECT_NUMS----- \n";
    cout<<"pls enter + int: ";
    cin>> num;
    print_perfect_nums(num);
    // Call print_perfect_nums

    cout << "EXECUTE PRINT_LEAP_YEARS----- \n";

    // Call print_leap_years
    int start;
    int end;
    cout<< "pls enter positive integer: "<<endl;
    cin>>start;
    cout<< "pls enter a positive integer that is slightly extra thicc compared to the last one: "<<endl;
    cin>>end;
    print_leap_years(start,end);

    cout << "EXECUTE PRINT_REVERSE----- \n";
    // Repeatedly ask user for positive integer(until user enter a negative integer)
    // Call print_reverse
    int jesus;
    print_reverse(jesus);
    return 0;
}