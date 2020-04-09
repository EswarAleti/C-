#include<iostream>
//Including fstream to handle files
#include<fstream>
using namespace std;

int main()
{
	//Input stream to handle file
	ifstream infile("ABC.txt");
	//If file not exist then print a message and return
	if (!infile.is_open()) 
	{ 
  		cout << "file not found"; 
  		return 0;
    }
	//Line will store each line of the file 
	string line;
	//Initial count is 0
	int count=0;
	//Read each line
	while(getline(infile, line))
	{
		//Increment count by 1
		count++;
	}
	//closing file
	infile.close();
	//Print the output
	cout<<"Total number of lines: "<<count<<endl;
	return 0;
}
