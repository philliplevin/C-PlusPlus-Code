#include<iostream>
#include<cassert>

using namespace std;

int main()
{
   bool numberIsCorrect = false;
   int n;
   
   while (numberIsCorrect == false)
   {
      cout << "What is the number?" << endl;
      
      cin >> n;
      
      if (n < 1023)
         cout << "Too small." << endl;
         
      else if (n > 1023)
         cout << "Too big." << endl;
      
      else
         numberIsCorrect = true;
   }
   
   cout << "You got it!" << endl;
}
