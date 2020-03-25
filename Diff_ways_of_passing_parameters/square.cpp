#include<iostream>
using namespace std;

//n has value of x
int squareByValue(int n)
{
	//return square of n
	return n*n;
}

//reference to y
void squareByRef(int &n)
{
	//update n
	n=n*n;
}

//point to the z
void squareByPointer(int *n)
{
	//update value pointed by pointer
	*n = *n * *n;
}

int main()
{
	int x=5;
	//x will be passed
	cout<<"Square by Value: "<<squareByValue(x)<<endl;
	
	int y=6;
	//y will be passed
	squareByRef(y);
	cout<<"Square by Reference: "<<y<<endl;
	
	int z=7;
	//address should of z be passed
	squareByPointer(&z);
	cout<<"Square by Pointer: "<<z<<endl;
	return 0;
}