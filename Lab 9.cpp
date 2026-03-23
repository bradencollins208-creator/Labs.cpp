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
			
			topLeft="\n 1 ";
			topMiddle="| 2 |";
			topRight=" 3 ";
			
			middleLeft=" 4 ";
			middleMiddle="| 5 |";
			middleRight=" 6 ";
			
			bottomLeft=" 7 ";
			bottomMiddle="| 8 |";
			bottomRight=" 9 \n";
			
			
			cout<<topLeft;
			cout<<topMiddle;
			cout<<topRight<<endl;
			
			cout<<"-----------"<<endl;
			
			cout<<middleLeft;
			cout<<middleMiddle;
			cout<<middleRight<<endl;
			
			cout<<"-----------"<<endl;
			
			cout<<bottomLeft;
			cout<<bottomMiddle;
			cout<<bottomRight<<endl;
		}
};


int main(){
	board newBoard;
	
	int XorO=0;
	
	cout<<"Tic Tac Toe"<<endl;
	cout<<"1) X"<<endl;
	cout<<"2) O"<<endl;
	cout<<"What would like to play: ";
	cin>>XorO;
	
	if(XorO==1){
		cout<<"User is X"<<endl;
	}
	else if(XorO==2){
		cout<<"User is O"<<endl;
	}
	else{
		cout<<"Invalid Input"<<endl;
	}
	
	newBoard.printBoard();
	return 0;
}//end main()