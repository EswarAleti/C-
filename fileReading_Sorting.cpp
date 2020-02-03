#include<iostream>
#include<fstream>
#define N 200
using namespace std;

class Sort_Search
{
	private:
		int arr1[N];
		int arr2[N];
	public:
		bool addToArray();
		int bubbleSort();
		int selectionSort();
		int linearSearch();
		int binarySearch();
};
bool Sort_Search::addToArray()
{
	//Opening file
	ifstream file;
	file.open("random.txt");
	if(!file)
	{
		cout<<"Error in opening a file"<<endl;
		return false;
	}
	
	int val, index=0;
	//Store each value of file into arrays
	while(file>>val)
	{
		arr1[index]=val;
		arr2[index]=val;
		index++;
	}
	file.close();
	//return true becasue file opened successfully
	return true;
}
//implementation of bubblesort
int Sort_Search::bubbleSort()
{
	int exchanges = 0;
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-i-1;j++)
		{
			//Increment exchanges by 1
			if(arr1[j]>arr1[j+1])
			{
				swap(arr1[j],arr1[j+1]);
				exchanges++;
			}
		}
	}
	return exchanges;
}
//Implementation of selection sort
int Sort_Search::selectionSort()
{
	int exchanges = 0;
	for(int i=0;i<N-1;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<N;j++)
		{
			if(arr2[minIndex]>arr2[j])
			{
				minIndex=j;
			}
		}
		//Increment exchanges by 1
		if(minIndex!=i)
		{
			swap(arr2[i],arr2[minIndex]);
			exchanges++;
		}
	}
	return exchanges;
}
int Sort_Search::linearSearch()
{
	int comp=0;
	for(int i=0;i<200;i++)
	{
		comp++;
		//If 869 found ten return comparisions
		if(arr1[i]==869)
		{
			return comp;
		}
	}
	return comp;
}
int Sort_Search::binarySearch()
{
	int comp=0;
	int low=0,high=99;
	while(low<=high)
	{
		//increment comparisions by 1
		comp++;
		int mid = (low+high)/2;
		//If 869 found then return number of comparisions
		if(arr1[mid]==869)
		{
			return comp;
		}
		//Go to left subarray
		else if(arr1[mid]>869)
		{
			high=mid-1;
		}
		//Go to right subarray
		else
		{
			low=mid+1;
		}
	}
	return comp;
}
int main()
{
	//creation of object
	Sort_Search obj;
	//function callings and printing the outputs
	bool doesFileOpened = obj.addToArray();
	if(doesFileOpened)
	{
		cout<<"Number of exchanges in bubble sort: "<<obj.bubbleSort()<<endl;
		cout<<"Number of exhanges in selection sort: "<<obj.selectionSort()<<endl;
		cout<<"Number of comparisions using linear search: "<<obj.linearSearch()<<endl;
		cout<<"Number of comparisions using binary search: "<<obj.binarySearch()<<endl;	
	}
}
