// Phillip Levin, Rachel Soper 
// Sieve of Eratosthenes

#include<iostream>
#include<iomanip>
#include<set>
#include<vector>

using namespace std;

// Returns true if x is in vector
bool find(vector<int> v, int x)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(x == v[i])
		{
			return true;
		}
	}
	
	return false;
	
}

// Removes all non-prime numbers from a vector
void sieveVector(vector<int> &v, int n)
{
	int m, i;
	
	// Removes all elements in vector
	for(int i = 0; i < v.size(); i++)
	{
		v.pop_back();
	}
	
	// Inputs integers into vector, goes up to n
	for(int m = 2; m < n; m++)
	{
		v.push_back(m);	
	}
	
	// Finds the prime numbers using magic (Sieve of Eratosthenes)
	for(int m = 2; m*m <= n; m++)
	{
		// If m is in the vector the following is executed
		if(find(v, m) == true)
		{ 
			i = 2*m;
			
			// Finds instance of i and removes them from the vector
			while(i <= n)
			{
				vector<int> :: iterator it = v.begin();
				vector<int> :: iterator itend = v.end();
				
				while(it != itend)
				{
					if(*it == i)
					{
						v.erase(it); 
						itend = v.end();
					}
					else
					{
						it++;
					}
				}
				i += m;
			}	
		}
	}
	
}

int main()
{
	// Creates a vector and iterator for vector
	// Asks user for number
	// Creates vector including all integers up to that number
	
	vector<int> primeVec;
	
	vector<int>:: iterator iter;
	
	int primeLimit, count = 0;
	
	cout << "Enter upper limit for vector of primes: ";
	
	cin >> primeLimit;
	
	// Uses sieve algorithm to remove all non-primes in vector
	sieveVector(primeVec, primeLimit);
	
	iter = primeVec.begin();
	
	// Uses iterator to traverse the vector and outputs 10 elements from the vector per line
	while(iter != primeVec.end())
	{
		count++;
		
		cout << setw(5) << *iter;
		
		if(count % 10 == 0)
		{
			cout << endl;
		}
		
		iter++;
	}
	cout << endl;
	return 0;
}