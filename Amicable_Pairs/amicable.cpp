#include<iostream>
#include<math.h>
using namespace std;

//Function to find factorsum
long factorSum(long n)
{
	//sum is intialized to 1 because 1 is factor of every numebrs
	long sum=1;
	//Iterate from 2 to square root of n
	for(int i=2;i<=sqrt(n);i++)
	{
		//If i is a factor of n
		if(n%i==0)
		{
			//49/7 = 7 then add 7 only once
			if(n/i==i)
			{
				sum+=i;
			}
			//Add 2 factors
			else
			{
				sum+=(n/i + i);
			}
		}
	}
	//return sum
	return sum;
}

int main()
{
	long count=0,num=2;
	//Iterate until 45 Amicable pair were found
	while(count<45)
	{
		//find factorsum of num and store in variable sum1
		long sum1 = factorSum(num);
		//find factorsum of sum1 and store in variable sum2
		long sum2 = factorSum(sum1);
		//num!=sum1 becasue factorSum(28)=28 but 28 is not Amicable pair
		//If num is eqaul to sum2 then num, sum1 are Amicable pair
		if(num!=sum1 && num==sum2)
		{
			cout<<num<<" "<<sum1<<endl;
			//next num starts at sum1
			num=sum1;
			//increment the Amicable paris counts
			count++;
		}
		num++;
	}
	return 0;
}