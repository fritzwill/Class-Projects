// Will Fritz
// 10/30/2016
// implementation for state class (state.cpp)



#include <iostream>
#include "state.h"

using namespace std;

State::State(){
}
State::State(string a, string b, string c, int d, int e, int f){
	abr = a;
	name = b;
	capital = c;
	pop = d;
	year = e;
	rep = f;
}

State::~State(){
}

string State::getAbr(){
	return abr;
}

string State::getName(){
	return name;
}

string State::getCapital(){
	return capital;
}

int State::getPop(){
	return pop;
}

int State::getYear(){
	return year;
}

int State::getRep(){
	return rep;
}

void State::print(){
	cout << "Abbreviation: " << abr << endl;
	cout << "Name: " << name << endl;
	cout << "Capital: " << capital << endl;
	cout << "Population: " << pop << endl;
	cout << "Year it became a state: " << year << endl;
	cout << "NUmber of representatives in Congress " << rep << endl;
}


