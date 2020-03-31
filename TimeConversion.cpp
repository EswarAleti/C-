#include<iostream>
using namespace std;

void convert(int &h , char &meridium)
{
	//If hour=12 then only meridium needed to be changed to PM
	if(h==12)
	{
		meridium='P';
	}
	//If hour>12 then change both hours and meridium
	else if(h>12)
	{
		h=h-12;
		meridium='P';
	}
	//Otherwise meridium should be AM
	else
	{
		meridium='A';
	}
}

//Function that takes inputs from user
void InputTime(int &h,int &min ,char &meridium)
{
	//User input as hours and minutes
	cout<<"Enter hours :";
	cin>>h;
	cout<<"Enter minutes :";
	cin>>min;
	//function calling to convert the time
	convert(h,meridium);
}

void output(int &h , int &min ,char &meridium)
{
	//Print hours and minutes
	cout<<"Time : "<<h<<":"<<min;
	//Print AM/PM
	if(meridium == 'P')
		cout<<"PM\n";
	else
		cout<<"AM"<<endl;
}
int main()
{
	int opt ,hh ,mm;
	char meridium;
	while(true)
	{
		cout<<"1.Enter time\n";
		cout<<"2.Exit\n";
		cout<<"Enter your option :";
		cin>>opt;
		//If user wants to convert another time
		if(opt == 1)
		{
			InputTime(hh , mm,meridium);
			output(hh ,mm,meridium);	
		}
		//If user wants to exit then break the loop
		else
			break;
	}
}
