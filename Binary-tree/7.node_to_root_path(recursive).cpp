#include <iostream>
#include <vector>

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

// to store the node values of the path where true is returned 
// in the recursive call
vector <int> path;

bool nodeToRoot(Node *root, int data)
{

	if(root == NULL)
		return false;

	if(root->data == data)
	{	
		path.push_back(root->data);
		return true;
	}

	// find in left child (subtree)
	bool filc = nodeToRoot(root->left, data);
	if (filc)
	{
		path.push_back(root->data);
		return true;
	}

	// find in right child(subtree)
	bool firc = nodeToRoot(root->right, data);
	if (firc)
	{
		path.push_back(root->data);
		return true;
	}

	return false;
}

int main()
{
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->right->right = createNode(5);

	cout<<nodeToRoot(root, 5)<<endl;

	for (int i = 0; i < path.size(); ++i)
	{
		cout<<path[i]<<" ";
	}

	return 0;
}