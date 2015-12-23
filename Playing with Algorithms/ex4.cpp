#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main ()
{

   srand(time(0));
   
   for (int i = 0; i < 100; ++i)
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
      
      cout << endl;  
      
   }
      
}
