#include <iostream>
#include <string>

using namespace std;

int prec(char x)
{
	if (x == '*' || x == '/')
	{	
		return 1;
	}
	else if (x == '+' || x == '-')
	{
		return 0;
	}
	
}

int main()
{
	cout << prec('+') << endl;
	
}