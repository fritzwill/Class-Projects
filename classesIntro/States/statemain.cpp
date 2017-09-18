//Will Fritz
//10/30/2016
//utili

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "state.h"

using namespace std;

// prototypes
void findStateAbr(vector<State >);
void displayAll(vector<State >);
void yearBefore(vector<State >);
void popOver(vector<State >);
void repOver(vector<State >);

int main(){
	// streams in file and checks if it can be opened
	string filename;
	cout << "\nEnter file name: \n";
	cin >> filename;
	ifstream ifs(filename); 
	if (!ifs){
		cout << "\nError opening file\n";
		return 1;
	}

	// creates a vector storing all the strings of file as state class
	vector<State > stateList;
	string abr, name, capital, pop, year, rep;
	int popi, yeari, repi;
	State temp;
	char c = ifs.peek();
	while (c != EOF){
		getline(ifs, abr, ',');
		getline(ifs, name, ',');
		getline(ifs, capital, ',');
		getline(ifs, pop, ',');
		getline(ifs, year, ',');
		getline(ifs, rep);
		popi = stoi(pop);
		yeari = stoi(year);
		repi = stoi(rep);
		// will be used to store into vector
		temp = State(abr, name, capital, popi, yeari, repi);
		stateList.push_back(temp);
		c = ifs.peek();
	}

	// displays options for users
	bool userHold = true;
	while (userHold){
		cout << "\nSelect one of the following options:";
		cout << "\n1: See the info of a state by giving its"; 
		cout << " abbreviation\n";
		cout << "2: Display info of all states\n";
		cout << "3: Show all the states created before a certain ";
		cout << "year\n";
		cout << "4: Show all the states that have a population ";
		cout << "greater than a certain number\n"; 
		cout << "5: Show all the states that have more than a "; 
		cout << "certain amount of representatives in Congress\n";
		cout << "6: Quit\n";
		cout << "\nYour choice: ";
		int userChoice;
		cin >> userChoice;
		switch(userChoice){
			case 1:
				findStateAbr(stateList);
			case 2:
				displayAll(stateList);
			case 3:
				yearBefore(stateList);
			case 4:
				popOver(stateList);
			case 5:
				repOver(stateList);
			case 6:
				userHold = false;
			default:
				cout << "\nYou must enter a number between ";				     cout << "1 and 6";
		}
	}
}

void findStateAbr(vector<State > stateList){
	string abr;
	cout << "\nEnter the abbreviation of the state you wish to find";
	cin >> abr;
	bool found = false;
	for (auto it = stateList.begin(); it != stateList.end(); it++){
		if ((*it).getAbr() == abr){
			(*it).print();
			found = true;
		}
	}
	if (!found) 
		cout << "\nNo state with that abbreviation could be found";
}

void displayAll(vector<State > stateList){
	for (auto it = stateList.begin(); it != stateList.end(); it++){
		(*it).print();
	}
}

void yearBefore(vector<State > stateList){
	int year;
	cout << "\nSelect a year: ";
	cin >> year;
	for (auto it = stateList.begin(); it != stateList.end(); it++){
		if ((*it).getYear() < year)
			(*it).print();
	}
}
	
	
void popOver(vector<State > stateList){
	int pop;
	cout << "\nEnter the population you would like to check for: ";
	cin >> pop;
	cout << "\nThese states have a population over that amount: \n";
	for (auto it = stateList.begin(); it != stateList.end(); it++){
		if ((*it).getPop() > pop)	
			(*it).print();
	}
}	
 
void repOver(vector<State > stateList){
	int rep;
	cout << "\nEnter the amount of representatives you would like to ";
	cout << "check for: ";
	cin >> rep;
	cout << "\nThese states have more than the given amount of ";
	cout << "representatives";
	for (auto it = stateList.begin(); it != stateList.end(); it++){
		if ((*it).getRep() > rep)
			(*it).print();
	}
}	


