// Will Fritz
// 10/4/2016
// A program that will store and manage many of your favorite sayings

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <fstream>

using namespace std;

void allsayings(list<string > );
void newsaying(list<string >& );
void givenword(list<string > );
void save(list<string > );
void sort(list<string >& );
void erase(list<string >& );

int main() {
	// streams in file and check if it can be opened
	string filename;
	cout << "\nEnter the name of a startup file: " << endl;
	cin >> filename;
	ifstream ifs(filename);
	if (!ifs){
		cout << "\nError opening file " << filename << endl;
		return 1;
	}
	// creates a list storing all the strings from file
	list<string > sayings;
	string str;
	getline(ifs, str);
	while (!ifs.eof()){
		sayings.push_back(str);
		getline(ifs, str);
	}
	// displays options for user and calls respective functions
	sort(sayings); //sorts the sayings 
	bool hold = true;	
	while (hold){
		cout << "\nTasks you can perform:";
		cout << "\n 1: Show all sayings.";
		cout << "\n 2: Enter a new saying.";
		cout << "\n 3: List sayings that contain a given word.";
		cout << "\n 4: Save all saying in a new text file.";
		cout << "\n 5: Delete a saying.";
		cout << "\n 6: Quit.";
		
		int choice;
		cout << "\nYou're choice? ";
		cin >> choice;
		switch(choice){
			case 1:
				allsayings(sayings);
				break;
			case 2:
				newsaying(sayings);
				sort(sayings);
				break;
			case 3:
				givenword(sayings);
				break;
			case 4:
				save(sayings);
				break;
			case 5:
				allsayings(sayings);
				erase(sayings);
				break;		
			case 6:
				cout << "\nGoodbye!" << endl;
				hold = false;
				break;
			default:
				cout << "\nYou must enter one of the";
				cout << " above choices!" << endl;
		}
	}
}

// Displays a list of every saying cureently in the list
void allsayings(list<string > sayings){
	cout << "\nHere is the list of sayings:\n\n";
	int num = 1;
	for (auto it = sayings.begin(); it != sayings.end(); it++)
		cout << setw(2) << num++ << ". " << *it << endl;
}

// Adds a new saying to the end of the list		
void newsaying(list<string > &sayings){
	string str;
	cout << "\nEnter a new saying to add to the list: ";
	cin.ignore();
	getline(cin,str);
	sayings.push_back(str);
}		
	
// Finds the sayings that contain a given word
void givenword(list<string > sayings){
	string word;
	cout << "\nEnter the word: ";
	cin.ignore();
	getline(cin,word);
	cout << "\nThe sayings that contain " << word << " are:\n\n";
	for (auto it = sayings.begin(); it != sayings.end(); it++){
		if((*it).find(word) != string::npos) //checks if string
			cout << *it << endl;	     //contains word
	}
}

// Saves the list of strings into a new file
void save(list<string > sayings){
	string filename;
	cout << "\nWhat would you like to name the file? ";
	cin >> filename;
	ofstream ofs(filename);
	// copies the contents of list to file
}

// sort function 
void sort(list<string > &sayings){
	bool swap = true;
	while(swap == true){
		swap = false;
		list<string>::iterator iback = sayings.begin();
		list<string>::iterator i = sayings.begin();
		i++; 
		while(i != sayings.end()){
			if ((*iback).compare((*i)) > 0){
				string hold = (*i);
				(*i) = (*iback);
				(*iback) = hold;
				swap = true;
			}	
			iback++;
			i++;
		}
	}
}

// option to delete saying
void erase(list<string> &sayings){
	int user;
	cout << "\nEnter the number corresponding to the saying";
	cout << " you want to delete ";
	cin >> user;
	user -= 1;
	for (auto i = sayings.begin(); i != sayings.end(); i++) {
		// distance between iterators
		int diff = distance(sayings.begin(), i);
		if (user == diff) {
			sayings.erase(i);
			break;
		}
	}
}
		







	
