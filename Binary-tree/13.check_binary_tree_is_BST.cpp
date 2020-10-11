#include <iostream>
#include <limits.h>

using namespace std;

struct Node
{
	int data;
	Node *left = NULL;
	Node *right = NULL;
};

Node *createNode(int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right= NULL;

	return newnode;
}

bool isBST(Node *root, int min, int max)
{
	if(root == NULL)
		return true;

	if(root->data <= min || root->data > max)
		return false;

	return(isBST(root->left, min, root->data) && isBST(root->right, root->data, max));
}	

void printtree(Node *temp)
{
	if (temp != NULL)
	{
	printtree(temp->left);
	cout<<temp->data<<" ";
	printtree(temp->right);
	}
}

int main()
{
	Node *root = createNode(4);
	root->left = createNode(2);
	root->right = createNode(5);
	root->left->left = createNode(1);
	root->left->right = createNode(3);

	if(isBST(root, INT_MIN, INT_MAX))
		cout<<"true";
	else
		cout<<"false";

	return 0;
}