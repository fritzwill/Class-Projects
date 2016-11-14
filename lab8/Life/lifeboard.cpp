// Will Fritz
// 11/7/2016
// Implementation for Lifeboard class

#include "lifeboard.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// constructor
Lifeboard::Lifeboard(){
    for (int i = 0; i < 42; i++){
        for (int j = 0; j < 42; j++){
            // creates boarder
            if (i == 0 || i == 41) board[i][j] = '-';
            else if(j == 0 || j == 41) board[i][j] = '|';
            // populates the rest of the board and counter array
            else{ 
                board[i][j] = ' ';
                count[i][j] = 0;
            }
        }
    }
}

// destructor
Lifeboard::~Lifeboard(){
}

// Makes a cell contain' '
void Lifeboard::kill(int a, int b){
    if (a == 0 || a == 42 || b == 0 || b == 42) return;
    else board[a][b] = ' ';
}
 // Makes a cell contain 'X'
void Lifeboard::revive(int a, int b){
    if (a == 0 || a == 42 || b == 0 || b == 42) return;
    else board[a][b] = 'X';
}

// Goes through each element on the board and updates the count[i][j]
// so that it contaisn teh amount of alive cells surrounding it
void Lifeboard::addCount(){
    int counter = 0;
    for (int x = 1; x <= 40; x++){
        for (int y = 1; y <= 40; y++){
            // start with changing the rows
            for (int i = -1; i <= 1; i++){
                // changing columns
                for (int j = -1; j <= 1; j++){
                        if (board[x+i][y+j] == 'X') counter ++;
                }
            }
        if (board[x][y] == 'X') counter--;
        count[x][y] = counter;
        counter = 0;
        }
    }
}

// prints the board array
void Lifeboard::print(){
    cout << endl;
    for (int i = 0; i < 42; i++){
        for (int j = 0; j < 42; j++)
            cout << board[i][j];
        cout << endl;
    }
}   

// calls addCount(), kill(), revive(), so that simulation can be advanced
void Lifeboard::advance(){
    addCount();
    for (int i = 1; i <= (40); i++){
        for (int j = 1; j <= (40); j++){
            if (count[i][j] < 2 || count[i][j] > 3)
                kill(i, j);
            else if (count[i][j] == 3)
                revive(i,j);               
        }
    }
    system("clear"); //clears screen
    print();
}





  
        
        
            
