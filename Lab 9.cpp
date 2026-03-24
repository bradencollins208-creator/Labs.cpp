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
			else if(middleLeft==p && middleMiddle==p && bottomMiddle==p){
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
			
			//newBoard.middleMiddle=" X ";
		}
	}
	else if(XorO==2){
		cout<<"User is O"<<endl;
	}
	else{
		cout<<"Invalid Input"<<endl;
	}
	return 0;
}//end main()