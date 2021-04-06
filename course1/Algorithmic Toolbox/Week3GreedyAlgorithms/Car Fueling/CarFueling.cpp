#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
#include <bits/stdc++.h>
using namespace std;


int main()
{
int d;
int m;
int n;
cin >> d >> m >> n;

int stops[n + 2];
   stops[n + 1] = d;
   stops[0]=0;
   	for (int i = 1; i <= n; i++)
	{
		cin >> stops[i];
	}
  int currRefill = 0; 
  int numRefill = 0;
  int bad = 0 ;

while (currRefill <= n)
	{
		int lastRefill = currRefill;
		while ((currRefill <= n) && ((stops[currRefill + 1] - stops[lastRefill]) <= m)) 
			currRefill= currRefill + 1;

                 if (currRefill == lastRefill)	
                  {
			bad = 1; 
			break;	  
		}	
                else if (currRefill <= n)
                    numRefill= numRefill+1;
                 }
          	if (bad == 0)
		cout << numRefill << endl;
                    	else
		cout << "-1" << endl;	
                 return 0;
}					
