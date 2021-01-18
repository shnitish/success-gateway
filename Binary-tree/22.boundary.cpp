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

void leftBoundary(Node *root, vector <int> &nodes)
{
    if(root == NULL) return; 
    if(root->left || root->right) nodes.push_back(root->data);
    if(root->left) leftBoundary(root->left, nodes);
    else if(root->right) leftBoundary(root->right, nodes);
}

void rightBoundary(Node *root, vector <int> &nodes)
{
    if(root == NULL) return; 
    if(root->right) rightBoundary(root->right, nodes);
    else if(root->left) rightBoundary(root->left, nodes);
    if(root->left || root->right) nodes.push_back(root->data);
}

void leafNodes(Node *root, vector <int> &nodes)
{
    if(root == NULL) return;
    if(root->left) leafNodes(root->left, nodes);
    if(!root->left && !root->right) nodes.push_back(root->data);
    if(root->right) leafNodes(root->right, nodes);
}

vector <int> printBoundary(Node *root)
{
     vector <int> nodes;
     if(root == NULL) return nodes;
     
     nodes.push_back(root->data);
     if(root->left == NULL && root->right == NULL) return nodes;

     leftBoundary(root->left, nodes);
     leafNodes(root, nodes);
     rightBoundary(root->right, nodes);    
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

	printBoundary(root);
	return 0;
}