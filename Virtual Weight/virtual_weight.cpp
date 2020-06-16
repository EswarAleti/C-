#include<iostream>
#include<time.h>
using namespace std;

int virtual_weight(int n)
{
	int sum=0;
	while(n>0)
	{
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

char classify(int num, int cut_off)
{
	int vw = virtual_weight(num);
	return vw<=cut_off?'L':'H';
}

void countVW(int &counter)
{
	counter++;
}

int main()
{
	srand(time(0));
	int n,sum=0,count_low=0;
	do
	{
		cout<<"Enter an integer number between 5 and 20: ";
		cin>>n;
		if(n<5 || n>20)
		{
			cout<<"Invalid input, please try again...!"<<endl;
			continue;
		}
		cout<<"--------------------------------------------"<<endl;
		cout<<"The classifications of the numbers are: ";
		for(int i=0;i<n;i++)
		{
			int num = rand();
			cout<<num<<"("<<classify(num,15)<<") ";
			if(classify(num,15)=='L')
			{
				sum+=num;
				countVW(count_low);
			}
		}
		cout<<endl;
		cout<<"The number of low VW is: "<<count_low<<endl;
		cout<<"The number of high VW is: "<<n-count_low<<endl;
		cout<<"The sum of low VW numbers is: "<<sum<<endl;
		cout<<"--------------------------------------------"<<endl;

	}while(n<5 || n>20);

	return 0;
}