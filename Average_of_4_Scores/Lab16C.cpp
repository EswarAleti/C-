#include<iostream>
using namespace std;

void getScores(double &a, double &b, double &c, double &d)
{
	//Take inputs from user
	cout<<"Enter 4 scores: ";
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
}

double findLowest(double a, double b, double c, double d)
{
	//If a smaller than b,c,d then return a
	if(a<=b && a<=c && a<=d)
	{
		return a;
	}
	//If b is smaller than a,c,d then return b
	if(b<=a && b<=c && b<=d)
	{
		return b;
	}
	//If c is smaller than a,b,d
	if(c<=a && c<=b && c<=d)
	{
		return c;
	}
	//return d otherwise
	return d;
}

void calcAverage(double a, double b, double c, double d)
{
	//Find total of 4 scores
	double total = a+b+c+d;
	//dubstract minimum from total
	total-=findLowest(a,b,c,d);
	//Calculate average
	double average = total/3;
	cout<<"Average: "<<average<<endl;
}

int main()
{
	double a,b,c,d;
	//Function calling
	getScores(a,b,c,d);
	calcAverage(a,b,c,d);
	return 0;
}