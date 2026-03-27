//Braden Collins
//Lab 9 Assignment: Tic Tac Toe
//Lab Section: Online
//date

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class board{
	public:
		string board[3][3];
		
		void printBoard(){
			cout<<"\n";
			for(int i=0;i<3;i++){
				cout<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<endl;
				if(i<2){
					cout<<"-----------"<<endl;
				}//end if
			}//end for loop
		}//end printBoard()
		
		bool winCondition(string p){
			//rows
			for(int i=0;i<3;i++){
				if(board[i][0]==p && board[i][1]==p && board[i][2]==p){
					return true;
				}//end if
			}//end for loop
			
			//columns
			for(int i=0;i<3;i++){
				if(board[0][i]==p && board[1][i]==p && board[2][i]==p){
					return true;
				}//end if
			}//end for loop
			
			//diagonals
			if(board[0][0]==p && board[1][1]==p && board[2][2]==p){
				return true;
			}//end if
			
			if(board[2][0]==p && board[1][1]==p && board[0][2]==p){
				return true;
			}//end if
			
			return false;
		}//end winCondition()
};//end board class

int main(){
	//generates random number
	srand(time(0));
	int randomNum=rand()%2+1;
	
	//creates varibles for the user and computer
	string user;
	string computer;
	
	//sets the user as X or O
	if(randomNum==1){
		user=" X ";
		computer=" O ";
	}//end if
	else{
		user=" O ";
		computer=" X ";
	}//end else
	
	//creates a board instance
	board newBoard;
	
	//sets the boards spaces to be different numbers
	newBoard.board[0][0]=" 1 ";
	newBoard.board[0][1]=" 2 ";
	newBoard.board[0][2]=" 3 ";
	
	newBoard.board[1][0]=" 4 ";
	newBoard.board[1][1]=" 5 ";
	newBoard.board[1][2]=" 6 ";
	
	newBoard.board[2][0]=" 7 ";
	newBoard.board[2][1]=" 8 ";
	newBoard.board[2][2]=" 9 ";
	
	//creates a variable to count the number of moves made
	int moves=0;

	while(newBoard.winCondition(user)==false && newBoard.winCondition(computer)==false){
		//prints the board
		newBoard.printBoard();
		
		//takes an input from the user for where they want to play
		int spaceChoice;
		cout<<"\nEnter the number of the space you would like to play: ";
		cin>>spaceChoice;
		
		//converts the number entered by the user into row and column values for the 2d board array
		int row=(spaceChoice-1)/3;
		int col=(spaceChoice-1)%3;
		
		//checks if a space the user wants to play is occupied
		if(newBoard.board[row][col]!=user && newBoard.board[row][col]!=computer){
			newBoard.board[row][col]=user;
			moves++;//increases the move counter
		}//end if
		else{
			cout<<"\nSpace filled\nEnter another number"<<endl;
		}//end else
		
		if(newBoard.winCondition(user)==false){
			int compMove;
			do{
				compMove=rand()%9+1;
				int r=(compMove-1)/3;
				int c=(compMove-1)%3;
				
				if(newBoard.board[r][c]!=user && newBoard.board[r][c]!=computer){
					newBoard.board[r][c]=computer;
					moves++;//increases the move counter
					break;
				}//end if
			}while(true);//end do while loop
		}//end if
		
		//checks if the move counter has hit 9, ends the game with a draw if true
		if(moves==9){
			newBoard.printBoard();
			cout<<"\nDraw"<<endl;
			break;
		}//end if
	}//end while loop
	
	//checks if the move count is under 9 after the while loop ends and prints the winner of the game
	if(moves<9){
		newBoard.printBoard();
		if(newBoard.winCondition(user)==true){
			cout<<"\n"<<user<<"wins"<<endl;
		}//end if
		else{
			cout<<"\n"<<computer<<"wins"<<endl;
		}//end else
	}//end if
	
	return 0;
}//end main()