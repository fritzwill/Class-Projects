// Will Fritz
// 10/25/16
// interface for state class (state.h
#include <string>
using namespace std;

class State{
	public:
		State();
		State(string , string , string , int , int , int );
		~State();
		string getAbr();
		string getName();
		string getCapital();
		int getPop();
		int getYear();
		int getRep();
		void print();
	private:
		string abr; // state abbreviation
		string name;
		string capital;
		int pop; // population of state
		int year; // year it became state
		int rep;  // number of representatives in COngress
	
};
