// Will Fritz 
// 10/25/2016
// implementation for Rational class

#include "rational.h"
#include <iostream>
using namespace std;

Rational::Rational(){
	numer = 1;
	denom = 1;
}

Rational::Rational(int a, int b){
	// Sets the numerator and denominator for an element of rational 
	numer = a;
	denom = b;
} 

Rational::~Rational(){
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


Rational Rational::add(Rational x){
	Rational z;
	// z is rational and because we are inside something that defines 	     the rational which allows us to access the private info of z
	z.numer = (numer * x.denom) + (denom * x.numer);
	z.denom = denom * x.denom;
	return z;
}

Rational Rational::subtract(Rational x){
	Rational z;
	z.numer = (numer * x.denom) - (denom * x.numer);
	z.denom = denom * x.denom;
	return z;
}

Rational Rational::multiply(Rational x){
	Rational z;
	z.numer = numer * x.numer;
	z.denom = denom * x.denom;
	return z;
}

Rational Rational::divide(Rational x){
	Rational z;
	z.numer = numer * x.denom;
	z.denom = denom * x.numer;
	return z;
}


