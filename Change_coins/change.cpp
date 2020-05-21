/*
1 nickel = 5 pennies
1 dime = 10 pennies
1 quarter = 25 pennies
1 dollar = 100 pennies
*/
#include<iostream>
using namespace std;

void ExactChange(double userTotal, int& numDollars, int& numQuarters, int& numDimes, int& numNickels, int& numPennies)
{
	numDollars = userTotal/100;
	userTotal = int(userTotal)%100;
	numQuarters = userTotal/25;
	userTotal = int(userTotal)%25;
	numDimes = userTotal/10;
	userTotal = int(userTotal)%10;
	numNickels = userTotal/5;
	numPennies = int(userTotal)%5;
}

int main()
{
	double userTotal;
	int numDollars, numQuarters, numDimes, numNickels, numPennies;
	// User input
	cout<<"Enter input: ";
	cin>>userTotal;
	// Function calling
	ExactChange(userTotal,numDollars, numQuarters, numDimes, numNickels, numPennies);
	// Output printing
	if(numDollars>0)
	{
		// If 1 dollor print singular, plural otherwise
		numDollars==1 ? cout<<numDollars<<" dollar"<<endl:cout<<numDollars<<" dollars"<<endl;
	}
	if(numQuarters>0)
	{
		numQuarters==1 ? cout<<numQuarters<<" quarter"<<endl:cout<<numQuarters<<" quarters"<<endl;
	}
	if(numDimes>0)
	{
		numDimes==1 ? cout<<numDimes<<" dime"<<endl:cout<<numDimes<<" dimes"<<endl;
	}
	if(numNickels>0)
	{
		numNickels==1 ? cout<<numNickels<<" nickel"<<endl:cout<<numNickels<<" nickels"<<endl;
	}
	if(numPennies>0)
	{
		numPennies==1 ? cout<<numPennies<<" penny"<<endl:cout<<numPennies<<" pennies"<<endl;
	}
	return 0;
}