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

/*
If N1, N2 both smaller than root then LCA lies in left 
so recur for left subtree.

IF N1, N2 both greater than root then LCA lies in right

If none of the case, then the current node is the LCA
*/
int LcaBST(Node *root, int N1, int N2)
{
	if(N1 < root->data && N2 < root->data)
		return LcaBST(root->left, N1, N2);

	else if(N1 > root->data && N2 > root->data) 
		return LcaBST(root->right, N1, N2);

	else
		return root->data;
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

	cout<<LcaBST(root,12, 37);
	return 0;
}