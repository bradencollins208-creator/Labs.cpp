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
		
		void genRandSymp(int count,int* condition1,int* condition2,int* condition3,int* condition4){
			bool symptoms[7];
			
			for(int i=0;i<count;i++){
				for(int k=0;k<7;k++){
					//generates a random number
					symptoms[k]=rand()%2;
				}//end for loop
				
				if(symptoms[0]==true && symptoms[1]==true && symptoms[2]==true){
					(*condition1)++;
				}//end if
				else if(symptoms[3]==true && symptoms[5]==true){
					(*condition2)++;
				}//end else if
				else if(symptoms[0]==true && symptoms[1]==true && symptoms[4]==true && symptoms[6]==true){
					(*condition3)++;
				}//end else if
				else{
					(*condition4)++;
				}//end else
			}//end for loop
		}//end genRandSymp()
		
		int conditionPercentages(int condition, int count){
			int result=((condition * 100)/count);
			return result;
		}//end conditionPercenages()
		
		void printConditionPerc(string condition, int conditionPerc){
			cout<<condition<<"["<<conditionPerc<<"%]";
			for(int i=0;i<conditionPerc;i++){
				cout<<"+";
			}//end for loop
		}//end printConditionPerc()
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
	while(iChoice<=0){
		cout<<"Invalid number\n";
		cout<<"Please enter a positive number: ";
		cin>>iChoice;
	}//end if
		
	cout<<"================================"<<endl;
	cout<<"Symptom Checker..."<<endl;
	
	//seeds for random numbers
	srand(time(0));
	
	int covid=0;
	int cold=0;
	int flu=0;
	int other=0;
	test.genRandSymp(iChoice,&covid,&cold,&flu,&other);
	
	cout<<covid<<" patients have symptoms of COVID-19"<<endl;
	cout<<cold<<" patients have symptoms of Cold"<<endl;
	cout<<flu<<" patients have symptoms of Flu"<<endl;
	cout<<other<<" patients may have some other illness"<<endl;
	cout<<"================================"<<endl;
	
	cout<<"\nPercentage of each illness:"<<endl;
	test.printConditionPerc("COVID-19:\t",test.conditionPercentages(covid,iChoice));
	test.printConditionPerc("\nCold:\t\t",test.conditionPercentages(cold,iChoice));
	test.printConditionPerc("\nFlu:\t\t",test.conditionPercentages(flu,iChoice));
	test.printConditionPerc("\nOther illness:\t",test.conditionPercentages(other,iChoice));
	
	return 0;
}