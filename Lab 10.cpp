//Braden Collins
//Lab 10 Assignment: 3d Tic Tac Toe
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

class board3D: public board{
	public:
		string board3D[3][3][3];
		
		void printBoard3D(){
			string level="\nBottom: ";
			
			for(int i=0;i<3;i++){
				cout<<level<<endl;
				
				for(int k=0;k<3;k++){
					cout<<board3D[i][k][0]<<"|"
						<<board3D[i][k][1]<<"|"
						<<board3D[i][k][2]<<endl;
					
					if(k<2){
						cout<<"-----------"<<endl;
					}//end if
				}//end for loop
				
				if(i==0){
					level="\nMiddle: ";
				}//end if
				
				else if(i==1){
					level="\nTop: ";
				}//end else if
			}//end for loop
		}//end printBoard3D()
		
		bool winCondition3D(string p){
			//rows
			for(int i=0;i<3;i++){
				for(int k=0;k<3;k++){
					if(board3D[i][k][0]==p && board3D[i][k][1]==p && board3D[i][k][2]==p){
						return true;
					}//end if
				}//end for loop
			}//end for loop
			
			//columns
			for(int i=0;i<3;i++){
				for(int k=0;k<3;k++){
					if(board3D[i][0][k]==p && board3D[i][1][k]==p && board3D[i][2][k]==p){
						return true;
					}//end if
				}//end for loop
			}//end for loop
			
			//layers
			for(int i=0;i<3;i++){
				for(int k=0;k<3;k++){
					if(board3D[0][i][k]==p && board3D[1][i][k]==p && board3D[2][i][k]==p){
						return true;
					}//end if
				}//end for loop
			}//end for loop
			
			//diagonals on each layer
			for(int i=0;i<3;i++){
				if(board3D[i][0][0]==p && board3D[i][1][1]==p && board3D[i][2][2]==p){
					return true;
				}//end if
				
				if(board3D[i][2][0]==p && board3D[i][1][1]==p && board3D[i][0][2]==p){
					return true;
				}//end if
			}//end for loop
			
			//diagonals across layers
			for(int i=0;i<3;i++){
				if(board3D[0][i][0]==p && board3D[1][i][1]==p && board3D[2][i][2]==p){
					return true;
				}//end if
				if(board3D[2][i][0]==p && board3D[1][i][1]==p && board3D[0][i][2]==p){
					return true;
				}//end if
				
				if(board3D[0][0][i]==p && board3D[1][1][i]==p && board3D[2][2][i]==p){
					return true;
				}//end if
				if(board3D[2][0][i]==p && board3D[1][1][i]==p && board3D[0][2][i]==p){
					return true;
				}//end if
			}//end for loop
			
			//diagonals through the cube
			if(board3D[0][0][0]==p && board3D[1][1][1]==p && board3D[2][2][2]==p){
				return true;
			}//end if
			if(board3D[0][0][2]==p && board3D[1][1][1]==p && board3D[2][2][0]==p){
				return true;
			}//end if
			if(board3D[0][2][0]==p && board3D[1][1][1]==p && board3D[2][0][2]==p){
				return true;
			}//end if
			if(board3D[0][2][2]==p && board3D[1][1][1]==p && board3D[2][0][0]==p){
				return true;
			}//end if
			
			return false;
		}//end winCondition()
};//end board3D

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
	board3D newBoard;
	
	//sets the boards spaces to be different numbers
	newBoard.board3D[0][0][0]=" 1 ";
	newBoard.board3D[0][0][1]=" 2 ";
	newBoard.board3D[0][0][2]=" 3 ";
	
	newBoard.board3D[0][1][0]=" 4 ";
	newBoard.board3D[0][1][1]=" 5 ";
	newBoard.board3D[0][1][2]=" 6 ";
	
	newBoard.board3D[0][2][0]=" 7 ";
	newBoard.board3D[0][2][1]=" 8 ";
	newBoard.board3D[0][2][2]=" 9 ";
	
	
	newBoard.board3D[1][0][0]=" 10 ";
	newBoard.board3D[1][0][1]=" 11 ";
	newBoard.board3D[1][0][2]=" 12 ";
	
	newBoard.board3D[1][1][0]=" 13 ";
	newBoard.board3D[1][1][1]=" 14 ";
	newBoard.board3D[1][1][2]=" 15 ";

	newBoard.board3D[1][2][0]=" 16 ";
	newBoard.board3D[1][2][1]=" 17 ";
	newBoard.board3D[1][2][2]=" 18 ";
	
	
	newBoard.board3D[2][0][0]=" 19 ";
	newBoard.board3D[2][0][1]=" 20 ";
	newBoard.board3D[2][0][2]=" 21 ";
	
	newBoard.board3D[2][1][0]=" 22 ";
	newBoard.board3D[2][1][1]=" 23 ";
	newBoard.board3D[2][1][2]=" 24 ";
	
	newBoard.board3D[2][2][0]=" 25 ";
	newBoard.board3D[2][2][1]=" 26 ";
	newBoard.board3D[2][2][2]=" 27 ";
	
	//creates a variable to count the number of moves made
	int moves=0;
	
	//loops the game until either the user or computer wins or the move count gets to 27 or more
	while(!newBoard.winCondition3D(user) && !newBoard.winCondition3D(computer) && moves<27){
		
		newBoard.printBoard3D();
		
		if(userTurn==true){
			//takes an input from the user for where they want to play
			int spaceChoice;
			cout<<"\nEnter the number of the space you would like to play: ";
			cin>>spaceChoice;
			
			//checks that the choice was between 1 and 27
			if(spaceChoice<1 || spaceChoice>27){
				cout<<"Invalid number\n";
				continue;
			}//end if
			
			//converts the number entered by the user into row, column, and layer values for the 3d board array
			int row=((spaceChoice-1)/3)%3;
			int col=(spaceChoice-1)%3;
			int lay=(spaceChoice-1)/9;
			
			//checks if a space the user wants to play is occupied
			if(newBoard.board3D[lay][row][col]!=user && newBoard.board3D[lay][row][col]!=computer){
				newBoard.board3D[lay][row][col]=user;//sets a players move to the space they choose if it is open
				moves++;//increases the move counter
				userTurn=false;//switches the turn so the computer can play
			}//end if
			
			//makes the user choose another number if they choose an occupied spot
			else{
				cout<<"\nSpace filled\nEnter another number"<<endl;
			}//end else
		}//end if
		
		else{
			//creates variables for the computers move and its row, column, and layer choice
			int compMove;
			int r;
			int c;
			int l;
			
			//runs a do while loop to get the row, column, and layer value for the computers move
			do{
				compMove=rand()%27+1;
				r=((compMove-1)/3)%3;
				c=(compMove-1)%3;
				l=(compMove-1)/9;
			}while(newBoard.board3D[l][r][c]==user || newBoard.board3D[l][r][c]==computer);//end do while loop
			newBoard.board3D[l][r][c]=computer;//sets the computers move the random space if it is open
			cout<<"Computer plays: "<<compMove<<endl;//outputs the computers move
			moves++;//increases the move counter
			userTurn=true;//switches the turn so the user can play
		}//end else
	}//end while loop
	
	newBoard.printBoard3D();
	
	if(newBoard.winCondition3D(user)==true){
		cout<<"\n"<<user<<"wins"<<endl;
	}//end if
	else if(newBoard.winCondition3D(computer)==true){
		cout<<"\n"<<computer<<"wins"<<endl;
	}//end else if
	else{
		cout<<"\nDraw"<<endl;
	}//end else
	
	return 0;
}//end main()