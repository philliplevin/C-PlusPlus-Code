#include<iostream>
#include<iomanip>
#include<set>
#include<vector>

using namespace std;

void sieveVector(vector<int> &v, int n)
{
	int m, i;
	
	for(int i = 0; i < v.size(); i++)
	{
		v.pop_back();
	}
	
	for(int m = 2; m < n; m++)
	{
		v.push_back(m);
		
	}
	
	for(int m = 2; m*m <= n; m++)
	{
		i = 2*m;
		
		while(i <= n)
			s.erase(i); // delete this
		{
			for(int k = 0; k < v.size(); k++)
			{
				if(v[k] == i)
				{
					vector<int> :: iterator it = v[k];
					v.erase(it);
				}
			}
			i += m;
			
		}
	}
	
}

int main()
{
	/*set<int> primeSet;
	
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
	*/
}