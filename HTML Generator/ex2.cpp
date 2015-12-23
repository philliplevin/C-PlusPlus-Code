#include <iostream>
using namespace std;

// Function Declarations 

bool is_prime(int n);

// Main Function

/*
Prints all prime numbers from 2 to n (where n is a number entered by the user).
*/

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

            if (is_prime(k) == true)
            {
               cout << k << endl;
            }   
 
         }
        
      cout << "That's all of them!" << endl;  
   }
   
   cout << endl;
    
 }


// Function Definitions 

/*
Checks to see if n is prime.
   If it is prime returns true.
   If it is not prime returns false.
*/

bool is_prime(int n)
{
   for (int i = 2; i < n; ++i)
   {
      if (n % i == 0)
      {
          return false;
      }
   }
   
   return true;
}

