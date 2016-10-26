// Will Fritz
// 9/13/2016
// gives polar coordinates given x and y. Also, includes special cases like
// on an axis or on the origin

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double radius (double x, double y);
double angle (double x, double y);
string quad (double x, double y);

int main () {
	double x;
	double y;
	cout << "Please enter x and y coordinates respectively: ";
	cin >> x >> y;

	cout << "\nThe polar coordinates are: \n(radius, angle) = (";
	cout << setprecision(2) << fixed << radius(x,y) << ",";
	cout << setprecision(2) << fixed << angle(x,y) << ")";
	
	cout << "\nThe coordinates are " << quad(x,y) << endl;
	cout << "\nNote: the angle is in radians and is between ";
	cout << "-pi and pi" << endl;
}

double radius (double x, double y){
	double root = sqrt(pow(x,2) + pow(y,2));
	return root;
}

double angle (double x, double y){
	double ang = atan2(y,x);
	return ang;
}

string quad (double x, double y){
	string temp;
	if (x > 0 && y > 0){
		temp = "in quadrant 1";
		return temp;
	}
	if (x > 0 && y < 0){
		temp = "in quadrant 4";
		return temp;
	}
	if (x < 0 && y > 0){
		temp = "in quadrant 2";
		return temp;
	}
	if (x < 0 && y < 0){
		temp = "in quadrant 3";
		return temp;
	}
	if (x == 0 && y != 0){
		temp = "on the y-axis";
		return temp;
	}
	if (y == 0 && x != 0){
		temp = "on the x-axis";
		return temp;
	}
	if (x == 0 && y == 0){
		temp = "on the origin";
		return temp;
	}
	return 0;
}

