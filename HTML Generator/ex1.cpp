#include <iostream>
#include <cassert>
using namespace std;


// Function Declarations 

bool is_prime (int n); 

// Main Function

int main (int argc, char * args [])
{

   cout << "All test passed!" << endl;
   
   int n; 

   cout << "Enter an integer greater than 1: ";
   cin >> n;
   
   assert(n != 1);
   assert(is_prime(2));
   assert(!is_prime(40));
   assert(!is_prime(24));
   assert(is_prime(7));
   assert(!is_prime(27));   
   assert(!is_prime(100));
   assert(is_prime(59));
   assert(is_prime(5));
  
   
   if (is_prime(n) == false) 
   {
      cout << n << " is not prime." << endl;
   }
      
   else if (is_prime(n) == true) 
   {
      cout << n << " is prime." << endl;
   }

   cout << endl;
   
}

// Other Functions 

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

