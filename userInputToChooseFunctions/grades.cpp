// Will Fritz
// 9-20-16
// reads grade values from a data file into an array and then computes 
// their average and standard deviation

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int count = 0; // has to be int along with array
	double sum = 0;
	double a = 0;
	int grades[50]; // initializes grades array (can't be > 50)
	
	cin >> a; //allows so the first input is not 0
	
	while (a != -1) {
		grades[count] = a;
		count++;
		sum += a; // will be used later to compute average
		cin >> a;
	}

	double avg = sum / count;
	double sum2 = 0; // Will be used to compute stnd deviation
	
	for (int i = 0; i < count; i++) {
		double b = pow((grades[i] - avg),2);
		sum2 += b; // allows for sum of x-avg squared
		
	}
	
	double stndev = sqrt(sum2 / count);
	
	// Outputs
	cout << "The average of the data is: " << avg << endl;
	cout << "The standard deviation of the data is: " << stndev;
	cout << endl;
} 		
		
		
		

