/*
1) Make two variables to store the data of left and right chiild.
2) Check if the left and right child have not null values and store their values into variables.
3) Check if their sum is equal to the root node data while recursively calling the isSum function in the 
of statement for the further left and right child.
4) In main function pass the root node to the isSum function.

TC = O(n)

*/


#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
};

int isSum(Node *node)
{
	int left_data = 0, right_data = 0;

	if (node == NULL || (node->left == NULL && node->right == NULL))
	{
		return 1;
	}

	else
	{
		if (node->left != NULL)
			left_data = node->left->key;

		if (node->right != NULL)
			right_data = node->right->key;

		if ((node->key == left_data + right_data) && isSum(node->left) && isSum(node->right))
			return 1;
		else
			return 0;
	}
}

Node* createNode(int key)
{
	Node *newnode = new Node();
	newnode->key = key;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void printtree(Node *temp)
{
	if (temp != NULL)
	{
		printtree(temp->left);
		cout<<temp->key<<" ";
		printtree(temp->right);
	}	
}

int main()
{	
	Node *root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(5);
	root->right->right = createNode(2);

	printtree(root);
	cout<<'\n';

	if (isSum(root))
		cout<<"Satisfies";

	else
		cout<<"Unsatisfies";

	return 0;
}