#include<iostream>
#include<queue>
#include<stack>
using namespace std;

float calculatePostfixExpr(string postfixExpr)
{
	//q to store input tokens
	queue<string> q;
	//For each token of postfixExpr
	for(int i=0;i<postfixExpr.length();i++)
	{
		//Convert character to string
		string op(1, postfixExpr[i]);
		//Push op onto queue
		q.push(op);
	}

	float val=0,x,y;
	//Stack to store operands
	stack<float> s;
	//Iterate untill q is empty()
	while(!q.empty())
	{
		string op=q.front();
		q.pop();
		//If digit then push onto stack
		if(isdigit(op[0]))
		{
			s.push(op[0]-'0');
		}
		//If it is operator
		else
		{
			//Pop() 2 operands from stack
			y=s.top();
            s.pop();
            x=s.top();
            s.pop();
            //Do operation as per the operator and push result onto stack
            switch(op[0])
            {
                case '+': s.push(x+y);break;
                case '-': s.push(x-y);break;
                case '*': s.push(x*y);break;
                case '/': s.push(x/y);break;
            }
		}
	}
	//top of stack contains final result
	return s.top();
}

int main()
{
	string postfixExpr;
	//User input
	cout<<"Enter postfix expression: ";
	cin>>postfixExpr;
	//Function calling
	cout<<calculatePostfixExpr(postfixExpr)<<endl;;
	return 0;
}