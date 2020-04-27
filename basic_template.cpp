#include<iostream>
using namespace std;

/*int add(int a, int b)
{
	return a+b;
}

float add(float a, float b)
{
	return a+b;
}

double add(double a, double b)
{
	return a+b;
}*/

template<typename T>
T add(T a, T b)
{
	return a+b;
}

int main()
{
	int a=10;
	int b=20;
	cout<<add<int>(a,b)<<endl;
	float x=15.3;
	float y=14.2;
	cout<<add<float>(x,y)<<endl;
	double m=18.2;
	double n=19.4;
	cout<<add<double>(m,n)<<endl;
	return 0;
}