#include<iostream>
using namespace std;

int main()
{
	long long n,m;
	//User input
	cin>>n>>m;
	//Start day from 1
	long long i=1, max=n;
	//Till Ram has no arrows
	while(n>0)
	{
		//Add at most m arrows
		n=(n+m)<=max?(n+m):max;
		//Destory i arrows of ram
		n-=i;
		//Increment day by 1
		i++;
	}
	//Output
	cout<<i-1<<endl;
	return 0;
}