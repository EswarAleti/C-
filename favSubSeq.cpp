/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#define MAX 100001
#define DIV 1000000000
using namespace std;

long getNumberOfFavSubSeq(string str)
{
    long dp[MAX]={0};
    //lia is last index of a
    long lia,lib,lic; 
    lia=lib=lic=-1;
    long result=0;
    for(long i=0;i<str.length();i++)
    {
        //cout<<"Hi"<<endl;
        if(str[i]=='a')
        {
            dp[i]=1;
            if(lia==-1)
            {
                lia=i;
            }
            else
            {
                dp[i]+=2*dp[lia];
                lia=i;
            }
        }
        else if(str[i]=='b')
        {
            dp[i]=dp[lia];
            if(lib==-1)
            {
                lib=i;
            }
            else
            {
                dp[i]+=2*dp[lib];
                lib=i;
            }
        }
        else if(str[i]=='c')
        {
            dp[i]=dp[lib];
            if(lib==-1)
            {
                lic=i;
            }
            else
            {
                dp[i]+=2*dp[lic];
                lic=i;
            }
        }
        dp[i]%=DIV;
        if(str[i]=='c')
        {
            result = dp[i];
        }
    }
    return result;
}

int main()
{
    string str;
    cin>>str;
    cout<<getNumberOfFavSubSeq(str)<<endl;
    return 0;
}