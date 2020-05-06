#include<iostream>
using namespace std;

int main()
{
	long long n,m;
	cin>>n>>m;
	long long i=1, max=n;
	while(n>0)
	{
		cout<<"Ram: "<<n<<" Ravan: "<<i<<endl;
		n=(n+m)<=max?(n+m):max;
		n-=i;
		i++;
	}
	cout<<i-1<<endl;
	return 0;
}