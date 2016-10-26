#include <iostream>

using namespace std;

int main () {
   int touch = 0;
   int extra = 0;
   int field = 0;
   int safety = 0;

   cout << "Enter the amount of points from touchdowns: ";
   cin >> touch;
   cout << "Enter the amount of points from extra points: ";
   cin >> extra;
   cout << "Enter the amount of points from field goals: ";
   cin >> field;
   cout << "Enter the amount of points from safeties: ";
   cin >> safety;

   int sum = touch + extra + field + safety;

   cout << "Notre Dame has a total of " << sum << " points" << endl;
}




