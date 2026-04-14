//Braden Collins
//Final Project
//Lab Section: Online
//4-14-26

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace illnessChecker{
	class symptomTable{
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
	};//end symptomTable class
	
	class symptomChecker:public symptomTable{
		public:
			void genRandSymp(int count,int* condition1,int* condition2,int* condition3,int* condition4){
				//creates a boolean array to store the seven possible symptoms
				bool symptoms[7];
				
				//runs a nested for loop for to generate a true or false value for each symptom for the number of people the user enters
				for(int i=0;i<count;i++){
					for(int k=0;k<7;k++){
						//generates a random number
						symptoms[k]=rand()%2;
					}//end for loop
					
					//checks if the symptoms match a condition and adds to each condition count
					if(symptoms[0] && symptoms[1] && symptoms[2]){
						(*condition1)++;
					}//end if
					else if(symptoms[3] && symptoms[5]){
						(*condition2)++;
					}//end else if
					else if(symptoms[0] && symptoms[1] && symptoms[4] && symptoms[6]){
						(*condition3)++;
					}//end else if
					else{
						(*condition4)++;
					}//end else
				}//end for loop
			}//end genRandSymp()
			
			//calculates the percentages for each condition
			int conditionPercentages(int condition, int count){
				int result=((condition * 100)/count);
				return result;
			}//end conditionPercenages()
			
			//prints the percentages for each contition with the pluses
			void printConditionPerc(string condition, int conditionPerc){
				cout<<condition<<"["<<conditionPerc<<"%]";
				for(int i=0;i<conditionPerc;i++){
					cout<<"+";
				}//end for loop
				cout<<endl;
			}//end printConditionPerc()
	};//end symptomChecker class
}//end namespace illnessChecker

int main(){
	//creates a symptomChecker instance
	illnessChecker::symptomChecker test;
	
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
	
	//creates count variables for each contition
	int covid=0;
	int cold=0;
	int flu=0;
	int other=0;
	
	//runs the genRandSymp function to generate random symptoms for each patient the user enters
	test.genRandSymp(iChoice,&covid,&cold,&flu,&other);
	
	//prints the number of patients that have each contition
	cout<<covid<<" patients have symptoms of COVID-19"<<endl;
	cout<<cold<<" patients have symptoms of Cold"<<endl;
	cout<<flu<<" patients have symptoms of Flu"<<endl;
	cout<<other<<" patients may have some other illness"<<endl;
	cout<<"================================"<<endl;
	
	//prints the percentages of each illness using the printConditionPerc function and the conditionPercentages function
	cout<<"\nPercentage of each illness:"<<endl;
	test.printConditionPerc("COVID-19:\t",test.conditionPercentages(covid,iChoice));
	test.printConditionPerc("Cold:\t\t",test.conditionPercentages(cold,iChoice));
	test.printConditionPerc("Flu:\t\t",test.conditionPercentages(flu,iChoice));
	test.printConditionPerc("Other illness:\t",test.conditionPercentages(other,iChoice));
	
	return 0;
}//end main()