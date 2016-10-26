#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main () {
	float prin = 0;
	float rate = 0;
	float pay = 0;
	float paysum = 0;
	
	int test = 1;
	while (test == 1){
		cout << "Enter the principal of the loan: ";
		cin >> prin;
		if (prin > 0){
			test += 1;
		}
		else {
			cout << "Please enter a positive number" << endl;
		}
	}
	
	test = 1;
	while (test == 1) {
		cout << "Enter the percentage interst rate of the loan: ";
		cin >> rate;
		if (rate > 0) {
			test += 1;
			rate = rate*.01;
			rate = rate/12;
		}
		else {
			cout << "Please enter a positive number" << endl;
		}
	}
	
	test = 1;
	while (test == 1) {
		cout << "Enter the monthly payment of the loan: ";
		cin >> pay;
		
		
		if (pay > 0) {
			test += 1;
		}
		else {
			cout << "Please enter a positive number" << endl;
		}
	}
	
	cout << setw(5) <<  "Month" << setw(15) << "Payment";
	cout << setw(15) << "Interest" << setw(15) << "Balance" << endl;
	
	test = 1;
	int month = 0;
	while (test == 1) {
		float interest = prin*rate;
		float diff = pay - interest;
		prin = prin - diff;
		month += 1;
		if (pay <= interest) {
			cout << "Your payment is not enough to cover the interest";
			cout << endl;
			cout << "Please run the program again using an appropriate";
			cout << " amount" << endl;
			test += 1;
		}
		else {
			cout << setw(5) << month;
			cout << setw(9) << "$";
			cout << setw(8) << setprecision(2) << fixed << pay;
			cout << setw(6) << "$"; 
			cout << setw(9) << setprecision(2) << interest;
			cout << setw(6) << "$"; 
			cout << setw(9) << setprecision(2) << prin;
			cout << endl;
		
			if (prin < pay) {
				interest = prin*rate;
				pay = prin + interest;
			}
			if (prin <= 0) {
				test += 1;
			}
		}
		paysum = pay + paysum;
	}
	int year = floor(month/12);
	int monthfinal = month%12;
	
	cout << endl;
	cout << "You pain a total of $ " << paysum << " over " << year;
	cout << " years and " << monthfinal << " months." << endl;
	

}


