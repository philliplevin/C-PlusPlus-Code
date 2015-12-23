// Phillip Levin, Rachel Soper 
// Sieve of Eratosthenes

#include<iostream>
#include<iomanip>
#include<set>

using namespace std;

// Removes all non-prime numbers from a set
void sieve(set<int> &s, int n)
{
	int m, i;
	
	// Removes all elements in set
	s.erase(s.begin(), s.end());
	
	// Inputs integers into set, goes up to n
	for(int m = 2; m < n; m++)
	{
		s.insert(m);
		
	}
	
	// Finds the prime numbers using magic (Sieve of Eratosthenes)
	for(int m = 2; m*m <= n; m++)
	{
		if(s.find(m) != s.end())
		{
			i = 2*m;
		
			while(i <= n)
			{
				s.erase(i);
				i += m;
			}
		}
	}
}

int main()
{
	// Creates a set and iterator for set
	// Asks user for number
	// Creates set including all integers up to that number
	
	set<int> primeSet;
	
	set<int>:: iterator iter;
	
	int primeLimit, count = 0;
	
	cout << "Enter upper limit for set of primes: ";
	
	cin >> primeLimit;
	
	// Uses sieve algorithm to remove all non-primes in set 
	sieve(primeSet, primeLimit);
	
	iter = primeSet.begin();
	
	// Uses iterator to traverse the set and outputs 10 elements from the set per line
	while(iter != primeSet.end())
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