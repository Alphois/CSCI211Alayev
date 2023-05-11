#include <iostream>
#include "date.h"
using namespace std;
// Date::operator <<(const Date& thing) const;
//function for adding all the parts of the date:
int angelWithAShotgun(const Date& thing){
   int moonth=thing.getMonthNum();
   int yr=thing.getYear();
   int dai=thing.getDay();

   //IM AN ANGEL WITH A SHOTGUN
   int n=10;
   int sum=0;

   while(moonth!=0){
      sum+=moonth%n;
      moonth/=n;
   }
   while(dai!=0){
      sum+=dai%n;
      dai/=n;
   }
   while(yr!=0){
      sum+=yr%n;
      yr/=n;
   }
   while (sum>=10){
      sum=sum%10 + sum/10;
   }
   
   return sum;
   
}
int main(){
   int d1;
   cout<<"Sir User-highness, please give size of Date List please: ";
   cin>>d1;
   Date* dateEiji=new Date[d1];
   int* intEiji = new int[d1];

   for (int i=0;i< d1;i++){
      Date h;
      dateEiji[i]=h;
      dateEiji[i].input();
      //store/input date 

      // int munth=dateEiji[i].getMonthNum();
      // int yr=dateEiji[i].getYear();
      // int dai=dateEiji[i].getDay();

      intEiji[i]=angelWithAShotgun(dateEiji[i]);
      //create and store int in int array
      
      //now output both dates and their corresponding integers
   }
   cout<<endl;

   for (int i=0;i< d1;i++){
      dateEiji[i].output();
      cout<<endl<<"corresponding Integer: "<<intEiji[i]<<endl<<endl;
   }
   delete [] dateEiji;
   delete [] intEiji;
   return 0;
   // for (int i=0; )
}
