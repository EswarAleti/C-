#include<iostream>
using namespace std;
const int row = 10; 
const int col = 10; 

void displayMat(int mat[row][col])
{
	//for each row
	for(int i=0;i<row;i++)
	{
		//for each element of row
		for(int j=0;j<col;j++)
		{
			//print the element
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}


void transpose(int mat[row][col])
{
	//for half of the rows
	for(int i=0;i<row/2;i++)
	{
		//for each element
		for(int j=0;j<col;j++)
		{
			//swap corresponding values
			swap(mat[i][j],mat[row-1-i][col-1-j]);
		}
	}
}

int main()
{
	//matrix initialization
	int mat[][10] = {{1,7,4,0,9,4,8,8,2,4},
					 {5,5,1,7,1,1,5,2,7,6},
					 {1,4,2,3,2,2,1,6,8,5},
					 {7,6,1,8,9,2,7,9,5,4},
					 {3,1,2,3,3,4,1,1,3,8},
					 {7,4,2,7,7,9,3,1,9,8},
					 {6,5,0,2,8,6,0,2,4,8},
					 {6,5,0,9,0,0,6,1,3,8},
					 {9,3,4,4,6,0,6,6,1,8},
					 {4,9,6,3,7,8,8,2,9,1}};
	//function calling and output printing
	cout<<"Before transpose: "<<endl;
	displayMat(mat);
	transpose(mat);
	cout<<"After transpose: "<<endl;
	displayMat(mat);
	return 0;
}