#include <string.h>
#include <iostream>
using namespace std;

int total;
struct Student
{
	string name;
	int id;
	int *marks;
};

// Declarations of various functions
void inputStudent(Student* ptr, int);
void outputStudent(Student* ptr, int);
int highest(int*,int);
int lowest(int*,int);
double average(int*,int);

int main ()
{
	// instantiating an STUDENT object
	Student stu; 
	// defining a pointer for the object
	Student* stuPtr = &stu;

	// Input for number of marks that user wants to enter
	int noOfMarks;
	cout<<"Enter number of marks you would like to enter: ";
	cin>>noOfMarks;
	
	// initializing the object
	inputStudent(&stu,noOfMarks);
	// printing the object
	outputStudent(&stu,noOfMarks);
	return 0;

}

// Function to take input from user
void inputStudent(Student* ptr, int noOfMarks)
{
	cout <<"Please enter a name: ";
	cin >>ptr->name;
	cout <<"Please enter an id: ";
	cin >>ptr->id;
	// Dynamically create array
	ptr->marks = new int[noOfMarks];
	// Input marks
	for(int i=0;i<noOfMarks;i++)
	{
		cout <<"Please enter a mark: ";
		cin >>ptr->marks[i];	
	}
}

void outputStudent(Student* ptr, int noOfMarks)
{
	// Output
	cout<<"Student info:"<<endl;
	cout<<"Name:"<<ptr->name <<endl;
	cout<<"Id:"<<ptr->id <<endl;
	// Output marks
	for(int i=0;i<noOfMarks;i++)
	{
		cout <<"Mark "<<i+1<<":"<<ptr->marks[i]<<endl;
	}
	cout <<"Highest marks:" <<highest(ptr->marks, noOfMarks)<<endl;
	cout <<"Lowest marks:" <<lowest(ptr->marks, noOfMarks)<<endl;
	cout <<"Average marks:" <<average(ptr->marks, noOfMarks)<<endl;
}
//function for highest marks in array
int highest(int* arr, int noOfMarks)
{
	int max=arr[0];
	for(int i=1;i<noOfMarks;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
//function for Lowest marks in array
int lowest(int* arr, int noOfMarks)
{
	int min=arr[0];
	for(int i=1;i<noOfMarks;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	return min;
}
//function for Average marks in array
double average(int *arr, int noOfMarks)
{
	double sum=0;
	for(int i=0;i<noOfMarks;i++)
	{
		sum+=arr[i];
	}
	return sum/noOfMarks;
}