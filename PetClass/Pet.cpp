#include<iostream>
#include "Pet.h"
using namespace std;

int main()
{
	//Object cration and function calling
	Pet petl;
	petl.PrintInfo();
	Pet pet2("Fluffy","cat",1);
	pet2.PrintInfo();
	Pet pet3("Sparky","hamster",0);
	pet3.PrintInfo();
}