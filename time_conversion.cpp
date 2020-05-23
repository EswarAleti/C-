#include<iostream>
using namespace std;

void _24_to_12(int &hour, int &minute, string &meridian)
{
	if(hour==12)
	{
		meridian="PM";
	}
	else if(hour>12)
	{
		hour=hour-12;
		meridian="PM";
	}
	else
	{
		meridian="AM";
		if(hour==0)
		{
			hour=12;
		}
	}
}

void _12_to_24(int &hour, int &minute, string &meridian)
{
	if(hour==12)
	{
		hour = meridian=="AM"?0:12;
	}
	else if(meridian=="PM")
	{
		hour=hour+12;
	}
}

int main()
{
	string cont;
	int hour,minute,choice;
	string meridian="",time;
	do
	{
		cout<<"1. 24-hour to 12-hour\n2. 12-hour to 24-hour\nEnter your choice."<<endl;
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter 24-hour time in format HH:MM"<<endl;
			// Input 24-hour format time from user
			cin>>time;
			int index = time.find(':');
			// Left part of : is hours
			hour = stoi(time.substr(0,index));
			// Right part of : is minutes
			minute = stoi(time.substr(index+1));
			// Convert
			_24_to_12(hour,minute,meridian);
			// Show the output
			cout<<"Time in 12-hour format:"<<endl;
			cout<<hour<<":"<<minute<<" "<<meridian<<endl;
		}
		else
		{
			cout<<"Enter 12-hour time in format HH:MM AM/PM"<<endl;
			// Remove newline character of above printing statement
			cin>>ws;
			// Input 12-hour format time from user
			getline(cin,time);
			int index = time.find(':');
			// Left part of : is hours
			hour = stoi(time.substr(0,index));
			// Middle part of : and white space is minutes
			minute = stoi(time.substr(index+1,time.find(' ')-index));
			// Right part of white space is meridian
			meridian = time.substr(time.find(' ')+1);
			// Convert
			_12_to_24(hour,minute,meridian);
			// Output
			cout<<"Time in 24-hour format:"<<endl;
			cout<<hour<<":"<<minute<<endl;
		}
		cout<<"Enter Y or y to continue, anything else quits."<<endl;
		cin>>cont;
	}while(cont=="Y" || cont=="y");
	return 0;
}