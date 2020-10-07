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
	Node *newnode = new Node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


Node *left_cloned(Node *root)
{	
	if (root == NULL)
	{
		return NULL;
	}

	// creates the left clones for the left and and right childerens of the root
	Node *lcr = left_cloned(root->left);
	Node *rcr = left_cloned(root->right);

	// create a new node 
	// Since it is left cloned, the new node is holds the same data as of root
	// and attach the lcr of to the left of this new node and null to the its right
	Node *newNOde = createNode(root->data);
	newNOde->left = lcr;
	newNOde->right = NULL;

	// Fina;ly attach this new node to the left of the root
	root->left = newNOde;
	root->right = rcr;

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
   	
	left_cloned(root);
	printtree(root);

	return 0;
}