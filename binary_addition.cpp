#include<iostream>
using namespace std;

string addFunction(string numberA, string numberB, int m, int base)
{
	string result="";
	int c=0;
	//Store last index of numberA in indexA
	int indexA=numberA.length()-1;
	//Store last index of numberA in indexA
	int indexB=numberB.length()-1;
	//Iterate untill both the strings finished
	while(indexA>=0 || indexB>=0)
	{
		//If theres is a bit in numberA then take it, 0 other 
		int a = (indexA>=0) ? numberA[indexA]-'0' : 0;
		//If theres is a bit in numberB then take it, 0 other 
		int b = (indexB>=0) ? numberB[indexB]-'0' : 0;
		//Find sum
		int sum = (a^b^c);
		//Find carry
		c = ((a & b) | (a & c) | (b & c));
		//Store the sum into result string
		result=char(sum+48)+result; 
		//Decrement both the indiecs
		indexA--;
		indexB--;
	}
	//If there is a carry then add append 1 to the front
	result=(c==1)?"1"+result:result; 
	return result;
}

int main()
{
	//Function calling
	cout<<addFunction("1001","100001101",4,2)<<endl;
	cout<<addFunction("1111","11111",5,2)<<endl;
	cout<<addFunction("1000","0100",4,2)<<endl;
	return 0;
}