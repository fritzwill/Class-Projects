// Will Fritz 
// 10/25/2016
// implementation for Rational class

#include "rational.h"
#include <iostream>
#include <cmath>
using namespace std;

Rational::Rational(){
	setRational(1,1);
}

Rational::Rational(int a, int b){
	// Sets the numerator and denominator for an element of rational 
	setRational(a, b);
} 

Rational::~Rational(){
}

void Rational::setRational(int a, int b){
	setNumer(a);
	setDenom(b);
}

int Rational::getNumer(){
	return numer;
}

int Rational::getDenom(){
	return denom;
}

void Rational::setNumer(int a){
	numer = a;
}

void Rational::setDenom(int a){
	denom = a;
}

void Rational::print(){
	cout << numer << "/" << denom << endl;
}


// overloading +
Rational Rational::operator+(Rational x){
	Rational z;
	// z is rational and because we are inside something that defines 	     the rational which allows us to access the private info of z
	z.numer = (numer * x.denom) + (denom * x.numer);
	z.denom = denom * x.denom;
	return z;
}

// overloading -
Rational Rational::operator-(Rational x){
	Rational z;
	z.numer = (numer * x.denom) - (denom * x.numer);
	z.denom = denom * x.denom;
	return z;
}

// overloading *
Rational Rational::operator*(Rational x){
	Rational z;
	z.numer = numer * x.numer;
	z.denom = denom * x.denom;
	return z;
}

// overlaoding /
Rational Rational::operator/(Rational x){
	Rational z;
	z.numer = numer * x.denom;
	z.denom = denom * x.numer;
	return z;
}

// overloading output operator
ostream& operator<< (ostream &f, Rational &r){
	f << r.numer << " / " << r.denom;
	return f;
}

// overloading input operator
istream& operator>> (istream &f, Rational &r){
	int a,b;
	
	cout << "Enter the denominator and numerator: ";
	f >> a >> b;
	r.setRational(a,b);

	return f;
} 
		








