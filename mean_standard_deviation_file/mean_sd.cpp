#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cmath>
using namespace std;

double count_no_data_items()
{
	double count=0;
	string line;
	ifstream infile("prices.txt");
	while(getline(infile,line))
	{
		count++;
	}
	infile.close();
	return count;
}

void read_data(double *arr)
{
	int index=0;
	ifstream infile("prices.txt");
	while(infile>>*(arr+index))
	{
		index++;
	}
	infile.close();
}

double find_mean(double *arr, double n)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+= *(arr+i);
	}
	double mean = sum/n;
	return mean;
}

double find_sd(double *arr, double n)
{
	double mean = find_mean(arr,n);
	double square_diff_sum = 0;
	for(int i=0;i<n;i++)
	{
		double diff = *(arr+i) - mean;
		square_diff_sum+=(diff*diff);
	}
	double sd = sqrt((double)(square_diff_sum/n));
	return sd;
}

int main()
{
	double no_lines = count_no_data_items();
	double *arr = (double *)malloc(sizeof(double)*no_lines);
	read_data(arr);
	cout<<fixed<<"Mean: "<<find_mean(arr,no_lines)<<endl;
	cout<<fixed<<"Standard Deviation: "<<find_sd(arr,no_lines)<<endl;
	return 0;
}