#include<iostream>
using namespace std;

//Implementation of bubble sort
void sortAscendingOrder(int A[],int sA)
{
	for(int i=0;i<sA;i++)
	{
		for(int j=0;j<sA-1-i;j++)
		{
			//If previous element is larger than current element then swap
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}

//Implementation of bubblesort
void sortDescendingOrder(int A[],int sA)
{
	for(int i=0;i<sA;i++)
	{
		for(int j=0;j<sA-1-i;j++)
		{
			//If previous element is smaller than current element then swap
			if(A[j]<A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}

void displayArray(int A[], int sA)
{
	//Traverse array
	for(int i=0;i<sA;i++)
	{
		//Print element
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	//User input
	int sA;
	cout<<"Enter number of elements of array: ";
	cin>>sA;
	cout<<"Enter elements of array A: ";
	int A[sA];
	for(int i=0;i<sA;i++)
	{
		cin>>A[i];
	}

	//User choice for type of sorting
	char C;
	cout<<"Enter A for ascending order, D for descending order: ";
	cin>>C;

	//Print array
	cout<<"Before sorting: ";
	displayArray(A,sA);

	//Function calling and output printing
	if(C=='A')
	{
		sortAscendingOrder(A,sA);
		cout<<"After sorting in ascending order: ";
		displayArray(A,sA);
	}
	else if(C=='D')
	{
		sortDescendingOrder(A,sA);
		cout<<"After sorting in descending order: ";
		displayArray(A,sA);
	}
}