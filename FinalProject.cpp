//Braden Collins
//Final Project
//Lab Section: Online
//date

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class symptomChecker{
	public:
		void printTable(){
			cout<<"Guide:\t\t* Common\t+ Sometimes/Rarely\t- NO"<<endl;
			cout<<"========================================================================="<<endl;
			cout<<"Symptoms\t\t|\tCOVID-19|\tCold\t|\tFlu\t|"<<endl;
			cout<<"========================================================================="<<endl;
			cout<<"Fever\t\t\t|\t*\t|\t+\t|\t*\t|"<<endl;
			cout<<"Cough\t\t\t|\t*\t|\t+\t|\t*\t|"<<endl;
			cout<<"Shortness of Breath\t|\t*\t|\t-\t|\t-\t|"<<endl;
			cout<<"Runny Nose\t\t|\t+\t|\t*\t|\t+\t|"<<endl;
			cout<<"Headaches\t\t|\t+\t|\t+\t|\t*\t|"<<endl;
			cout<<"Sneezing\t\t|\t-\t|\t*\t|\t-\t|"<<endl;
			cout<<"Fatigue\t\t\t|\t+\t|\t+\t|\t*\t|"<<endl;
			cout<<"========================================================================="<<endl;
		}//end printTable()
		
		void genRandSymp(){
			
			
			//cout<<randomNum<<endl;
		}//end genRandSymp()
		
};//end symptomChecker class

int main(){
	//creates a symptomChecker instance
	symptomChecker test;
	
	//prints the table
	cout<<"Welcome to Symptom Checker\n"<<endl;
	test.printTable();
	
	//takes the users input
	int iChoice;
	cout<<"\nEnter the number of patients? ";
	cin>>iChoice;
	
	//checks that the choice is greater than 0
	while(iChoice<0){
		cout<<"Invalid number\n";
		cout<<"Please enter a positive number: ";
		cin>>iChoice;
	}//end if
		
	cout<<"================================"<<endl;
	cout<<"Symptom Checker..."<<endl;
	
	int covid=0;
	int cold=0;
	int flu=0;
	int other=0;
	
	//generates random symptoms
	bool fever;
	bool cough;
	bool shortBreath;
	bool runnyNose;
	bool Headache;
	bool sneezing;
	bool fatigue;
	
	bool symptom;
	
	//seeds for random numbers
	srand(time(0));
	
	for(int i=0;i<iChoice;i++){
		for(int k=0;k<7;k++){
			//generates a random number
			int randomNum=rand()%2;
			if(randomNum==0){
				symptom=false;
			}
			else{
				symptom=true;
			}
		}
		fever=symptom;
		cough=symptom;
	}
	cout<<fever<<endl;
	cout<<cough<<endl;
	
	cout<<covid<<" patients have symptoms of COVID-19"<<endl;
	cout<<cold<<" patients have symptoms of Cold"<<endl;
	cout<<flu<<" patients have symptoms of Flu"<<endl;
	cout<<other<<" patients may have some other illness"<<endl;
	cout<<"================================"<<endl;
	
	int covidPerc=covid/iChoice;
	int coldPerc=cold/iChoice;
	int fluPerc=flu/iChoice;
	int otherPerc=other/iChoice;
	
	cout<<"\nPercentage of each illness:"<<endl;
	cout<<"COVID-19:\t["<<covidPerc<<"%]";
	for(int i=0;i<covidPerc;i++){
		cout<<"+";
	}
	cout<<"\nCold:\t\t["<<coldPerc<<"%]";
	for(int i=0;i<<coldPerc;i++){
		cout<<"+";
	}
	cout<<"\nFlu:\t\t["<<fluPerc<<"%]";
	for(int i=0;i<<fluPerc;i++){
		cout<<"+";
	}
	cout<<"\nOther illness:\t["<<otherPerc<<"%]";
	for(int i=0;i<<otherPerc;i++){
		cout<<"+";
	}
	
	return 0;
}