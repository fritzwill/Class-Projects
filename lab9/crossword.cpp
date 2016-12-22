// Will Fritz
// 11/22/2016
// Creates a blank crowssword anagram puzle

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct crossword {
    char board[15][15];
    vector<string> userStrings;
    vector<string> shuffledStrings;
};

void prompt(crossword &);
bool checkString(string);
void makeBoard(crossword &);
void displayBoard(crossword);
string longestString(crossword);
void addStringH(string, int, int, crossword &);

int main(){
    crossword puzzle;
    prompt(puzzle);
    
    string longestStr;
    longestStr = longestString(puzzle);
    int yCoorLongString;
    yCoorLongString = (15 - (longestStr.size()/2));
    addStringH(longestStr, 15, yCoorLongString, puzzle);

    displayBoard(puzzle);
    
}

void prompt(crossword &p){
    string temp;
    int wordCount; // will be used to make sure only 20 words are entered

    // continues to ask user until period
    cout << "\nEnter a list of words:\n";
    cin >> temp;
    while(temp != "."){ 
        if (checkString(temp)){
            for (auto & c: temp) c = toupper(c); //makes word upper case
                p.userStrings.push_back(temp);
                wordCount++;
        }
        else {
            cout << "\nSorry, you must enter a word < 15 letters and all";
            cout << " letters must be in the alphabet";
            cout << "\nPlease restart your list:\n";
            p.userStrings.clear(); // clers the vector so new list can start
        }
        cin >> temp;
    }
}

bool checkString(string a){
    bool valid = false;
    if (a.size() > 15) return valid; // length boundary
    
    // Check if entered characters are within alphabet
    for (int i = 0; i < a.size(); i++){
        if ((a[i] < 65) || ((a[i] > 90) && (a[i] < 97)) || (a[i] > 122))
            return valid;
    }
    valid = true;
    return valid;
}

void makeBoard(crossword &p){
    // Creates 15 by 15 blank board
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++)
            p.board[i][j] = '#';
    }
}

// finds longest word in vector an places in boad
string longestString(crossword p){    
    string longestStr;
    longestStr = p.userStrings[0];
    for (auto i = p.userStrings.begin(); i != p.userStrings.end(); i++){
        if ((*i).size() > longestStr.size())
            longestStr = *i;
    }
}

// takes coordinates of word and adds it horizontally to board
void addStringH(string s, int x, int y, crossword &p){
    int stringCounter = 0; // will be used to access chars of string s
    for (int i = y; i < (y + s.size()); i++){
        p.board[x][i] = s[stringCounter];
        stringCounter++;
    }
}


void displayBoard(crossword p){
    for (int i = 0; i < 15; i++){ 
        for (int j = 0; j < 15; j++)
            cout << p.board[i][j];
        cout << endl;
        }
}



