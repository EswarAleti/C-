#include<iostream>
using namespace std;

//This function will return true if key existed in array B[]
bool isFound(int B[], int sB, int key)
{
	//Traverse array
	for(int i=0;i<sB;i++)
	{
		//If key found then return true
		if(B[i]==key)
		{
			return true;
		}
	}
	//execution come here if key not found in array B[]
	return false;
}

int arrayDiff(int A[], int B[], int sA, int sB)
{
	//travese array A[]
	for(int i=0;i<sA;i++)
	{
		//If A[i] found in B[] then eliminate A[i]
		if(isFound(B,sB,A[i]))
		{
			//move elements after i to left
			for(int j=i;j<sA-1;j++)
			{
				A[j]=A[j+1];
			}
			//reduce size of A by 1
			sA--;
			//reduce index i by 1
			i--;
		}
	}
	//return size of array A
	return sA;
}

int main()
{
	//User input
	int sA;
	cout<<"Enter sA: ";
	cin>>sA;
	cout<<"Enter elements of A: ";
	int A[sA];
	for(int i=0;i<sA;i++)
	{
		cin>>A[i];
	}

	int sB;
	cout<<"Enter sB: ";
	cin>>sB;
	cout<<"Enter elements of B: ";
	int B[sB];
	for(int i=0;i<sB;i++)
	{
		cin>>B[i];
	}

	//Function calling and output printing
	cout<<"Array A after eliminates from A all elements that appear also in B: ";
	sA = arrayDiff(A,B,sA,sB);
	for(int i=0;i<sA;i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}