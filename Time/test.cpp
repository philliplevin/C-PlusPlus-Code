#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

	cout << "Enter a time in the format of HH:MM AM(OR PM)" << endl;
	string input, hour, minute, unit;

	 getline(cin, hour, ':');
	cin >> minute;
	cin >> unit;
	cout << hour << endl;
	cout << minute << endl;
	cout << unit << endl;
	
	
	//int h, m;
	
	//stringstream(hour) >> h;
	//stringstream(minute) >> m;

// copy above

	//cout << h + m << endl;
	
}