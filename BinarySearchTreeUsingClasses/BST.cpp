#include<iostream>
#include<vector>
using namespace std;

class BTreeNode
{
	private:
		double data;
		BTreeNode *left,*right,*root;
	public:
		//Non-parameterized constructor
		BTreeNode()
		{
			this->root=NULL;
		}
		//Parameterized constructor
		BTreeNode(double data)
		{
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
		void insert(double x);
		void insert(BTreeNode *t, double x);
		void inorder(vector<double> &v);
		void inorder(BTreeNode *t, vector<double> &v);
		bool search(double x);
		bool search(BTreeNode *t, double x);
		int size();
		int size(BTreeNode *t);
		int leafCounter();
		int leafCounter(BTreeNode *t);
		int height();
		int height(BTreeNode *t);
};

void BTreeNode::insert(double x)
{
	insert(root,x);
}

void BTreeNode::insert(BTreeNode* t, double value)
{
	//If tree is empty
	if(!root)
	{
		root=new BTreeNode(value);
		return;
	}
	while(true)
	{
		//If value is lesser
		if(value < t->data)
		{
			//If left is null then insert
			if(!t->left)
			{
				t->left=new BTreeNode(value);
				return;
			}
			//else go to left
			t=t->left;
		}
		//Else value is greater
		else
		{
			//If right is null then insert
			if(!t->right)
			{
				t->right=new BTreeNode(value);
				return;
			}
			//else go right
			t=t->right;
		}
	}
}

void BTreeNode::inorder(vector<double> &v)
{
	inorder(root, v);
}

void BTreeNode::inorder(BTreeNode *t, vector<double> &v)
{
	if(t)
	{
		//Left Root Right
		inorder(t->left,v);
		v.push_back(t->data);
		inorder(t->right,v);
	}
}

bool BTreeNode::search(double x)
{
	return search(root, x);
}

bool BTreeNode::search(BTreeNode *t, double x)
{
	if(t)
	{
		//If x found return true
		if(t->data==x)
		{
			return true;
		}
		//If x is less then go to left
		if(x<t->data)
		{
			return search(t->left,x);
		}
		//If x is greater then go to right
		return search(t->right,x);
	}
	return false;
}

int BTreeNode::size()
{
	return size(root);	
}

int BTreeNode::size(BTreeNode *t)
{
	if(t)
	{
		return 1+size(t->left)+size(t->right);
	}
	return 0;
}

int BTreeNode::leafCounter()
{
	return leafCounter(root);
}

int BTreeNode::leafCounter(BTreeNode *t)
{
	if(t)
	{
		//If leaf return 1
		if(!t->left && !t->right)
		{
			return 1;
		}
		//Count in left and right subtrees
		return leafCounter(t->left)+leafCounter(t->right);
	}
	return 0;
}

int BTreeNode::height()
{
	return height(root);
}

int BTreeNode::height(BTreeNode *t)
{
	if(t)
	{
		//1+ maximum of height of left and right sub tree
		return 1+max(height(t->left),height(t->right));
	}
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	BTreeNode b;
	b.insert(40);
	b.insert(20);
	b.insert(30);
	b.insert(10);
	b.insert(50);
	vector<double> v;
	b.inorder(v);
	cout<<"\nInorder: ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n\nSize of tree: "<<b.size()<<endl;
	cout<<"\nNumber of leaves: "<<b.leafCounter()<<endl;
	//Assume height of single node is 0
	cout<<"\nHeight of tree: "<<b.height()-1<<endl;
	return 0;
}