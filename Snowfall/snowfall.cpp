#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//Declaration of snowfall vector of double
	vector<double> snowfall;
	cout<<"Enter snowfall (Enter -1 to exit): "<<endl;
	double val;
	//if user enter 0.0 then valid will be true, false otherwise
	bool valid = false;
	while(true)
	{
		cin>>val;
		//If user enter 0.0 then set valid as true
		if(val==0)
		{
			valid=true;
		}
		//If user wants to exit by entering valid input
		if(val==-1 && valid==true)
		{
			break;
		}
		//If user wants to exit without entering 0.0
		if(val==-1 && valid==false)
		{
			cout<<"User should enter 0.0"<<endl;
			continue;
		}
		//Push to the vector
		snowfall.push_back(val);
	}
	int i;
	double sum_Detroit=0;
	int count_Detroit=0;
	//Add snowfall of Detroit till vector got 0.0
	for(i=0;snowfall[i]!=0.0;i++)
	{
		sum_Detroit+=snowfall[i];
		count_Detroit++;
	}
	//Calculate average
	double avg_Detroit = sum_Detroit/count_Detroit;
	cout<<"Average snowfall of Detroit: "<<avg_Detroit<<endl;

	double sum_Seattle=0;
	int count_Seattle=0;
	//Start i from next to the 0.0 value
	for(i=i+1;i<snowfall.size();i++)
	{
		sum_Seattle+=snowfall[i];
		count_Seattle++;
	}
	//Calculate average
	double avg_Seattle = sum_Seattle/count_Seattle;
	cout<<"Average snowfall of Seattle: "<<avg_Seattle<<endl;
}