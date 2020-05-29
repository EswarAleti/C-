#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;

int main()
{
	// Read file
	ifstream file("values.txt");
	string line;
	int row=0,col;
	// Array Initialization
	int arr[4][4];
	// For each line of file
	while(getline(file,line))
    {
    	col=0;
    	// Divide line with respect to comma and store into array
    	stringstream ss(line);
    	string value;
    	while(getline(ss, value, ','))
    	{
    		arr[row][col++] = stoi(value);
    	}
    	// Increment row by 1
    	row++;
    }
    // Close the file
    file.close();

    // For each row
    for(int i=0;i<row;i++)
    {
    	// Initial row_sum is 0
    	int row_sum=0;
    	// For each column
    	for(int j=0;j<col;j++)
    	{
    		// Add value to row_sum
    		row_sum += arr[i][j];
    	}
    	// Print output
    	cout<<"Row Total "<<i+1<<": "<<row_sum<<endl;
    }

    // For each column
    for(int j=0;j<col;j++)
    {
    	// Initial col_sum is 0
    	int col_sum=0;
    	// For each row
    	for(int i=0;i<row;i++)
    	{
    		// Add value to col_sum
    		col_sum += arr[i][j];
    	}
    	// Print output
    	cout<<"Col Total "<<j+1<<": "<<col_sum<<endl;
    }

    // Initial sum is 0
    int sum=0;
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    	{
    		// Add value to sum
    		sum+=arr[i][j];
    	}
    }
    // Find average and print it
    cout<<"Array Average: "<<sum/(row*col)<<endl;
	return 0;
}