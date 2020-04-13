#include<iostream>
#include<stdlib.h>
using namespace std;

//Linked list node
struct node
{
	int data;
	struct node *next;
};
typedef struct node LLNode;

//Initializing head and tail to null
LLNode *head = NULL;
LLNode *tail = NULL;

//This function append new node to the end of the list
void appendAtLast(int val)
{
	//Creation of new node
	LLNode *newNode = (LLNode *)malloc(sizeof(LLNode));
	newNode->data=val;
	newNode->next=NULL;

	//If list is empty then make newNode as head and tail
	if(head==NULL)
	{
		head=newNode;
		tail=newNode;
		return;
	}
	//If list is not empty then append it next to tail
	tail->next=newNode;
	//Make newNode as tail
	tail=newNode;
}

//Function to display elements of linked list
void display()
{
	cout<<"Elements of linkedlist are: ";
	LLNode *temp=head;
	//Iterate toill end of list
	while(temp)
	{
		cout<<temp->data<<" ";
		//Move to next node
		temp=temp->next;
	}
	cout<<endl;
}

void insertAt(int val, int index)
{
	//Creat a new node with given parameter value
	LLNode *newNode = (LLNode *)malloc(sizeof(LLNode));
	newNode->data=val;
	newNode->next=NULL;

	//If index is 0 then insert it before head and make it head
	if(index==0)
	{
		newNode->next=head;
		head=newNode;
		return;
	}

	int i;
	LLNode *temp=head;
	//Move till we found position before the index 
	for(i=0;temp->next && i<index-1;i++)
	{
		temp=temp->next;
	}
	//Index out of range case
	if(i!=index-1)
	{
		cout<<"Index out of range"<<endl;
		return; 
	}
	//Insert
	newNode->next=temp->next;
	temp->next=newNode;
}

void deleteAt(int index)
{
	//If list is empty
	if(head==NULL)
	{
		cout<<"List is empty, so deletion not possible"<<endl;
		return;
	}
	//Delete head
	if(index==0)
	{
		LLNode *temp=head;
		head=head->next;
		free(temp);
		return;
	}
	int i;
	LLNode *temp=head;
	//Move till we found position before the index 
	for(i=0;temp && i<index-1;i++)
	{
		temp=temp->next;
	}
	//Index out of range case
	if(temp->next==NULL)
	{
		cout<<"Index out of range"<<endl;
		return; 
	}
	//Delete the node
	LLNode *dummy=temp->next;
	temp->next = temp->next->next;
	free(dummy);
}

//Menu is for user functionality
//menu() return 0 if user want to exit, 1 otherwise
int menu()
{
	cout<<"1. Append at the end of list"<<endl;
	cout<<"2. Insert"<<endl;
	cout<<"3. Delte"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Your choice: ";
	int choice,val,index;
	cin>>choice;
	switch(choice)
	{
		case 1:
				cout<<"Enter value to append: ";
				cin>>val;
				appendAtLast(val);
				display();
				break;
		case 2:
				cout<<"Enter value to insert: ";
				cin>>val;
				cout<<"Enter index to insert: ";
				cin>>index;
				insertAt(val,index);
				display();
				break;
		case 3:
				cout<<"Enter index to delte: ";
				cin>>index;
				deleteAt(index);
				display();
				break;
		case 4:
				return 0;
	}
	return 1;
}

int main()
{
	//Iterate till user wants to exit
	while(menu()==1);
	return 0;
}