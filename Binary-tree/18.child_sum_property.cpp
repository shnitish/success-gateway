/*
Check child sum property of the binary tree.

TC = O(n)
*/

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

bool isChildSum(Node *root)
{   
    int sum = 0;

    if(root == NULL)
        return true;
    
    if(root->left == NULL && root->right == NULL)
        return true;
    
    if(root->left != NULL)
         sum += root->left->data;

    if(root->right != NULL)
        sum += root->right->data;
    
    return(sum == root->data && isChildSum(root->left) && isChildSum(root->right));
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
	Node *root = createNode(10);
	root->left = createNode(8);
	root->right = createNode(2);
	root->left->left = createNode(3);
    root->left->right = createNode(5);
	root->right->right = createNode(2);

    
	cout<<isChildSum(root);
	return 0;
}