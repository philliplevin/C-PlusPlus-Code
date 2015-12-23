#include <iostream>
#include <vector> 
#include <cassert>

using namespace std;

// Global variables
const int ROWS = 4;
const int COLS = 3;

// Function declarations
double findMax(double a[ROWS][COLS]);

// Main

int main()
{
   // 2D array w/ rows = 4, cols = 3
   // Function that finds max value in array and returns it
   
   double array1[ROWS][COLS] = { {5, 4, 9}, {3, 5, 10}, {15, 39, 141}, {0, 3, 9} };
                            
   assert(findMax(array1) == 141);
  
   double array2[ROWS][COLS] = { {-20, -20, -20}, {-20, -20, -20}, {-20, -20, -20}, {-20, -20, -20} };
                           
   assert(findMax(array2) == -20);
   
   cout << "All tests passed!" << endl;    

}

// Function definitions 
double findMax(double a[ROWS][COLS])
{
   int largest = a[0][0]; 
   
   for (int i = 0; i <= ROWS - 1; ++i)
   {
      for (int j = 0; j <= COLS - 1; ++j)
      {
         if(a[i][j] > largest)
            largest = a[i][j];
      }
   }
   
   return largest;
}

