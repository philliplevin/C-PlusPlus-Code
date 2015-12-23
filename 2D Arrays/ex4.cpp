#include<iostream>
#include<cassert>

using namespace std;

// Function declarations
int binarySearch(int a[], int size, int k);

// Main function
int main()
{
   int array1[5] = {-2, 4, 5, 6, 8};
   
   // Test code
   assert(binarySearch(array1, 5, 1) == -1);
   assert(binarySearch(array1, 5, 100) == -1);
   assert(binarySearch(array1, 5, -2) == 0);
   assert(binarySearch(array1, 5, 4) == 1);
   assert(binarySearch(array1, 5, 5) == 2);
   assert(binarySearch(array1, 5, 6) == 3);
   assert(binarySearch(array1, 5, 8) == 4);
   
   
   cout << "All tests passed!" << endl;
}


// Function definitions
int binarySearch(int a[], int size, int k)
{
   int start = 0;
   int end = size -1;
   
   
   while (start <= end)
   {
      int mid = (start + end) / 2;
      
      if (k < a[mid])
         end = mid - 1;
         
      else if (k > a[mid])
         start = mid + 1;
         
      else if (k == a[mid])
         return mid;
   }
   
   return -1;
}
