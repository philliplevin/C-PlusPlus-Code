#include <iostream>
using namespace std;

/* 
   Test cases
   
   Input    Output
   2        2
   3        3
   4        2
   6        2 3
   8        2 2 2
   9        3 3
   27       3 3 3
   31       31
   100      2 2 5 5   
*/

int main ()
{
   int n;
   cout << "Enter an integer greater than 1." << endl;
   cin >> n;
   
   cout << "The prime factors are: ";
   
   int k = 2;
 
   while (n > 1)
   {
      if (n % k == 0)
      
     {
         cout << k << " ";
         n = n / k; 
     }
     
     else
     {
         ++k;
     }
   }
   
   cout << endl;  
}
