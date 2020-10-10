/*
1) We pass the parent of the root node as NULL.
2) This parent gets updated with the previous root node as we go down.
3) Recur for left and right checking that if either of the child of node have NULL child or not
4) If yes then print the node's data.
*/

#include <iostream>

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

void print_single_child(Node *root, Node *parent)
{		
	if(root == NULL)
		return;

	if(parent != NULL && parent->left == root && parent->right == NULL)
	{
		cout<<root->data<<endl;
	}
	else if(parent != NULL && parent->right == root && parent->left == NULL)
	{
		cout<<root->data<<endl;
	}

	print_single_child(root->left, root);
	print_single_child(root->right, root);
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
	Node *root = createNode(50);
	root->left = createNode(25);
	root->right = createNode(75);
	root->left->left = createNode(12);
	root->left->right = createNode(37);
	root->left->right->left = createNode(98);
	root->right->left = createNode(62);
	root->right->right = createNode(18); 

	print_single_child(root, NULL);
	return 0;
}