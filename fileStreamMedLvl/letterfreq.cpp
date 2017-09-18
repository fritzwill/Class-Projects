// Will Fritz
// 10/14/2016
// Counts the frequency of each letter of the alphabet as they occur in text
// contained in a text file. Outputs frewuency table along with other stat

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <string>
#include <cctype>
#include <iterator>

using namespace std;

void display(int [], double, double);

int main(){
	int counter[128]; //will be used to count amount of letter recorded
	for (int i = 0; i < 128; i++)
		counter[i] = 0;
	string filename;
	ifstream ifs;
	cout << "\nEnter the name of the file you want to read: ";
	cin >> filename;
	ifs.open(filename);

	// checks for error reading file
	if(!ifs){
		cout << "\nerror opening " << filename;
		return 1;
	}
	
	char letter;	
	letter = ifs.get();
	double spaces = 0; //freq of spaces in file
	double totalchar = 0; //total number of characters in file
	while(!ifs.eof()){
		letter = toupper(letter); //makes everything uppercase
		counter[letter]++; //increases freq of letter in array
		if(isspace(letter))
			spaces++;
		totalchar++;
		letter = ifs.get();
	}
	display(counter, spaces, totalchar);
}

// displays frequencey of each letter as well as other stats
void display(int counter[], double spaces, double totalchar){
	int count = 0;
	for(char c = 'A'; c <= 'Z'; c++){
		count++;
		cout << c << ": " << setw(12) << counter[c] << " |";
		if (count == 4){
			cout << endl;
			count = 0;
		}
	}
	
	float lettersonly = totalchar - spaces;
	float percentspace = (spaces/totalchar)*100;

	cout << "\nThere are a total of " << lettersonly << " letters";
	cout << "\nThere are a total of " << totalchar << " characters";
	cout << "\nThere are a total of " << spaces << " whitespaces";
	cout << "\nThe 'space percentage' is: ";
	cout << setprecision(2) << percentspace << "%" << endl;
} 
				
	
		

