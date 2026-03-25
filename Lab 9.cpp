//Braden Collins
//Lab 9 Assignment: Tic Tac Toe
//Lab Section: Online
//date

#include <iostream>
#include <string>
using namespace std;

class board{
	public:
		string topLeft;
		string topMiddle;
		string topRight;
		
		string middleLeft;
		string middleMiddle;
		string middleRight;
		
		string bottomLeft;
		string bottomMiddle;
		string bottomRight;
		
		
		void printBoard(){
			
			cout<<"\n";
			cout<<topLeft;
			cout<<"|";
			cout<<topMiddle;
			cout<<"|";
			cout<<topRight<<endl;
			
			cout<<"-----------"<<endl;
			
			cout<<middleLeft;
			cout<<"|";
			cout<<middleMiddle;
			cout<<"|";
			cout<<middleRight<<endl;
			
			cout<<"-----------"<<endl;
			
			cout<<bottomLeft;
			cout<<"|";
			cout<<bottomMiddle;
			cout<<"|";
			cout<<bottomRight;
			cout<<"\n"<<endl;
		}//end printBoard()
		
		bool winCondition(string p){
			//left column
			if(topLeft==p && middleLeft==p && bottomLeft==p){
				return true;
			}//end if
			
			//middle column
			else if(topMiddle==p && middleMiddle==p && bottomMiddle==p){
				return true;
			}//end else if
			
			//right column
			else if(topRight==p && middleRight==p && bottomRight==p){
				return true;
			}//end else if
			
			//top row
			else if(topLeft==p && topMiddle==p && topRight==p){
				return true;
			}//end else if
			
			//middle row
			else if(middleLeft==p && middleMiddle==p && middleRight==p){
				return true;
			}//end else if
			
			//bottom row
			else if(bottomLeft==p && bottomMiddle==p && bottomRight==p){
				return true;
			}//end else if
			
			//forward slash
			else if(bottomLeft==p && middleMiddle==p && topRight==p){
				return true;
			}//end else if
			
			//back slash
			else if(topLeft==p && middleMiddle==p && bottomRight==p){
				return true;
			}//end else if
			
			//draw
			else{
				//
			}//end else
		}//end winCondition()
		
		//returns true if the space is open
		bool checkSpace(string space){
			if(space==" 1 " || space==" 2 " || space== " 3 "
			|| space==" 4 " || space==" 5 " || space==" 6 " 
			|| space==" 7 " || space==" 8 " || space==" 9 "){
				return true;
			}
			else{
				return false;
			}
		}//end checkSpace()
		
		int checkCloseWin(string p){
			//top left column
			if(topLeft==p && middleLeft==p){
				return 1;
			}//end if
			
			//top middle column
			else if(topMiddle==p && middleMiddle==p){
				return 2;
			}//end else if
			
			//top right column
			else if(topRight==p && middleRight==p){
				return 3;
			}//end else if
			
			//bottom left column
			else if(middleLeft==p && bottomLeft==p){
				return 4;
			}//end if
			
			//bottom middle column
			else if(middleMiddle==p && bottomMiddle==p){
				return 5;
			}//end else if
			
			//bottom right column
			else if(middleRight==p && bottomRight==p){
				return 6;
			}//end else if
			
			//top left row
			else if(topLeft==p && topMiddle==p){
				return 7;
			}//end else if
			
			//middle left row
			else if(middleLeft==p && middleMiddle==p){
				return 8;
			}//end else if
			
			//bottom left row
			else if(bottomLeft==p && bottomMiddle==p){
				return 9;
			}//end else if
			
			//top right row
			else if(topMiddle==p && topRight==p){
				return 10;
			}//end else if
			
			//middle right row
			else if(middleMiddle==p && bottomMiddle==p){
				return 11;
			}//end else if
			
			//bottom tight row
			else if(bottomMiddle==p && bottomRight==p){
				return 12;
			}//end else if
			
			//bottom forward slash
			else if(bottomLeft==p && middleMiddle==p){
				return 13;
			}//end else if
			
			//top forward slash
			else if(middleMiddle==p && topRight==p){
				return 14;
			}//end else if
			
			//top back slash
			else if(topLeft==p && middleMiddle==p){
				return 15;
			}//end else if
			
			//bottom back slash
			else if(middleMiddle==p && bottomRight==p){
				return 16;
			}//end else if
			
			else{
				return 0;
			}//end else
		}//end checkCloseWin()
};//end class board


int main(){
	board newBoard;
	
	newBoard.topLeft=" 1 ";
	newBoard.topMiddle=" 2 ";
	newBoard.topRight=" 3 ";
	
	newBoard.middleLeft=" 4 ";
	newBoard.middleMiddle=" 5 ";
	newBoard.middleRight=" 6 ";
	
	newBoard.bottomLeft=" 7 ";
	newBoard.bottomMiddle=" 8 ";
	newBoard.bottomRight=" 9 ";
	
	int XorO=0;
	
	cout<<"Tic Tac Toe"<<endl;
	cout<<"1) X"<<endl;
	cout<<"2) O"<<endl;
	cout<<"What would like to play: ";
	cin>>XorO;
	
	if(XorO==1){
		while(newBoard.winCondition(" X ")==false){
			int spaceChoice=0;
			
			newBoard.printBoard();
			cout<<"Enter the number of the space you would like to play: ";
			cin>>spaceChoice;
			if(spaceChoice==1){
				if(newBoard.checkSpace(newBoard.topLeft)==true){
					newBoard.topLeft=" X ";
					if(newBoard.checkCloseWin(" X ")==1){
						newBoard.bottomLeft=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==7){
						newBoard.topRight=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==15){
						newBoard.bottomRight=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==0){
						newBoard.topMiddle=" O ";
					}
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==2){
				if(newBoard.checkSpace(newBoard.topMiddle)==true){
					newBoard.topMiddle=" X ";
					if(newBoard.checkCloseWin(" X ")==2){
						newBoard.bottomMiddle=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==7){
						newBoard.topRight=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==10){
						newBoard.topLeft=" O ";
					}
					else if(newBoard.checkCloseWin(" X ")==0){
						newBoard.middleMiddle=" O ";
					}
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==3){
				if(newBoard.checkSpace(newBoard.topRight)==true){
					newBoard.topRight=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==4){
				if(newBoard.checkSpace(newBoard.middleLeft)==true){
					newBoard.middleLeft=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==5){
				if(newBoard.checkSpace(newBoard.middleMiddle)==true){
					newBoard.middleMiddle=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==6){
				if(newBoard.checkSpace(newBoard.middleRight)==true){
					newBoard.middleRight=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==7){
				if(newBoard.checkSpace(newBoard.bottomLeft)==true){
					newBoard.bottomLeft=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==8){
				if(newBoard.checkSpace(newBoard.bottomMiddle)==true){
					newBoard.bottomMiddle=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
			else if(spaceChoice==9){
				if(newBoard.checkSpace(newBoard.bottomRight)==true){
					newBoard.bottomRight=" X ";
				}
				else{
					cout<<"\nSpace filled\nEnter another number"<<endl;
				}
			}
		}//end while loop
		newBoard.printBoard();
		cout<<"X wins"<<endl;
	}
	else if(XorO==2){
		cout<<"User is O"<<endl;
	}
	else{
		cout<<"Invalid Input"<<endl;
	}
	return 0;
}//end main()