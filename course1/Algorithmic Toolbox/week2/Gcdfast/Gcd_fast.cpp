#include <iostream>

using namespace std;
  //GCD function

int GCD(int x , int y) {

  if (y == 0)
    return x;

    return GCD(y,x%y);

   /*if ( x == 0 || y == 0 )
     return 0;
   else if ( x == y )

   return x;
   
   else if (x > y && x%y==0)
   
   return GCD(y, y % x);
   
   else if (x<y && x%y==0)
   
    return GCD(x,x%y);

     //else if ((x < y && x%y !=0) && (x>1000 && y>1000) )
       //return 4 ;
     
   else if (x<y && x%y != 0)
        return 1 ; */
   

    //else return GCD(x,y%x);

   }

  int main(){
   int a,b ;
   //cout<<" insert a and b " ;
   cin >> a >> b ;
   cout<< GCD(a,b); 


}


