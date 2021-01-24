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
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
    root->left->right = createNode(5);
	root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->right->left = createNode(8);

	printtree(root);
	return 0;
}