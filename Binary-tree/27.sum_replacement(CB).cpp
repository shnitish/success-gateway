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
	newnode->right= NULL;

	return newnode;
}

void printTree(Node *temp)
{
	if (temp != NULL)
	{
        cout<<temp->data<<" ";
    	printTree(temp->left);
	    printTree(temp->right);
	}
}

int sumReplacement(Node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return root->data;
    
    int leftSum = sumReplacement(root->left);
    int rightSum = sumReplacement(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + root->data;
}


int main()
{
    Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
    root->left->right = createNode(5);
	root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->right->left = createNode(8);

    printTree(root);
    sumReplacement(root);
    cout<<'\n';
    printTree(root);

}