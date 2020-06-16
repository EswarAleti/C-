#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

long long fact(long long n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	return n*fact(n-1);
}

double Computation(int n)
{
	double sum=0,x=1.5;
	for(int i=1;i<=n;i++)
	{
		sum+=(pow(x,i)/pow(x,n-i)*fact(n-i));
	}
	return round(sum*100)/100;
	//return sum;
}

bool isSmall(double t)
{
	return t<=25;
}

int main()
{
	int k,no_of_small=0,no_of_big=0;
	double sum=0;
	do
	{
		cout<<"Enter an integer value above 5 : ";
		cin>>k;
		if(k<=5)
		{
			cout<<"Invalid input, please try again...!"<<endl;
			continue;
		}
		cout<<"***********************************************"<<endl;
		cout<<"Terms generated : "<<k<<endl;
		for(int i=1;i<=k;i++)
		{
			double val = Computation(i);
			if(isSmall(val))
			{
				cout<<fixed<<setprecision(2)<<val<<"(S) ";
				no_of_small++;	
			}
			else
			{
				cout<<fixed<<setprecision(2)<<val<<"(B) ";
				no_of_big++;	
			}
			sum+=val;
		}
		cout<<endl;
		cout<<"Number of Bigs : "<<no_of_big<<endl;
		cout<<"Number of Smalls : "<<no_of_small<<endl;
		cout<<"Sum of Terms : "<<sum<<endl;
		cout<<"***********************************************"<<endl;
	}while(k<=5);
	return 0;
}