#include<iostream>
#include<string>
using namespace std;

int main()
{
	string phoneNo;
	cout<<"Please enter a phone number: ";
	//User input
	getline(cin,phoneNo);

	string digits="";
	//Store digits of phoneNo into digits
	for(int i=0;i<phoneNo.length();i++)
	{
		char digit=phoneNo[i];
		//If it is digit then store
		if(isdigit(digit))
		{
			digits.push_back(digit);
		}
	}
	//If number of digits less than 10
	if(digits.length()<10)
	{
		cout<<"The phone number must have at least 10 digits"<<endl;
		return 0;
	}
	string formattedPhoneNo="(";
	for(int i=0;i<10;i++)
	{
		formattedPhoneNo.push_back(digits[i]);
		//After appending digit at index 2 apend ") "
		if(i==2)
		{
			formattedPhoneNo.push_back(')');
			formattedPhoneNo.push_back(' ');
		}
		//After appending digit at index 5 apend "-"
		if(i==5)
		{
			formattedPhoneNo.push_back('-');
		}
	}
	//Print output
	cout<<"The properly formatted number is "<<formattedPhoneNo<<endl;
	return 0;
}