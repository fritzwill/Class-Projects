// Will Fritz
// 9/13/2016
// Creates a text menu driven basic calculator

#include <iostream>
#include <iomanip>

using namespace std;

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double div(double a, double b);
string quit();

int main (){
	int temp = 1;
	while (temp == 1) {
		int  input = 0;
		cout << "What would you like to do?";
		cout << "\n   1  for addition";
		cout << "\n   2  for subtraction";
		cout << "\n   3  for multiplication";
		cout << "\n   4  for division";
		cout << "\n   5  to exit";
		cout << "\nEnter your choice: ";
		cin >> input;
		
		double a, b;
		
		switch (input) {
			case 1:
				cout << "\nEnter two numbers: ";
				cin >> a >> b;
				cout << setprecision(6) << fixed << "\n(" << a << ")";
				cout << " + (" <<  b << ") = " << add(a,b) << endl;
				break;
			case 2:
				cout << "\nEnter two numbers: ";
				cin >> a >> b;
				cout << setprecision(6) << fixed <<	"\n(" << a << ")";
				cout << " - (" << b << ") = " << sub(a,b) << endl;
				break;
			case 3:
				cout << "\nEnter two numbers: ";
				cin >> a >> b;
				cout << setprecision(6) << fixed << "\n(" << a << ")";
				cout << " * (" << b << ") = " << mult(a,b) << endl;
				break;
			case 4:
				cout << "\nEnter two numbers: ";
				cin >> a >> b;
				cout << setprecision(6) << fixed << "\n(" << a << ")";
				cout << " / (" << b << ") = " << div(a,b) << endl;
				break;
			case 5:
				cout << quit() << endl;
				temp = 0;
				break;
			default:
				cout << "\nYou must enter a number between 1 and 5" << endl;
		}
	}
}

double add(double a, double b){
	double out = a + b;
	return out;
}

double sub(double a, double b){
	double out = a - b;
	return out;
}

double mult(double a, double b){
	double out = a * b;
	return out;
}

double div(double a, double b){
	double out = a / b;
	return out;
}

string quit(){
	string out = "Thank you!";
	return out;
}
