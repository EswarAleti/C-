#include<iostream>
#include<fstream>
using namespace std;
//Initialization of node
struct node 
{
    int data;
    int count=0;
    struct node *left;
    struct node *right;
};
//create a new node
struct node *createNode(int val)
{
    struct node *newNode=new(struct node);
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//Ordered tree class
class BST
{
    private:
    	//Initialization of root node
        struct node *root=NULL;
    public:
    	//Method declarations
        void insert(struct node *t,int val);
        void insert(int val);
        void inorder(struct node *t,int count);
        void inorder(int count);
        int isValidLeaf(int val);
        void deleteLeaf(struct node *&t);
        void deleteLeaf();
        int numberOfNodes(struct node *t);
        int numberOfNodes();
        int sum(struct node *t);
        int sum();
        int numberOfValues(struct node *t);
        int numberOfValues();
};

//Insert new val to tree
void BST::insert(struct node *t,int val)
{
	//create new node
    struct node *newNode=createNode(val);
    //If tree is empty then make new node as root
    if(root==NULL)
    {
        root=newNode;
        return;
    }
    //If val is lesser than parent go left
    if(val<t->data)
    {
    	//If left is null then make it as null
        if(t->left==NULL)
        {
            t->left=newNode;
            return;
        }
        //Else go left
        insert(t->left,val);
    }
    //If val is greater than parent go right
    else if(val>t->data)
    {
    	//If right is null then make it as null
        if(t->right==NULL)
        {
            t->right=newNode;
            return;
        }
        //Else go right
        insert(t->right,val);
    }
    //If node exist then increment it's count
    else
    {
    	t->count++;
    }
}
void BST::insert(int val)
{
    insert(root,val);
}
void BST::inorder(struct node *t, int count)
{
	//If node exist and if it is in first 20 elements
    if(t!=NULL && count<=20)
    {
    	//Go left
    	inorder(t->left,count+1);   
        //Print data
        cout<<t->data<<" ";   
        //Go right
        inorder(t->right,count+1);
    }
}
void BST::inorder(int count)
{
    inorder(root,count);
}

int BST::isValidLeaf(int num)
{
	int sum=0;
	//sum of digits
	while(num>0)
	{
		sum+=num%10;
		num/=10;
	}
	//Return False if sum is less than 9, True otherwise
	return sum>=9;
}
void BST::deleteLeaf()
{
	deleteLeaf(root);
}
void BST::deleteLeaf(struct node *&t)
{
	if(t!=NULL)
	{
		//If it is leaf and sum<9
		if(!t->left && !t->right && !isValidLeaf(t->data))
		{
			t=NULL;
			return;
		}
		//Go to left subtree
		deleteLeaf(t->left);
		//Go to right subtree
		deleteLeaf(t->right);
	}
}
int BST::numberOfNodes()
{
	return numberOfNodes(root);
}
//This function returns number of nodes
int BST::numberOfNodes(struct node *t)
{
	//If node not exist then return 0
	if(t==NULL)
	{
		return 0;
	}
	//count current node + nodes of left subtree + nodes of right subtree
	return 1+numberOfNodes(t->left)+numberOfNodes(t->right);
}
int BST::numberOfValues()
{
	return numberOfValues(root);
}
//this funstion returns number of values including duplicates
int BST::numberOfValues(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	//t->count+1 count the duplicates also
	return (t->count+1)+numberOfValues(t->left)+numberOfValues(t->right);
}
int BST::sum()
{
	return sum(root);
}
int BST::sum(struct node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	//(t->count+1)*t->data finds the sum including duplicates
	return ((t->count+1)*t->data)+sum(t->left)+sum(t->right);
}
int main()
{
	BST bst;
	//read file
    fstream myfile("TreeNbrsV2.txt");
	int num;
	//each number in file
	while(myfile>>num)
	{
		//insert into ordered tree
		bst.insert(num);
	}
	//Function calling and output printing
	cout<<"\nBefore deletion: "<<endl;
	bst.inorder(0);
	bst.deleteLeaf();
	cout<<"\nAfter deletion: "<<endl;
    bst.inorder(0);
    cout<<"\n\nSize of tree: "<<bst.numberOfNodes()<<endl;
    cout<<"\nSum is: "<<bst.sum()<<endl;	
    cout<<"\nAverage is: "<<float(bst.sum())/bst.numberOfValues()<<endl;
    return 0;
}