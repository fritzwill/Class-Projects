// Will Fritz
// 9/13/2016
// Utilizes a self-made greatest common denominator function

#include <iostream>

using namespace std;

int getgcd(int a, int b);

int main () {
	int a, b;
	int test = 1;
	while (test == 1) {
		cout << "Enter two positive integers: ";
		cin >> a >> b;
		if (a < 0 || b < 0){
			cout << "Please enter a positive number" << endl;
		}
		else {
			test = 2;
		}
	}
	
	cout << "The greatest common denominator of " << a;
	cout << " and " << b << " is " << getgcd(a,b) << endl;
}

int getgcd(int a, int b){
	int temp;
	while (a != 0) {
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
