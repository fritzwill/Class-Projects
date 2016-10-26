// Creates a multiplication table based on user inputs

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
	int x = 0;
	cout << "Enter the amount of numbers on the X-axis: ";
	cin >> x; // rows
	int y = 0;
	cout << "Enter the amount of numbers on the y-axis: ";
	cin >> y; // columns
	for (int i = 1; i <= x+1;i++) { //must use x+1 so every row is used
		if (i == 1) {
			cout << setw(5) << "*";
		}
		else {
			cout << setw(5) << (i-1);
		}
		for (int j = 1;j <= y;j++) {
			if (i == 1) {
				cout << setw(5) << j*i;
			}
			else {
				cout << setw(5) << j*(i-1);
			}
		}
		cout << endl;
	}
}



