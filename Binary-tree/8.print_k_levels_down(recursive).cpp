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

void k_levels_down(Node *root, int k)
{

	if(root == NULL || k < 0)
		return;

	if(k == 0)
		cout<<root->data<<" ";

	k_levels_down(root->left, k - 1);
	k_levels_down(root->right, k - 1);
}

int main()
{
	Node *root = createNode(50);
	root->left = createNode(25);
	root->right = createNode(75);
	root->left->left = createNode(12);
	root->left->right = createNode(37);
	root->right->left = createNode(62);
	root->right->right = createNode(87);
	root->left->right->left = createNode(30);
	root->left->right->right = createNode(40);
	root->right->left->left = createNode(60);
	root->right->left->right = createNode(70);

	k_levels_down(root, 2);
	return 0;
}