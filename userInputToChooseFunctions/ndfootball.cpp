// Will Fritz
// 9/22/2016
// Store wins and losses into arrays and display menu that allows users
// to aquire certain statistics: 

#include <iostream>
#include <iomanip>
#include "nd_data.h"

using namespace std;

void record(int);
void winsF(int);
void lossesF(int);
void mostwins();
void mostlosses();

int main (){
	int val = 1; //initial value to keep the loop going
	while(val != -1){
		int choice;
		cout << "\n1: Display the record for a given year";
		cout << "\n2: Display the years with at least 'n' wins";
		cout << "\n3: Display the years with at least 'n' losses";
		cout << "\n4: Display the years with the most wins";
		cout << "\n5: Display the years with the most losses";
		cout << "\n6: Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				int year;
				cout << "\nEnter the year: ";
				cin >> year;
				record(year);
				break;
		   	case 2:
		   		int win;
				cout << "\nEnter the min amount of wins: ";
				cin >> win;
				winsF(win);
				break;
		   	case 3:
				int loss;
				cout << "\nEnter the min amount of losess: ";
				cin >> loss;
				lossesF(loss);
				break;
		   	case 4:
				mostwins();
				break;
		   	case 5:
				mostlosses();
				break;
		   	case 6:
		   		val = -1;
		   		break;
		   	default:
				cout << "\nYou must enter a number between";
				cout << " 1 and 6" << endl;
		}
	}
	return 0;
}
				

// displays the record of a certain year given the year
void record(int a){
	int size = sizeof(wins) / sizeof(int);
	if (a < 1900 || a > (1900 + size)){
		cout << "Enter a year after 1900 or before ";
		cout << (1900 + size);
	}
	else{
		int b = a - 1900; //gives element of array given year
		int win = wins[b];
		int loss = losses[b];
		cout << "\nThe record for the " << a << " season is: ";
		cout << win << "-" << loss << endl;
	}
}

// displays the years that have the given amount of years
void winsF(int a){
	int size = sizeof(wins) / sizeof(int);
	int count = 0; // used to keep track of number of years with a wins
	for (int i = 0; i < size; i++){
		if (wins[i] >= a)
			count++;
	}
	
	int years[count];
	int count2 = 0; //will be used to fill array years[]	
	for (int j = 0; j < size; j++){
		if (wins[j] >= a){
			years[count2] = j + 1900; //enters actual years
			count2++;
		}
	}
	
	// displays years with a wins
	cout << "Notre Dame had at least " << a << " win(s) in the "; 
	cout << "year(s): ";
	cout << endl;
	int count3 = 0; // to limit amount of years displayed per line
	for (int k = 0; k < count2; k++){
		if (count3 == 10){
			cout << endl;
			count3 = 0;
		}
		else{
			cout << years[k] << " ";
			count3++;
		}
	}
	
	cout << endl;
}

// displays the years that have the given amount of losses
void lossesF(int a){
	int size = sizeof(wins) / sizeof(int);
	int count = 0; //used to keep track of number of years with a losses
	for (int i = 0; i < size; i++){
		if (losses[i] >= a)
			count++;
	}
	
	int years[count];
	int count2 = 0; //will be used to fill array years[]
	for  (int j = 0; j < size; j++){
		if (losses[j] >= a){
			years[count2] = j + 1900; //enters actual years
			count2++;
		}
	}
	
	// displays years with a losses
	cout << "Notre Dame had at least " << a << " loss(es) in the "; 
	cout << "year(s): ";
	cout << endl;
	int count3 = 0; //to limit amount of years displayed per line
	for (int k = 0; k < count2; k++){
		if (count3 == 10){
			cout << endl;
			count3 = 0;
		}
		else{
			cout << years[k] << " ";
			count3++;	
		}
	}
	cout << endl;
}

// displays the year with the most amount of wins
void mostwins(){
	int size = sizeof(wins) / sizeof(int);
	int mostwin = 1; // initial value for most wins
	for (int i = 0; i < size; i++){
		if (wins[i] > mostwin)
			mostwin = wins[i];
	}

	int count = 0; // keep track of how many years has mostwin
	for (int j = 0; j < size; j++){
		if (wins[j] == mostwin)
			count++;
	}
	
	int years[count];
	int count2 = 0; //used to populate years
	for (int k = 0; k < size; k++){
		if (wins[k] == mostwin){
			years[count2] = k + 1900;
			count2++;
		}
	}
	
	//output	
	cout << "\nNotre Dame had the most wins in the year(s): " << endl;
	for (int m = 0; m < count2; m++)
		cout << years[m] << " ";
	cout << "\nThey had " << mostwin << " wins for those years" << endl;
}

// displays the year with the most amount of losses
void mostlosses(){
	int size = sizeof(wins) / sizeof(int);
	int mostloss = 1; // initial value for most losses
	for (int i = 0; i < size; i++){
		if (losses[i] > mostloss)
			mostloss = losses[i];
	}

	int count = 0; // keep track of how many years has mostloss
	for (int j = 0; j < size; j++){
		if (losses[j] == mostloss)
			count++;
	}

	int years[count];
	int count2 = 0; //used to populate years
	for (int k = 0; k < size; k++){
		if (losses[k] == mostloss){
			years[count2] = k + 1900;
			count2++;
		}
	}
	
	// output
	cout << "\nNotre Dame had the most losses in the year(s): " << endl;
	for (int m = 0; m < count2; m++)
		cout << years[m] << " ";
	cout << "\nThey had " << mostloss << " losses for those years";
	cout << endl;
}
 


