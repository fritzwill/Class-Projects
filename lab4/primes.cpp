// Will Fritz
// 9/21/2016
// FInd all prime numbers etween 1 and 1000


#include <iostream>
#include <iomanip>

using namespace std;

void remove(bool []);
void display(bool []);

int main(){
	bool mainarray[1000];
	// assume all values are prime. in this case true -> prime
	for (int i = 2; i < 1000; i++){
		mainarray[i] = true;
	}
	remove(mainarray);
	display(mainarray);
	
}

void remove(bool a[]) {
	for (int i = 2; i < 1000; i++){ 
		if (a[i] == true){ //checks to see what values are still T
			for (int j = 2*i; j < 1000; j += i){
				a[j] = false; // removes multiples of prime
			}
		}
	}
}
				
void display(bool a[]){
	// To determine the amount of prime numbers
	int size = 0;
	for (int i = 2; i < 1000; i++){
		if (a[i] == true)
			size++;
	}

	int b[size]; //will be used to display int values given bool values
	int count2 = 0;
	for (int j = 2; j < 1000; j++){
		if (a[j] == true){
			b[count2] = j; //the actual prime numbers
			count2++;
		}
	} 
	
	int count3 = 0;
	// used to output the prime numbers in 10x10
	for (int k = 0; k < size; k++){
		count3++;
		cout << setw(5) << b[k];
		if (count3 == 10) { // creates rows of 10
			cout << endl;
			count3 = 0;
		}
	}
	cout << endl;
} 
		 
				
					 
