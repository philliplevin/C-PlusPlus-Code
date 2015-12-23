#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

// Function Declarations
void hexgen();


// Main Function

// Main function calls a function, which generates XXXXXX (where X = a # or letter) in cout. After each call, it inserts a line break. It does this until 100 random XXXXXX have been printed into cout. 

int main ()
{

   srand(time(0));
   
   for (int i = 0; i < 100; ++i)
   {
      hexgen();        
      cout << endl;        
   }
      
}

// Function Definitions

// void hexgen() generates a series of 6 random numbers and/or letters. Numbers generated include 0 to 9. Letters generated are A to F. Function doesn't return any values, prints directly via cout. 


void hexgen()
{
         for (int x =0; x < 6; ++x) 
         { 
            int n = rand() % 16;
      
            if (n == 15) 
            {
               cout << 'F';
            }
      
            else if (n == 14) 
            {  
               cout << 'E';
            }
      
            else if (n == 13) 
            {
               cout << 'D';
            }
           
            else if (n == 12) 
            {
               cout << 'C';
            }      
      
            else if (n == 11) 
            {
               cout << 'B';
            }      
      
            else if (n == 10) 
            {
               cout << 'A';
            }
      
            else
            {
               cout << n;
            }     
         }
}
