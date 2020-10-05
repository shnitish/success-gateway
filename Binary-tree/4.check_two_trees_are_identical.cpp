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

/*
check if roots of both the trees are equal or not 
if yes then recur the function to check for left child or root1 and left child of root2 
same for right child.
*/
bool isIdentical(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	else if (root1 == NULL || root2 == NULL)
		return false;

	else
	{ if (root1->data == root2->data)
		return (isIdentical(root1->right, root2->right) && isIdentical(root1->left, root2->left));

	else
		return false;
	}
}

int main()
{
	Node *root1 = createNode(50);
	root1->left = createNode(25);
	root1->right = createNode(75);
	root1->left->left = createNode(12);
	root1->left->right = createNode(37);
	root1->right->left = createNode(62);
	root1->right->right = createNode(18); 

	Node *root2 = createNode(5);
	root2->left = createNode(2);
	root2->right = createNode(7);
	root2->left->left = createNode(1);
	root2->left->right = createNode(3);
	root2->right->left = createNode(6);
	root2->right->right = createNode(1); 
    

    cout<<isIdentical(root1, root2);
 
	return 0;
}