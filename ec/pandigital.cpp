// Will Fritz
// 9/18/2016
// Find the largest pandifgital 


#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int a);
bool pan(int a);

int main(){
	int test = 987654321;
	int ans = 0;
	for (int i = test; i > 2; i--){
		if (isprime(i) == true && pan(i) == true){
			ans = i;
			break;
		}		
	}
	cout << ans << endl;
}

bool isprime(int a) {
	for (int i = 2; i < a; i++){
		if (a % i == 0){
			return false;
		}
	}	
	return true;
}

bool pan(int a){
	int temp = a; //use this so I can divide by 10 later and not affect a
	int length = 0;
	while (temp != 0){
		length++;
		temp /= 10;
	}
	int temp2 = a;
	int array [length];
	for (int i = length; i >= 1; i--){
		array[i] = temp2 % 10;
		temp2 /= 10;
	}
	int sum = 0;
	for (int j = 0; j <= length; j++){
		sum += array[j];
	}
	int check = 45; // starts at maximum sum. used to compare with sum
	for (int k = 9; k >= 2; k--){
		if (length == k && sum == check ){
			return true;
		}
		check -= k;
	}
	return false;
}
	 


		 
		
		
