#include <iostream>
#include <cassert>
using namespace std;

// Function declarations
int search(int a[], int size, int k);

// Main function

int main()
{
   int array1[5] = {-2, 4, 18, 6, -10};
  
   assert(search(array1, 5, 1) == -1);
   assert(search(array1, 5, 0) == -1);
   
   assert(search(array1, 5, -2) == 0);
   assert(search(array1, 5, 4) == 1);
   assert(search(array1, 5, 18) == 2);
   assert(search(array1, 5, 6) == 3);
   assert(search(array1, 5, -10) == 4);
   
   cout << "All tests passed!" << endl;

}

// Function definitions

// This function performs a linear search. If k is present in the array, it returns the index value of k. If k is not in the array, it returns -1.
int search(int a[], int size, int k)
{
   for (int i = 0; i < size; ++i)
   {
      if(a[i] == k)
      return i;
   }   
   
   return -1;
}
