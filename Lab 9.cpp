//Braden Collins
//Lab 9 Assignment: Tic Tac Toe
//Lab Section: Online
//3-30-26

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
	
	//creates varibles for the user, computer, and the turn the game is on
	string user;
	string computer;
	bool userTurn;
	
	//sets the user as X or O and the turn the game starts on
	if(randomNum==1){
		user=" X ";
		computer=" O ";
		userTurn=true;
	}//end if
	else{
		user=" O ";
		computer=" X ";
		userTurn=false;
	}//end else
	
	//outputs what the user and computer is
	cout<<"User is:"<<user<<"\nComputer is:"<<computer<<endl;
	
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
	
	//loops the game until either the user or computer wins or the move count gets to 9 or more
	while(!newBoard.winCondition(user)==true && !newBoard.winCondition(computer)==true && moves<9){
		//prints the board
		newBoard.printBoard();
		
		//runs if the game is on the users turn
		if(userTurn==true){
			//takes an input from the user for where they want to play
			int spaceChoice;
			cout<<"\nEnter the number of the space you would like to play: ";
			cin>>spaceChoice;
			
			//checks that the choice was between 1 and 9
			if(spaceChoice<1 || spaceChoice>9){
				cout<<"Invalid number";
				continue;
			}//end if
			
			//converts the number entered by the user into row and column values for the 2d board array
			int row=(spaceChoice-1)/3;
			int col=(spaceChoice-1)%3;
			
			//checks if a space the user wants to play is occupied
			if(newBoard.board[row][col]!=user && newBoard.board[row][col]!=computer){
				newBoard.board[row][col]=user;//sets a players move to the space they choose if it is open
				moves++;//increases the move counter
				userTurn=false;//switches the turn so the computer can play
			}//end if
			
			//makes the user choose another number if they choose an occupied spot
			else{
				cout<<"\nSpace filled\nEnter another number"<<endl;
			}//end else
		}//end if
		
		//runs if the game is on the computers turn
		else{
			//creates variables for the computers move and its row and column choice
			int compMove;
			int r;
			int c;
			
			//runs a do while loop to get the row and column value for the computers move
			do{
				compMove=rand()%9+1;
				r=(compMove-1)/3;
				c=(compMove-1)%3;
			}while(newBoard.board[r][c]==user || newBoard.board[r][c]==computer);//end do while loop
			newBoard.board[r][c]=computer;//sets the computers move the random space if it is open
			cout<<"Computer plays: "<<compMove<<endl;//outputs the computers move
			moves++;//increases the move counter
			userTurn=true;//switches the turn so the user can play
		}//end else
	}//end while loop
	
	//checks if either the user or computer won or there was a draw and outputs the appropriate output
	newBoard.printBoard();
	
	if(newBoard.winCondition(user)==true){
		cout<<"\n"<<user<<"wins"<<endl;
	}//end if
	else if(newBoard.winCondition(computer)==true){
		cout<<"\n"<<computer<<"wins"<<endl;
	}//end else if
	else{
		cout<<"\nDraw"<<endl;
	}//end else
	
	return 0;
}//end main()