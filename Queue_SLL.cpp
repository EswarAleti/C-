#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Node;
typedef Node* NodePtr;

class Node
{
	public:
		int Number;
		NodePtr next;
		Node() { Number = 0; next = NULL; }
		Node(int n) { Number = n; next=NULL;}
};

class Queue
{
	private:
		int currSize;
		int maxSize;
		NodePtr front;
		NodePtr rear;
	public:
		Queue() { currSize = maxSize = 0; front = NULL; rear = NULL; }
		Queue(int size) { currSize = 0; maxSize = size; front = NULL; rear = NULL; }
		bool push(int n);
		bool pop();
		bool full();
		bool empty();
		bool destroy();
		bool init();
};

bool Queue::push(int n)
{
	if (full())
	{
		cout << "Queue is full- Can't add anymore value to the queue" << endl;
		return false;
	}
	// If queue is empty
	if(front==NULL)
	{
		// Front and rear is same when queue has single element
		front = new Node(n);
		rear = front;
		// Increment size
		currSize++;
		return true;
	}
	// Insert after rear
	rear->next = new Node(n);
	rear = rear->next;
	// Increment size
	currSize++;
	return true;
}

bool Queue::pop()
{
	if (empty())
	{
		cout << "Queue is empty Can't take any value out of queue because it is empty" << endl;
		return false;
	}
	// Delete front
	NodePtr p = front;
	front = front->next;
	delete p;
	// Decrement size by 1
	currSize--;
	return true;
}

bool Queue::full()
{
	return (currSize == maxSize);
}

bool Queue::empty()
{
	return (currSize == 0);
}

bool Queue::destroy()
{
	NodePtr curr = front;
	NodePtr temp;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	return true;
}

bool Queue::init()
{
	destroy();
	front = NULL;
	rear = NULL;
	currSize = 0;
	return true;
}

int main()
{
	Queue queue(5);
	queue.push(10);
	cout << "10 is in the queue" << endl;
	queue.push(20);
	cout << "20 is in the queue" << endl;
	queue.push(30);
	cout << "30 is in the queue" << endl;
	queue.push(40);
	cout << "40 is in the queue" << endl;
	queue.push(50);
	cout << "50 is in the queue" << endl;
	queue.push(60);

	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
	queue.pop();
}