#include<iostream>
using namespace std;
//class average is constant
const double class_avg=78.9;

//This function will display the menu
void menu()
{
	cout<<"1) Calculate Average"<<endl;
	cout<<"2) Display minimum grade"<<endl;
	cout<<"3) Display maximum grade"<<endl;
	cout<<"4) Display the letter grade for each"<<endl;
	cout<<"   -\t>90 is A"<<endl;
	cout<<"   -\t>80 and <=90 B"<<endl;
	cout<<"   -\t>70 and <=80 C"<<endl;
	cout<<"   -\t>60 and <=70 D"<<endl;
	cout<<"   -\tOtherwise F"<<endl;
	cout<<"5) Check if the average is greater than class average"<<endl;
}

//this function return maximum value among arguments a,b
double max(double a,double b)
{
	return a>b?a:b;
}

//this function return minimum value among arguments a,b
double min(double a,double b)
{
	return a<b?a:b;
}

//this function return letter_grade for grade argument
char get_letter_grade(double grade)
{
	if(grade>90)
		return 'A';
	else if(grade>80 && grade<=90)
		return 'B';
	else if(grade>70 && grade<=80)
		return 'C';
	else if(grade>60 && grade<=70)
		return 'D';
	else
		return 'F';
}

int main()
{
	//User input
	double g1,g2,g3;
	cout<<"Enter grade1: ";
	cin>>g1;
	cout<<"Enter grade2: ";
	cin>>g2;
	cout<<"Enter grade3: ";
	cin>>g3;
	//Display menu
	menu();
	//Choice from user input
	int choice;
	cout<<"Enter your choice: ";
	cin>>choice;
	//Do corresponding operation according to user choice
	switch(choice)
	{
		case 1:
				cout<<"Average is: "<<(g1+g2+g3)/3<<endl;
				break;
		case 2:
				cout<<"Minimum grade is: "<<min(min(g1,g2),g3)<<endl;
				break;
		case 3:
				cout<<"Maximum grade is: "<<max(max(g1,g2),g3)<<endl;
				break;
		case 4:
				cout<<"Letter grade for "<<g1<<": "<<get_letter_grade(g1)<<endl;
				cout<<"Letter grade for "<<g2<<": "<<get_letter_grade(g2)<<endl;
				cout<<"Letter grade for "<<g3<<": "<<get_letter_grade(g3)<<endl;
				break;
		case 5:
				double stud_avg = (g1+g2+g3)/3;
				if(stud_avg>class_avg)
					cout<<"student average is greater than class average"<<endl;
				else
					cout<<"student average is lesser than class average"<<endl;
				break;
	}
	return 0;
}