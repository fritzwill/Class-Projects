#include <iostream>
#include <cmath>

using namespace std;

int main () {
   float a = 0;
   float b = 0;
   float c = 0;
   
   cout << "-------Heron's Formula-------" << endl;
   cout << "Enter the length of side 1 of the triangle: ";
   cin >> a;
   if (a<=0) {
      cout<< "Error: you must enter a number greater than 0"<<endl;
      return 0;
   }
   cout << "Enter the length of side 2 of the triangle: ";
   cin >> b;
   if (b<=0) {
      cout << "Error: you must enter a number greater than 0"<<endl;
      return 0;
   }
   cout << "Enter the length of side 3 on the triangle: ";
   cin >> c;
   if (c<=0) {
      cout << "Error: you must enter a number greater than 0"<<endl;
      return 0;
   }
   
   float s = (a+b+c)/2;
   
   float arg = (s-a)*(s-b)*(s-c)*s;
   
   float area = sqrt(arg);
   
   cout << "The area of the triangle with sides " << a << ", " << b;
   cout <<  ", and " << c << " is: " << area << endl;
}

   
    
