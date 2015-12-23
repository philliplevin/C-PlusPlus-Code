/*
   The following code has been tested and works with the following numbers: 
   
   input    output
   0        0 is not a prime number          
   1        1 is not a prime number
   3        3 is a prime number
   6        6 is not a prime number
   9        9 is not a prime number
   11       11 is a prime number
   15       15 is not a prime number
   17       17 is a prime number
   31       31 is a prime number
   100      100 is not a prime number
*/

#include <iostream>

using namespace std;

int main () 
{

  int suppliednumber; 

  cout << "Enter an integer greater than 1." << endl;
  cin >> suppliednumber; 
  
  int x = 1;
  int modcalc = 0;
  int z = 0; // This variable is the record of all cases of modulo = 0. Prime numbers will have 2 cases where modulo = 0 (when divided by 1 and itself). 

  if (x <= suppliednumber) 
  {
     while (x <= suppliednumber) 
     { 
         modcalc = suppliednumber % x;

       ++x; // This while loop runs until x = the supplied number.

       if (modcalc == 0) 
       {
          ++z; // If modulo = 0 (meaning the supplied # divides without a remainder), z is incremented, to keep track of the number of times this occurs. t
       }
  
     }
  }

// The possible outputs are as follows: 

  if (z > 2) 
  {  
     cout << suppliednumber << " is not a prime number." << endl; 
  } 

  if (z == 2) 
  {  
     cout << suppliednumber << " is a prime number." << endl; 
  } 

  if (suppliednumber <= 1) 
  {
     cout << suppliednumber << " is not a prime number." << endl;
  }

}
