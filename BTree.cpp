#include<iostream>
using namespace std;

class Node
{
	public:
		Node* left;
		Node* right;
		int key;
		Node(int val)
		{
			key=val;
			left=NULL;
			right=NULL;
		}
};

class BTree
{
	Node* root;
	public:
		BTree()
		{
			root=NULL;
		}
		void setRoot(Node* t);
		int CountLeaves() const;
		int CountLeaves(Node* t) const;
};

int BTree::CountLeaves() const
{
	return CountLeaves(root);
}

int BTree::CountLeaves(Node* t) const
{
	// If tree is empty return 0
	if(t==NULL)
	{
		return 0;
	}
	// If t is leaf then return 1
	if(t->left==NULL && t->right==NULL)
	{
		return 1;
	}
	// Find leaves of left subtree and right subtree and add them
	return CountLeaves(t->left)+CountLeaves(t->right);
}

void BTree::setRoot(Node* t)
{
	root=t;
}

int main()
{
	// Creating tree as per the question
	Node* t=new Node(2);
	t->left = new Node(7);
	t->right = new Node(5);
	t->left->left = new Node(2);
	t->left->right = new Node(6);
	t->left->right->left = new Node(5);
	t->left->right->right = new Node(11);
	t->right->right = new Node(9);
	t->right->right->left = new Node(4);
	BTree tree;
	// Setting root
	tree.setRoot(t);
	// Function calling
	cout<<"Number of leaves: "<<tree.CountLeaves()<<endl;
	return 0;
}