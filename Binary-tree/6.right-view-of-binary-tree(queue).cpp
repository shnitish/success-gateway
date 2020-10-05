

#include <bits/stdc++.h>

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

void rightView(Node *root)
{
	if (!root)
		return;

	queue <Node *> q;
	q.push(root);

	while(!q.empty())
	{
		int n = q.size();

		for (int i = 1; i <=n; ++i)
		{
			Node *temp = q.front();
			q.pop();

			if (i == n)
				cout<<temp->data<<" ";

			if(temp->left != NULL)
				q.push(temp->left);

			if(temp->right != NULL)
				q.push(temp->right);
		}
	}
}

int main()
{	
	Node *root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(8);
	root->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	rightView(root);
	return 0;
}