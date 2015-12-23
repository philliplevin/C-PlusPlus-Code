/*
   The following code has been tested and works with the following numbers: 
   
   input    output
   0        Prompts for re-entry
   1        Prompts for re-entry
   3        2, 3
   6        2, 3, 5   
   9        2, 3, 5, 7
   11       2, 3, 5, 7, 11
   15       2, 3, 5, 7, 11, 13
   20       2, 3, 5, 7 11, 13, 17, 19
   100      2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
*/

#include <iostream> 

using namespace std;

int main ()
{
   int n;
   
   cout << endl;
   cout << "Enter an integer greater than 1. All prime numbers from 2 to the number entered will be computed. " << endl;
   
   cin >> n;
   
   cout << endl;
   
   if (n <= 1)
   {
      cout << "You entered " << n << ". You must enter an integer greater than 1. Try again." << endl;
   }
   
   else
   {
      cout << "The following are the prime number(s) from 2 to " << n << ":" << endl;
         for (int k = 2; k <= n; ++k)
         {
            bool found_divisor_for_k = false;
            
            for (int i = 2; i < k; ++i)
            {
      
               if (k % i == 0)
               {
                  found_divisor_for_k = true;
                  break;
               }
            }  
      
            if (found_divisor_for_k == false && k < n)
            {
               cout << k << endl;
            }   
      
            if (found_divisor_for_k == false && k == n)
            {
               cout << k << endl;
            }     
 
        }
        
      cout << "That's all of them!" << endl;  
   }
   
   cout << endl;
    
 }
