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

Node *removeLEAFnodes(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}

	if(root->left == NULL && root->right == NULL)
	{
		free(root);
		return NULL;
	}
		
	root->left = removeLEAFnodes(root->left);
	root->right = removeLEAFnodes(root->right);

	return root;
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

	printtree(root);
	cout<<"\n";
	removeLEAFnodes(root);
	printtree(root);
	return 0;
}