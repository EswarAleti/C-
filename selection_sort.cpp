#include<iostream>
using namespace std;

void selectio_sort(int arr[],int n)
{
	int min_index;
	for(int i=0;i<n-1;i++)
	{
		// Initially min_index is i
		min_index=i;
		for(int j=i+1;j<n;j++)
		{
			// If arr[j] is smaller than arr[min_index] then min_index updated to j
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
		}
		// Swap arr[i] and arr[min_index]
		swap(arr[i],arr[min_index]);
	}
}

int main()
{
	// Array declaration
	int arr[] = {36, 55, 17, 35, 63, 85, 12, 48, 3, 66};
	// Finding number of elements in array
	int n = sizeof(arr)/sizeof(int);
	// Print array elements before sorting
	cout<<"\nBefore sorting: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	// Function calling
	selectio_sort(arr,n);
	// Print array elements after sorting
	cout<<"\nAfter sorting: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}