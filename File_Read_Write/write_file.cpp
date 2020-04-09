#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//Output stream to write file
	//Here ios_base::app used to append input data to existed data in file
	//You can remove if you want to overwrite existing data
	ofstream outfile("output.txt",ios_base::app);
	
	//User input
	string data;
	cout<<"Enter input: ";
	getline(cin,data);
	//Writing data
	outfile<<data;
	//Closing file
	outfile.close();
	return 0;
}
