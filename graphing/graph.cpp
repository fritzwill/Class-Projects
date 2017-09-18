#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main () {
	cout << "A plot of y = 10*(1+cos(x)) from x = 0 to 20.0" << endl;
	cout << setw(8) << "X" << setw(8) << "Y" << endl;
	float xmin = 0;
	float xmax = 0;
	
	float ymin = 50;
	float ymax = 0;
	
	for (float x = 0; x < 20.2; x += 0.2) {
		float y = 0;
		y = 10*(1+cos(x));
		cout << setw(8) << setprecision(2) << fixed << x;
		cout << setw(8) << setprecision(2) << fixed << y;
		cout << "    ";
		if (y < ymin) {
			ymin = y;
			xmin = x;
		}
		if (y > ymax){
			ymax = y;
			xmax = x;
		}
		for (int j = 0; j <= y; j++) {
			cout << "#";
		}
		cout << endl;
	}
	cout << "\nThe maximum of " << setprecision(2) << fixed << ymax;
	cout << " was at x=" << setprecision(2) << fixed << xmax << endl;
	
	cout <<"The minimum of " << setprecision(2) << fixed << ymin;
	cout << " was at x=" << setprecision(2) << fixed << xmin << endl;
}

