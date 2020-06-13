#include<iostream>
using namespace std;

int main(int argc, char **argv)
{
	int no_of_symbol,no_of_moves;
	no_of_symbol = atoi(argv[1]);
	no_of_moves = atoi(argv[2]);
	int line=0,first=0;
	while(first+no_of_moves<10)
	{
		int no_of_symbol_per_line=0;
		for(int i=0;i<line*no_of_moves;i++)
		{
			no_of_symbol_per_line++;
			cout<<"*";
		}
		first=no_of_symbol_per_line+1;
		for(int i=0;i<no_of_symbol && no_of_symbol_per_line<10;i++)
		{
			no_of_symbol_per_line++;
			cout<<"#";
		}
		for(int i=no_of_symbol_per_line;i<10;i++)
		{
			cout<<"*";
		}
		cout<<endl;
		line++;	
	}
	return 0;
}