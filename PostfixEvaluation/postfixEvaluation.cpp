#include<iostream>
#include<sstream>
using namespace std;

struct node
{
	double data;
	struct node *next;
};

class Stack
{
	private:
		struct node *top;
		double size;
	public:
		Stack()
		{
			top=NULL;
			size=0;
		}
		void push(double val);
		bool pop();
		bool isEmpty();
		double topOfStack();
		double sizeOfStack();
};

void Stack::push(double val)
{
	//Increment size by 1
	size++;

	//create new Node
	struct node *newNode=new node;
	newNode->data=val;
	newNode->next=NULL;

	//Append to front of list
	newNode->next=top;
	top=newNode;
}

bool Stack::pop()
{
	//If stack empty
	if(isEmpty())
	{
		return false;
	}
	//Decrement size by 1
	size--;
	//Delete top
	struct node *temp=top;
	top=top->next;
	free(temp);
	return true;
}

bool Stack::isEmpty()
{
	return top==NULL;
}

double Stack::topOfStack()
{
	//If stack is not empty
	if(!isEmpty())
	{
		return top->data;
	}
	return -9999;
}

double Stack::sizeOfStack()
{
	return size;
}

bool evaluateExpression(string expr, double *result)
{
	Stack s;
	double x,y;
	string word; 
	// to split the strng with respect to white spaces
	istringstream ss(expr);
	do 
	{ 
		//store each word  
		ss >> word;
		//If word is = then stop
		if(word=="=")
		{
			break;
		}

		//If operatos
		if(word=="+" || word=="-" || word=="*" || word=="/")
		{
			if(s.isEmpty())
        	{
        		cout<<"Error: Too many operators"<<endl;
        		return false;
        	}
            y=s.topOfStack();
            s.pop();
            if(s.isEmpty())
        	{
        		cout<<"Error: Too many operators"<<endl;
        		return false;
        	}
            x=s.topOfStack();
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
    if(s.sizeOfStack()>1)
    {
    	cout<<"Error: Too many operands"<<endl;
    	return false;
    }
    //Store top of stack into result variable
    *result=s.topOfStack();
    return true;
}

int main()
{
	Stack s;
	string expr;
	double result=0;
	while(true)
	{
		getline(cin,expr);
		//If user enters zero then break the loop
		if(expr=="zero")
		{
			break;
		}
		cout<<expr<<" ";
		//If expression is valid then print output
		//value of expresion stores in result since we passed address of result
		if(evaluateExpression(expr,&result))
		{
			cout<<result<<endl;
		}
	}
	return 0;
}