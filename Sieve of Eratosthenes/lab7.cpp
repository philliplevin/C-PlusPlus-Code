#include<iostream>
#include<iomanip>
#include<set>

using namespace std;

void sieve(set<int> &s, int n)
{
	int m, i;
	
	s.erase(s.begin(), s.end());
	
	for(int m = 2; m < n; m++)
	{
		s.insert(m);
		
	}
	
	for(int m = 2; m*m <= n; m++)
	{
		i = 2*m;
		
		while(i <= n)
		{
			s.erase(i);
			i += m;
			
		}
	}
	
}

int main()
{
	set<int> primeSet;
	
	set<int>:: iterator iter;
	
	int primeLimit, count = 0;
	
	cout << "Enter upper limit for set of primes: ";
	
	cin >> primeLimit;
	
	sieve(primeSet, primeLimit);
	
	iter = primeSet.begin();
	
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