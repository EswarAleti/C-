#include<iostream>
using namespace std;

bool isPalindrome(string str)
{
	int length = str.length();
	for(int i=0;i<length/2;i++)
	{
		//If str[i] is Uppercase letter then convert it to Lowercase by adding 32
		if(str[i]>=65 && str[i]<=90)
		{
			str[i]=str[i]+32;	
		}
		//If str[lenght-1-i] is Uppercase letter then convert it to Lowercase by adding 32
		if(str[length-1-i]>=65 && str[length-1-i]<=90)
		{
			str[length-1-i]=str[length-1-i]+32;
		}
		//If characters doesn't match then return false
		if(str[i]!=str[length-1-i])
		{
			return false;
		}
	}
	//Execution comes here only when str is a palindrome
	return true;
}

int main()
{
	//Function calling
	//If output is 1 then it is a palindrome
	//If output is 0 then it is not a palindrome
	cout<<"Madam: "<<isPalindrome("Madam")<<endl;
	cout<<"abBa: "<<isPalindrome("abBa")<<endl;
	cout<<"22: "<<isPalindrome("22")<<endl;
	cout<<"67876: "<<isPalindrome("67876")<<endl;
	cout<<"444244: "<<isPalindrome("444244")<<endl;
	cout<<"trYmeuemyRT: "<<isPalindrome("trYmeuemyRT")<<endl;
	return 0;
}