#include<iostream>
#include<vector>
#include<ctime>
#include<time.h>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	vector<int> :: iterator it = v.begin();
	vector<int> :: iterator itend = v.end();
			
			// Erase function
			while(it != itend)
			{
				if(*it == 3)
				{
					v.erase(it); 
					itend = v.end();
				
				}
				else
				{
					it++;
				}
			}
	
	
	
	
	
}