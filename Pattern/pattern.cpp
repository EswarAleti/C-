#include<iostream>
using namespace std;

int main()
{
	int numRows;
	int numColumns;
	int currentRow;
	int currentColumn;
	char currentColumnLetter;

	cin>>numRows;
	cin>>numColumns;
	
	//For each row
	for(int currentRow=1;currentRow<=numRows;currentRow++)
	{
		//For each column letter
		for(char currentColumnLetter='A';currentColumnLetter<'A'+numColumns;currentColumnLetter++)
		{
			//Print current row and current letter
			cout<<currentRow<<currentColumnLetter<<" ";
		}
	}
	return 0;
}