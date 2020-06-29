#include <iostream>
#include<sstream>
#include "stack.h"
using namespace std;

double compute(string postfix_notation)
{
	Stack<double> s;
	double x,y;
	string word; 
	// to split the strng with respect to white spaces
	istringstream ss(postfix_notation);
	do 
	{ 
		if(ss.eof())
		{
			break;
		}
		//store each word  
		ss >> word;
		//If operatos
		if(word=="+" || word=="-" || word=="*" || word=="/")
		{
			if(s.isEmpty())
        	{
        		cout<<"Error: Too many operators"<<endl;
        		return false;
        	}
            y=s.top();
            s.pop();
            if(s.isEmpty())
        	{
        		cout<<"Error: Too many operators"<<endl;
        		return false;
        	}
            x=s.top();
            s.pop();
            switch(word[0])
            {
                case '+': 
                		s.push(x+y);
                		break;
                case '-': 
                		s.push(x-y);
                		break;
                case '*': 
                		s.push(x*y);
                		break;
                case '/': 
                		if(y==0)
                		{
                			cout<<"Error: Division by zero"<<endl;
                			return false;
                		}
                		s.push(x/y);
                		break;
            }	
		}
		else
		{
			//stod() is to convert string to double
			s.push(stod(word));
		}
    }while(ss); 
    
    //If more operands left
    if(s.size()>1)
    {
    	cout<<"Error: Too many operands"<<endl;
    	return 0;
    }
    // Return the result
    return s.top();
}
int main()
{
	string postfix_notation;
	cout<<"Enter postfix expression to evaluate: ";
	getline(cin,postfix_notation);
	cout<<"Result: "<<compute(postfix_notation)<<endl;
	return 0;
}