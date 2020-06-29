#include<iostream>
using namespace std;

template <class T>
class Stack
{
	T *list;
	int topIndex;
	int maxSize;

	public:
		Stack(int n=100)
		{
			maxSize=n;
			list = new T[maxSize];
			topIndex=-1;
		}
		void push(T input);
		T top();
		void pop();
		bool isEmpty();
		int size();
		// Destructor
		~Stack()
		{
			delete[] list;
		}
};

template <class T>
void Stack<T>::push(T t)
{
	// cout<<"Pushing: "<<t<<endl;
	if(topIndex==maxSize-1)
	{
		cout<<"Overflow";
		return;
	}
	list[++topIndex]=t;
}

template <class T>
T Stack<T>::top()
{
	if(isEmpty())
	{
		cout<<"Stack is empty";
		return -1;
	}
	// cout<<"Top: "<<list[topIndex]<<endl;
	return list[topIndex];	
}

template <class T>
void Stack<T>::pop()
{
	if(isEmpty())
	{
		cout<<"Underflow";
		return;
	}
	// cout<<"Popping"<<endl;
	topIndex--;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return topIndex==-1;
}

template<class T>
int Stack<T>::size()
{
	return topIndex+1;
}