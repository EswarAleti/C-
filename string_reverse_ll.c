#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Node definiton
struct node
{
	char data;
	struct node *next;
};

//head and tail pointers
struct node *head=NULL;
struct node *tail=NULL;

//This will append a node to end of list
void append(char val)
{
	//Creation of new node
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=NULL;

	//If head is empty then make new_node as head and tail
	if(head==NULL)
	{
		head=new_node;
		tail=new_node;
		return;
	}
	//If list is not emoty then insert new_ndoe next to the tail
	tail->next=new_node;
	tail=new_node;
}

//This will print reverse order of linkedlist
void reverse(struct node *temp)
{
	//If node is not null
	if(temp!=NULL)
	{
		//Call reverse() by passing next node
		reverse(temp->next);
		//Print the data
		printf("%c",temp->data);
	}
}

int main()
{
	char *a = NULL;
	int read;
	size_t len;
	printf("Enter input (Press Enter key 2 times to stop giving input):\n");
	//User input untill user press Enter key 2 times
	while((read = getline(&a, &len, stdin))!=1)
	{
		//append each character to the linked list
		for(int i=0;i<read;i++)
		{
			append(a[i]);
		}
	}
	//Call reverse() with head as parameter
	printf("Reverse order:");
	reverse(head);
    return 0;
}