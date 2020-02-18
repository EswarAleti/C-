#include <iostream>
#include <map> 
using namespace std;

void findUnique(long arr[], long N)
{
    map<long, long> mapp;
    for(long i=0;i<2*N+2;i++)
    {
        mapp[arr[i]]++;
    }
    long res[2],index=0;
    map<long,long> ::iterator it;
	for(it=mapp.begin();it!=mapp.end();it++)
	{
		//cout<<(*it).first<<" "<<(*it).second<<endl;
		if((*it).second%2==1)
		{
			//cout<<"Success"<<endl;
			res[index++]=(*it).first;
		}
	}
    if(res[0]<res[1])
    {
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    else
    {
        cout<<res[1]<<" "<<res[0]<<endl;
    }
}

int main() {
	//code
	int T;
	long N;
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    long arr[2*N+2];
	    for(long i=0;i<2*N+2;i++)
	    {
	        cin>>arr[i];
	    }
	    findUnique(arr,N);
	}
	return 0;
}
