// Will Fritz
// 10/2/2016
//
// Creates a program that given a chess board, it tells you weather either black or white king is in check


#include <iostream>
#include <iomanip>

using namespace std;

bool pawn(char [][], int, int);
bool knight(char [][], int, int);
bool bishop(char [][], int, int);
bool rook(char [][], int, int);
bool queen(char [][], int, int);
bool king(char [][], int, int);

int main (){
	char board[8][8];
	bool hold = true;
	while(hold){
		cout << "Please enter an 8 by 8 chess board: " << endl;
		for (int 1 = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cin >> a;
				board[i][j] = a;
			}
		}
			


}

bool pawn(char board[][], int a, int b){
	if (board[a][b] == 'p'){
		if ((a+1) > 8) // makes sure pawn can move
			return false;
		else if ((b+1) > 8){ // makes sure it only checks board
			if (board[a+1][b-1] == 'K')
				return true;
			else
				return false;
		}
		
		else if ((b-1) < 0){ // makes sure it only checks board
			if (board[a+1][b+1] == 'K')
				return true;
			else
				return false;
		}
		
		else if (board[a+1][b+1] == 'K' || board[a+1][b-1] == 'K') 
			return true; //pawn is able to both diaganol directions
		else
			return false;
	}
	
	else if (board[a][b] == 'P'){
		if ((a-1) < 0) //makes sure pawn can move
			return false;
		else if ((b+1) > 8){ // makes sure it only checks board
			if (board[a-1][b-1] == 'k')
				return true;
			else 
				return false;
		}
		
		else if ((b-1) < 0){ // makes sure it only checks board
			if (board[a-1][b+1] == 'k')
				return true;
			else
				return false;
		}
		
		else if (board[a-1][b+1] == 'k' || board[a-1][b-1] == 'k')
			return true; //pawn is able to both diaganol directions
		else
			return false;
	}
	
	else 
		return false;
}

bool knight(char board[][], int a, int b){
	if (board[a][b] == 'n'){                                          	
		if ((a+1) > 8){
			if (board[a-1][b+2] == 'K' || board[a-1][b-2] == 'K' || board[a-2][b+1] == 'K' || board[a-2][b-1] == 'K') // all cases if n on bot
				return true;
			else 
				return false;
		else if ((a+2) > 8 && (b-2) < 0){
			if (board[a+1][b+2] == 'K')
				return true;
			else
				return false;
		}
		else if ((a+2) > 8 && (b+2) > 8){
			if (board[a+1][b-2] == 'K')
				return true;
			else
				return false;
		}
		else if ((b+1) > 8){ // makes sure it only checks board
			if (board[a+1][b-1] == 'K')
				return true;
			else
				return false;
		}
		
		else if ((b-1) < 0){ // makes sure it only checks board
			if (board[a+1][b+1] == 'K')
				return true;
			else
				return false;
		}
		
		else if (board[a+1][b+1] == 'K' || board[a+1][b-1] == 'K')
			return true; //pawn is able to both diaganol direc
		else
			return false;
	}
	
	else if (board[a][b] == 'P'){
		if ((a-1) < 0) //makes sure pawn can move
			return false;
		else if ((b+1) > 8){ // makes sure it only checks board
			if (board[a-1][b-1] == 'k')
				return true;
			else 
				return false;
		}
		
		else if ((b-1) < 0){ // makes sure it only checks board
			if (board[a-1][b+1] == 'k')
				return true;
			else
				return false;
		}
		else if (board[a-1][b+1] == 'k' || board[a-1][b-1] == 'k')

} 
}
bool bishop(char board[][], int a, int b){
	if (board[a][b] == 'b'){
		int count = 1;
		for (int i = a+1; i < 8; i++){
			if (board[i][b+count] != '.' || board[i][b+count] != 'K')
				return false;
			if (board[i][b+count] 









