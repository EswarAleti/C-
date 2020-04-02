#include<iostream>
#include <iomanip> 
using namespace std;

//soup_volume function definition with diameter and height as parameter
float soup_volume(float d, float h)
{
	//Funding radius
	float r = d/2;
	//Finding volume of the cylinder
	float volume_cylinder = 3.14159*(r*r)*h;
	//Finding volumer of soup which is 95% of the volume of cylinder
	float volume_soup = 0.95*volume_cylinder;
	//return the volume of soup
	return volume_soup;
}

int main()
{
	//User input
	float diameter,height;
	cout<<"Enter diameter of the cylinder: ";
	cin>>diameter;
	cout<<"Enter height of the cylinder: ";
	cin>>height;
	//Function calling and storing the result
	float soup_vol=soup_volume(diameter,height);
	//Printing result upto 2 decimals using setprecision()
	cout <<" Volume of soup in can is: "<<fixed << setprecision(2) << soup_vol << endl;
	return 0;
}