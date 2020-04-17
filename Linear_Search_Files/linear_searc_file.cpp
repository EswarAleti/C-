#include<iostream>
#include<fstream>
using namespace std;

bool SearchList(int stdList [],unsigned numElems,int searchValue,unsigned &foundIndex)
{
	//For each element of stdList[]
	for(int i=0;i<numElems;i++)
	{
		//If value found
		if(stdList[i]==searchValue)
		{
			//set index
			foundIndex=i+1;
			//return true
			return true;
		}
	}
	//Execution comes here if value not found
	return false;
}

int main()
{
	//Open LSStandard.txt file
	ifstream infile1("LSStandard.txt");
	//Store file content into stdList[]
	int stdList[100];
	//Initial number of elements is 0
	unsigned numStdElems=0;
	//Read each element int stdList[]
	while(infile1>>stdList[numStdElems])
	{
		//Increment number of elements by 1
		numStdElems++;
	}
	//Close the file
	infile1.close();

	//Open LSTest.txt
	ifstream infile2("LSTest.txt");
	//Store file content into testList[]
	int testList[50];
	//Initial number of elements is 0
	unsigned numTestElems=0;
	//Read each element into testList[]
	while(infile2>>testList[numTestElems])
	{
		//Increment number of elements by 1
		numTestElems++;
	}
	//close file
	infile2.close();

	//Search each elements in testList[]
	for(int i=0;i<numTestElems;i++)
	{
		//Declare foundIndex to -1
		unsigned foundIndex=-1;
		//Function calling
		bool val = SearchList(stdList,numStdElems,testList[i],foundIndex);
		//Output
		val?cout<<"Number "<<i+1<<" ("<<testList[i]<<") was located at index "<<foundIndex<<endl:cout<<"Number "<<i+1<<" ("<<testList[i]<<") was not in the file"<<endl;
	}
	return 0;
}