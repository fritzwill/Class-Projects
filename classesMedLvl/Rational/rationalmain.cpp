// Will Fritz
// 10/27/2016
// driver to test the Rational class

#include <iostream>
#include "rational.h"
using namespace std;

int main(){
	Rational a(5,6), b(3,7), c, s;
	
	cout << "\nGetting values for c: \n";
	cin >> c; // using overloaded input operator
 	// using overloaded output operator
	cout << " a is: " << a << endl;
	cout << " b is: " << b << endl;
	cout << " c is: " << c << endl;

  	// 'mathematically' add/subtract/multiply/divide a and b
  	Rational add, subtract, multiply, divide;
	add = a + b;
	subtract = a-b;
	multiply = a * b;
	divide = a / b;
  
	// using overloaded output operator
	cout << "\na + b = " << add << endl;
	cout << "a - b = " << subtract << endl;
	cout << "a * b = " << multiply << endl;
	cout << "a / b = " << divide << endl;

  	// tests getNumer() getDenom() 
  	cout << "\n*** gets numer and denom value of a and b and displays";
	cout << " ***\n";
	cout << "numer of a: " << a.getNumer() << endl;
	cout << "denom of a: " << a.getDenom() << endl;
	
	// tests setNumer() setDenom()
	cout << "\n*** sets a new numer(9) and denom(13) for a and displays";
	cout << " it ***\n";
	a.setNumer(9);
	a.setDenom(13);
	a.print(); // using pringt this time

	return 0;
}

