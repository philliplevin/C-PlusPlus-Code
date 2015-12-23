//Phillip Levin

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Interface for Person base class
class Person
{
	public:
	Person();
	Person(string n, string a, int t, string e);
	string getname();
	string getaddress();
	int gettelephone();
	string getemail();
	virtual string whatami();
	
	private:
	string name; 
	string address;
	double telephone;
	string email;
};

//Member functions for Person
Person::Person(string n, string a, int t, string e)
{
	name = n;
	address = a;
	telephone = t;
	email = e;
}

string Person::getname()
{
	return name;
}

string Person::getaddress()
{
	return address;
}

int Person::gettelephone()
{
	return telephone;
}

string Person::getemail()
{
	return email;
}

string Person::whatami()
{
	return "Person";	
}

//Interface for derived Student class
class Student: public Person
{
	public:
	Student();
	Student(string n, string a, int t, string e, string s);
	string getstatus();
	string whatami();
	
	private:
	string classstatus; // freshman, sophomore, junior, or senior
};

//Member functions for Student
Student::Student(string n, string a, int t, string e, string s): Person(n, a, t, e)
{
	classstatus = s; 
}

string Student::getstatus()
{
	return classstatus;
}

string Student::whatami()
{
	return "Student";
}
//Interface for derived Employee class
class Employee: public Person
{
	public:
	Employee();
	Employee(string n, string a, int t, string e, string o, double s, int d);
	string getoffice();
	double getsalary();
	int getdatehired();
	string whatami();
	
	private:
	string office;
	double salary;
	double datehired;
};

// Member functions for Employee
Employee::Employee(string n, string a, int t, string e, string o, double s, int d): Person(n, a, t, e)
{
	office = o;
	salary = s;
	datehired = d;
}
string Employee::getoffice()
{
	return office;
}

double Employee::getsalary()
{
	return salary;
}

int Employee::getdatehired()
{
	return datehired;
}

string Employee::whatami()
{

	return "Employee";
}

// Interface for derived class Faculty 
class Faculty: public Employee
{
	public:
	Faculty();
	Faculty(string n, string a, int t, string e, string o, double s, int d, string r, string st);
	string getrank();
	string getstatus();
	string whatami();
	
	private:
	string rank; // professor, associate, assistant, or lecturer
	string status; // tenured, tenure-track, visiting, or non-tenure-track
};

// Member functions for Faculty
Faculty::Faculty(string n, string a, int t, string e, string o, double s, int d, string r, string st): Employee(n, a, t, e, o, s, d)
{
	rank = r; 
	status = st;
}

string Faculty::getrank()
{
	return rank;
}

string Faculty::getstatus()
{
	return status;
}

string Faculty::whatami()
{
	return "Faculty";
}

// Interface for derived class Staff
class Staff: public Employee
{
	public:
	Staff();
	Staff(string n, string a, int t, string e, string o, double s, int d, string p);
	string getposition();
	string whatami();
	
	private:
	string position;
};	

//Member functions for Staff
Staff::Staff(string n, string a, int t, string e, string o, double s, int d, string p):Employee(n, a, t, e, o, s, d)
{
	position = p;
}

string Staff::getposition()
{
	return position;
}

string Staff::whatami()
{
	return "Staff";
}

// Main program begins here
int main ()
{	
	
	vector<Person*> people;
	
	people.push_back(new Person("Jeff Goldblum", "Somewhere in Jurassic Park", 5111993, "mancreatesdinosaurschaos.com"));
	people.push_back(new Student("Phillip", "My Home Address", 2718281, "philliplevin@gmail.com", "Junior"));
	people.push_back(new Employee("Michael Scott", "1234 Dunder Mifflin Ave", 911,  "michaelscott@dundermifflin.com", "A1", 15080, 03242005));
	people.push_back(new Faculty("Richard P. Feynman", "1200 East California Boulevard, Pasadena, CA 91125", 299792458, "feynman@surelyyourjoking.com", "P314", 200000, 5111918, "Professor", "Tenured"));
	people.push_back(new Staff("Donald Trump", "725 Fifth Avenue, East 56th Street in Midtown Manhattan, New York City", 2128322000, "dtrump@trump.com", "A1", 60000000, 5141946, "Receptionist"));
	
	cout << endl;
	for (int i = 0; i < people.size(); i++)
	{
		cout << (*people[i]).getname() << " is a " << (*people[i]).whatami() << endl;
	}
	cout << endl;
	
}
