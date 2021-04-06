#include <iostream>

int get_change(int m) {
  //write your code here
  int i=0 ;
  int Min=m ;
 while (i <Min)
{  if( (m-1)<= 0)
     {i= i+1 ;
     m=m-1;}
   else if ((m-5)<=0) 
    {i=i+1 ;
    m=m-1;}
    else ((10-m)<=0)
        
      ;{i =i+1;
        m=m-1;}   
   


}
  return i;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
