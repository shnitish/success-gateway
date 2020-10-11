/*
TC = O(n)

*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

int height_recursive(Node *root)
{	
	if (root == NULL)
	{
		return 0;
	}

	int lh = height_recursive(root->left);
	int rh = height_recursive(root->right);

	int th = max(lh, rh) + 1;

	return th;
}

// O(n^2) time complexity because the recurisive solution is calling height_recursive
// calculating height for n nodes

int diameter(Node *root)
{
	if(root == NULL)
		return 0;

	int left_dia = diameter(root->left);
	int right_dia = diameter(root->right);

	int factor = height_recursive(root->left) + height_recursive(root->right) + 2;

	int dia = max(factor,  max(left_dia, right_dia));

	return dia - 1; // subtracting 1 because the height function calc height node wise
					// and diameter is calculated edge wise
}

Node *createNode(int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
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

    cout<<diameter(root);

	return 0;
}