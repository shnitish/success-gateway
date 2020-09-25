#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *createNode(int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void leafNodes(Node *root)
{
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL)
	{
		cout<<root->data<<" ";
		return;
	}

	if (root->left)
	{
		leafNodes(root->left);
	}

	if (root->right)
	{
		leafNodes(root->right);
	}
}

int main()
{
	Node *root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(4); 
    root->right->left = createNode(5); 
    root->right->right = createNode(8); 
    root->right->left->left = createNode(6); 
    root->right->left->right = createNode(7); 
    root->right->right->left = createNode(9); 
    root->right->right->right = createNode(10);

    leafNodes(root);
	return 0;
}