// Will Fritz
// 11/8/2016
// Simulates OCnway's game of life in tow ways. One is an interactive mode which takes inputs from the user, the other is batch mode which takes an input file to populate the scene

#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include "lifeboard.h"

using namespace std;

//prototypes
void batchMode(Lifeboard &, char* );
void interactiveMode(Lifeboard &);

int main(int argc, char *argv[]){
    Lifeboard board;
    // no file is entered
    if (argc == 1)
        interactiveMode(board);   
    // too many arguments were entered after executable
    else if (argc >= 3) 
        cout << "Too many arguments" << endl;
    // one file was entered and is based into batchMode function
    else  batchMode(board, argv[1]);
    return 0;
}

// Uses file to poulate initial board, then runs continuously
void batchMode(Lifeboard &board, char* file){
    char choice, c;
    int row, column;
    ifstream ifs;
    ifs.open(file);
    // checks if file can be opened
    if (!ifs){
        cout << "Error opening";
        exit(1);
    }
    c = ifs.peek();
    while(c != EOF){
        ifs >> choice >> row >> column;
        switch(choice){
            case 'a':
                board.revive(row,column);
                break;
            case 'p':
                while(true){
                    board.advance();
                    usleep(100000); // delays update so you can see what
                                    // is happening
                }
                break;
        }
    }
}

// gives user choices to interact with board
void interactiveMode(Lifeboard &board){
    int x,y; //will be used for user inputs
    board.print();
    char userChoice;
    while (userChoice != 'q'){
        cout << "\nPlease choose one of the folllowing options:";
        cout << "\n  a: Choose coordinates to add a new live cell";
        cout << "\n  r: Choose a live cell to remove";
        cout << "\n  n: Advance simulation";
        cout << "\n  p: Play continuosly (use ctrl-c to stop)";
        cout << "\n  q: Quit the program";
        cout << "\n\nYour choice: ";
        cin >> userChoice;
    
        switch(userChoice){
            case 'a':
                cout << "\nEnter the coordinates ((1,1) is top left): ";
                cin >> x >> y;
                board.revive(x,y);
                board.print();
                break;
            case 'r':
                cout << "\nEnter the coordinates((1,1) is top left): ";
                cin >> x >> y;
                board.kill(x,y);
                board.print();
                break;
            case 'n':
                board.advance();
                break;
            case 'p':
                while (true){
                    board.advance();
                    usleep(100000);
                }
                break;
            case 'q':
                break;
            default:
                cout << "\nYou must choose one of the displayed options\n";
        }
    }
}


