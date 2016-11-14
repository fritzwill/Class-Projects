// Will Fritz
// 10/27/2016
// driver to test the Rational class

#include <iostream>
#include "rational.h"
using namespace std;

int main(){
	Rational a(5,6), b(3,7), c, s;

 	cout << "*** display a and b ***\n";
 	a.print();
  	b.print();
  	cout << "*** display c ***\n";
  	c.print();  // recall that c was instantiated with the default constr			 uctor

  	// 'mathematically' add a and b
  	cout << "*** compute s as the math sum of a and b, and display s";
	cout << " ***\n";
  	s = a.add(b);
  	s.print();
  
  	// tests getNumer() getDenom() 
  	cout << "*** gets numer and denom value of a and b and displays";
	cout << " ***\n";
	cout << "numer of a: " << a.getNumer() << endl;
	cout << "denom of a: " << a.getDenom() << endl;
	
	// tests setNumer() setDenom()
	cout << "*** sets a new numer(9) and denom(13) for a and displays";
	cout << " it ***\n";
	a.setNumer(9);
	a.setDenom(13);
	a.print();
	
	// find the product of new variables d and e. 
	Rational d(8,9), e(11,13);
	cout << "*** display d,e and p, the product of the d and e ***\n";
	cout << "d: ";
	d.print();
	cout << "e: "; 
	e.print();
	
	Rational p;
	p = d.multiply(e);
	cout << "product: \n";
	p.print(); 
  	
	// find y, the quotient of d/e
	cout << "*** display y, quotient of d/e ***\n";
	Rational y;
	y = d.divide(e);
	cout << "quotient: \n";
	y.print();

	// subtraction of d and e
	cout << "*** display q, which is d - e ***\n";
	Rational q;
	q = d.subtract(e);
	q.print();
	
	// divide
	return 0;
}

