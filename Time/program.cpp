// Phillip Levin, Rachel Soper


#include "d_time24.h"
#include "d_time12.h"

using namespace std;

int main()
{		
	// A time12 object is created and tested below
	
	time12 t(8,15,AM);
	cout << "New Time12 object has been created" << endl;
	cout << "The time is: ";
	t.writeTime();
	cout << endl;
	t.readTime(); //Input 12:00 PM
	cout << "The user has changed the time. The time is: ";
	t.writeTime();
	cout << endl;
	t.addTime(180); // add 3 hours to t
	cout << "180 minutes have been added. The time is: ";
	t.writeTime();
	time12 t1(8,15,PM);
	cout << endl << "New Time12 object has been created" << endl;
	cout << "The time is: ";
	t1.writeTime();
	cout << endl;
	t1.readTime(); //Input 12:00 PM
	cout << "The user has changed the time. The time is: ";
	t1.writeTime();
	t1.addTime(180);
	cout << endl << "180 minutes have been added. The time is: ";
	t1.writeTime(); 
	cout << endl;
	
	// Some additional tests of time12 class functionality 
	
	time12 t12(3, 18, AM);
    cout << "New Time12 object has been created" << endl;
	cout << "The time is: ";
	t12.writeTime(); // verifies that correct 12-hour clock was constructed
	t12.addTime(720); 
	cout << endl << "720 minutes have been added. The time is: ";
	t12.writeTime(); // verifies that hour/minute are correct and that time of day is PM
	t12.addTime(720);
	cout << endl << "720 minute have been added. The time is: ";
	t12.writeTime(); // verifies that hour/minute are correct and that time of day is AM
	t12.addTime(450);
	cout << endl << "450 minutes have been added. The time is: ";
	t12.writeTime(); // verifies that hour/minute are correct and that time of day is AM
	cout << endl;
	t12.readTime(); // verifies that user can input new time 
	cout << "The user has changed the time. The time is: ";
 	t12.writeTime(); // verifies that user-input was translated into correct time12 object
	cout << endl;
}
