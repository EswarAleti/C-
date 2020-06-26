#include<iostream>
#include<time.h>
#define LOWER_BOUND 3
using namespace std;

// Displaying array
void display(int arr[])
{
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

// Insertionsort implementation
void insertionsort(int arr[], int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int key = arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

// Partition implementation
int partition(int arr[], int low, int high)
{
	if(low<high)
	{
		int i = low-1;
		int pivot = arr[high];
		for(int j=low;j<high;j++)
		{
			if(arr[j]<pivot)
			{
				swap(arr[++i],arr[j]);
			}
		}
		swap(arr[++i],arr[high]);
		return i;
	}
	return -1;
}

void quicksort(int arr[], int low, int high)
{
	// If low<high and partition has atleast LOWER_BOUND number of elements
	if(low<high && high-low+1>=LOWER_BOUND)
	{
		int r = partition(arr,low,high);
		quicksort(arr,low,r-1);
		quicksort(arr,r+1,high);
	}
}

int main()
{
	int arr[10];
	srand(time(NULL));
	// Generating 10 random integers
	for(int i=0;i<10;i++)
	{
		arr[i]=rand()%100;
	}
	// Functiona calling
	cout<<"Array before sorting"<<endl;
	display(arr);
	quicksort(arr,0,9);
	insertionsort(arr,9);
	cout<<"Array after sorting"<<endl;
	display(arr);
	return 0;
}