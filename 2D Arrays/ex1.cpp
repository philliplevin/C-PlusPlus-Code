#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

bool binarySearch (const vector<int> &v, int k)
{

   int s = 0; // start of vector
   int e = v.size() - 1; // end of vector
   
   while (s <= e)
   {
      int m = (s + e) / 2;
      
      if(k < v[m])
      {
         e = m - 1;
      }
      
      else if (k > v[m])
      {
         s = m + 1;
      }
      
      else if (k == v[m])
         return true;  
   }
   
   return false;

}


int main () 
{
   vector <int> v;
   v.push_back(3);  
   v.push_back(5); 
   v.push_back(7);  
   v.push_back(9); 
   v.push_back(12); 
   v.push_back(15); 
   
   
   assert(binarySearch(v, 3) == true); 
   assert(binarySearch(v, 12) == true); 
   assert(binarySearch(v, 5) == true);
   assert(binarySearch(v, 15) == true);
   assert(binarySearch(v, 7) == true);  
   
   assert(binarySearch(v, 0) == false); 
   assert(binarySearch(v, 6) == false);
   
   cout << "All tests passed." << endl;
   
   
}
