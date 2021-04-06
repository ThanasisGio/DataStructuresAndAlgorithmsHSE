#include <iostream> 
using namespace std;
 

long long GCD(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return GCD(b, a % b);
}
 
 
long long lcm(int a, int b)
{
    return (a / GCD(a, b)) * b;
}
  

int main() 
{ 
    int a ;
    int b ; 
    cin >> a >> b;
    cout<< lcm(a, b); 
    return 0; 
} 
