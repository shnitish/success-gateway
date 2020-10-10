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

Node *left_cloned(Node *root)
{	
	if (root == NULL)
	{
		return NULL;
	}

	Node *lcr = left_cloned(root->left);
	Node *rcr = left_cloned(root->right);

	Node *newNOde = createNode(root->data);
	newNOde->left = lcr;
	newNOde->right = NULL;

	root->left = newNOde;
	root->right = rcr;

	return root;
}


Node *transformBack(Node *root)
{	
	if(root == NULL)
		return NULL;

	// Left normalize node and right normalize node
	// recur for the left child until node->left is null
	// Follow jump and change strategy 
	Node *lnn = transformBack(root->left->left);
	Node *rnn = transformBack(root->right);

	// Attach the left normalized to the left child of the 
	// current node and same for right
	root->left = lnn;
	root->right = rnn;

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
	cout<<'\n';
	transformBack(root);
	printtree(root);
	return 0;
}