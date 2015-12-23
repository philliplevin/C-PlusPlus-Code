// Phillip Levin

#include "ccc_win.h"
#include <string>
#include <sstream>

using namespace std;

class Parachutist
{
	public:
	Parachutist(); // default constructor
	Parachutist(Point loc); // creates an instance of a parachutist
	void display(bool x);	// displays chutist, with or without the chute
	void move(double dx, double dy); // updates location of parachutist 
	Point position(); // returns coordinates of parachutist
	
	private:
	Circle chutist;
	Line line1;
	Line line2;
	Line line3;
};

Parachutist::Parachutist()
{
	chutist = Circle(Point(0,0), 20);
} 

// Creates a chutist, including its parachute
Parachutist::Parachutist(Point location)
{
	chutist = Circle(location, 40);
	Point a = Point(location.get_x() - 70, location.get_y() + 40);
	Point b = Point(location.get_x() + 70, location.get_y() + 40);
	Point c = Point(location.get_x(), location.get_y() + 80); 	
	line1 = Line(a, b);
	line2 = Line(a, c);
	line3 = Line(b, c);
}

// Displays the chutist. When true chute is open, when false it is closed
void Parachutist::display(bool x)
{
	if(x) // chute is open
	{
		cwin << line1 << line2 << line3 << chutist;
	}
	else // chute is closed
	{
		cwin << chutist;
	}
}

// Updates the location of the chutist as well as the chute
void Parachutist::move(double dx, double dy)
{
	chutist.move(dx, dy);
	line1.move(dx, dy);
	line2.move(dx, dy);
	line3.move(dx, dy);
}

Point Parachutist::position()
{
	Point position = chutist.get_center();
	return position;
	
}

int ccc_win_main()
{	
	double velocityX = cwin.get_double("Enter the plane's velocity (suggested is 250): ");
	cwin.clear();
	double jumppoint = cwin.get_double("Enter jump altitude (suggested is 3000): ");
	cwin.clear();
	int secondstoopen = cwin.get_int("Enter seconds to open chute (suggested is 7): ");
	cwin.clear();
	
	cwin.coord(-40, jumppoint + 70, jumppoint + 370, -340);
	
	Parachutist chutist = Parachutist(Point(0, jumppoint));
	
	double altitude = jumppoint;
	int secondspassed = 0;
	double velocityY = 0;
	double acceleration = 32;
	double terminalvelocity = 174;
	double deceleration = 100;
	double dragfactor = 30;
	
	chutist.display(false);
	
	while (altitude > 0)
	{	

		if (secondspassed < secondstoopen) // calculations for closed parachute
		{
			velocityY = velocityY + acceleration;
			if(velocityY > 174)
			{
				velocityY = 174;
			}
			altitude = altitude - velocityY;
			chutist.move(velocityX, -velocityY);
		}
		else // calculations for open parachute
		{
			if (velocityY - deceleration <= 17)
			{
				velocityY = 17;
			}
			else
			{
				velocityY = velocityY - deceleration;
			}
			
			if(velocityX - dragfactor <= 0)
			{
				velocityX = 0;
			}
			else
			{
				velocityX = velocityX - dragfactor;
			}
			
			if(altitude - velocityY >= 0)
			{
				altitude = altitude - velocityY;
				chutist.move(velocityX, -velocityY);
			}
			else
			{
				chutist.move(velocityX, -altitude);
				altitude = 0;
			}
			
		}
		
		++secondspassed;
		
		if(secondspassed < secondstoopen && secondspassed % 2 == 0) // parachute is closed
		{
			chutist.display(false);
		}
		else if (secondspassed % 2 == 0) // parachute is open
		{
			chutist.display(true);
		}
		
	}

	// Displays landing area
	cwin << Line(Point(-40, -40), Point(jumppoint + 370, -40));
	
	// Converts velocity values into strings
	string velocityofX;
	ostringstream convertx;
	convertx << velocityX;
	velocityofX = convertx.str();
	
	string velocityofY;
	ostringstream converty;
	converty << velocityY;
	velocityofY = converty.str();
        
        // Displays landing velocities   
	Message landed(Point(0, -50), "Landing velocity:");
	Message x(Point(0, -150), velocityofX + " f/s x direction");
	Message y(Point(0, -250), velocityofY + " f/s y direction");
	cwin << landed << x << y;
}
