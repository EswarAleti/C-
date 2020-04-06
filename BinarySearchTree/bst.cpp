#include<iostream>
using namespace std;

//Tree node creation
struct node
{
	string name;
	float weight;
	struct node *left , *right;
};
typedef struct node BSTNode;

BSTNode* getNewNode(string name , float weight)
{
	BSTNode *newNode = new BSTNode;
	newNode -> name = name;
	newNode -> weight = weight;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}
BSTNode* insert(BSTNode* t , string name , float weight)
{
	//t is null
	if(t == NULL)
	{
		//Create a new node with name and weight and assign it to t
		t = getNewNode(name , weight);
	}
	//If name of t node is greater than name then go to left sub tree
	else if(name < t -> name)
	{
		t -> left = insert(t -> left , name , weight);
	}
	//If name of t node is smaller than name then go to right sub tree
	else
	{
		t -> right = insert(t -> right , name , weight);
	}
	//return t
	return t;
}

void preOrder(BSTNode* t)
{
	if(t)
	{
		//t Left Right
		cout<<t -> name<<", ";
		preOrder(t -> left);
		preOrder(t -> right);
	}
}

void inOrder(BSTNode* t)
{
	if(t)
	{
		//Left t Right
		inOrder(t -> left);
		cout<<t -> name<<", ";
		inOrder(t -> right);
	}
}

void PostOrder(BSTNode* t)
{
	if(t)
	{
		//Left Right t
		PostOrder(t -> left);
		PostOrder(t ->right);
		cout<<t -> name<<", ";
	}
}

//Returns maximum among a and b
int max(int a, int b)
{
	return a>b?a:b;
}

int height(BSTNode* t)
{
	if(t!=NULL)
	{
		//Height of left subtree
		int left = height(t->left);
		//Height of right subtree
		int right= height(t->right);
		//Return 1+maximum height aomng left and right subtree
		return 1+max(left,right);
	}
	return 0;
}

int numberOfLeaves(BSTNode* t)
{
	if(t!=NULL)
	{
		//If node is leaf then count as 1 and goto left and right subtrees
		if(t->left==NULL && t->right==NULL)
		{
			return 1+numberOfLeaves(t->left)+numberOfLeaves(t->right);
		}
		//Calculate leaves of left and right subtrees and add those
		return numberOfLeaves(t->left)+numberOfLeaves(t->right);
	}
	return 0;
}

BSTNode* search(BSTNode* t, string name)
{
	//If node is null then return null
	if(t==NULL)
	{
		return NULL;
	}
	//If node found then return that node
	if(t->name==name)
	{
		return t;
	}
	//If name is greater than name of current node then goto right subtree
	if(t->name<name)
	{
		return search(t->right,name);
	}
	//Else goto left subtree
	return search(t->left,name);
}

string firstName(BSTNode *t)
{
	if(t!=NULL)
	{
		//If it is leaf then return name
		if(t->left==NULL)
		{
			return t->name;
		}
		//Go to left most node
		return firstName(t->left);
	}
	return "";
}

int main()
{
	//Initializatiion of t node
	BSTNode *root = NULL;
	//User inputs
	string name;
	float weight;	
	cout<<"Enter details:"<<endl;
	for(int i=0;i<15;i++)
	{
		cin>>name;
		cin>>weight;
		//Inserting a new node with given name and weight to bst
		root=insert(root,name,weight);
	}

	//Traversals
	cout<<"\n\nPreorder Traversal :";
	preOrder(root);
	cout<<"\n\nInorder Traversal :";
	inOrder(root);
	cout<<"\n\nPostorder Traversal :";
	PostOrder(root);
	
	//Function calling, Note that here height of single node is 1
	cout<<"\n\nHeight of tree: "<<height(root)<<endl;
	
	cout<<"\nNumber of leaves of tree: "<<numberOfLeaves(root)<<endl;
	
	//Searching a node
	BSTNode* targetNode = search(root,"Srinivas");
	if(targetNode==NULL)
	{
		cout<<"\nName Not exist"<<endl;
	}
	else
	{
		cout<<"\nName exist and weight is: "<<targetNode->weight<<endl;
	}

	//Finding first name
	cout<<"\nFirst name in alphabetical order: "<<firstName(root)<<endl;
	return 0;
}