// Will Fritz
// 10/4/2016
// A program that will store and manage many of your favorite sayings

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void allsayings(vector<string > );
void newsaying(vector<string >& );
void givenword(vector<string > );
void save(vector<string > );

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
	// creates a vector storing all the strings from file
	vector<string > sayings;
	string str;
	getline(ifs, str);
	while (!ifs.eof()){
		sayings.push_back(str);
		getline(ifs, str);
	}
	// displays options for user and calls respective functions
	bool hold = true;	
	while (hold){
		cout << "\nTasks you can perform:";
		cout << "\n 1: Show all sayings.";
		cout << "\n 2: Enter a new saying.";
		cout << "\n 3: List sayings that contain a given word.";
		cout << "\n 4: Save all saying in a new text file.";
		cout << "\n 5: Quit.";
		
		int choice;
		cout << "\nYou're choice? ";
		cin >> choice;
		switch(choice){
			case 1:
				allsayings(sayings);
				break;
			case 2:
				newsaying(sayings);
				break;
			case 3:
				givenword(sayings);
				break;
			case 4:
				save(sayings);
				break;
			case 5:
				cout << "\nGoodbye!" << endl;
				hold = false;
				break;
			default:
				cout << "\nYou must enter one of the";
				cout << " above choices!" << endl;
		}
	}
}

// Displays a list of every saying cureently in the vector
void allsayings(vector<string > sayings){
	cout << "\nHere is the list of sayings:\n\n";
	for (auto it = sayings.begin(); it != sayings.end(); it++)
		cout << *it << endl;
}

// Adds a new saying to the end of the vector		
void newsaying(vector<string > &sayings){
	string str;
	cout << "\nEnter a new saying to add to the list: ";
	cin.ignore();
	getline(cin,str);
	sayings.push_back(str);
}		
	
// Finds the sayings that contain a given word
void givenword(vector<string > sayings){
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

// Saves the vector of strings into a new file
void save(vector<string > sayings){
	string filename;
	cout << "\nWhat would you like to name the file? ";
	cin >> filename;
	ofstream ofs(filename);
	// copies the contents of vector to file
	for (auto it = sayings.begin(); it != sayings.end(); it++)
		ofs << *it << endl;
}
	
