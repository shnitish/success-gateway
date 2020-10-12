#include <iostream>
#include <stack>

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


void zig_zag(Node *root)
{	
	if(root == NULL)
		return;

	// StackEven store nodes at even level
	stack <Node *> stackEven;
	// StackOdd store the nodes at odd level
	stack <Node *> stackOdd;

	stackEven.push(root);

	while( (!stackEven.empty()) || (!stackOdd.empty()) )
	{
			while(!stackEven.empty())
			{
				Node *temp = stackEven.top();
				cout<<temp->data<<" ";
				stackEven.pop();

				if(temp->left)
					stackOdd.push(temp->left);

				if(temp->right)
					stackOdd.push(temp->right);
			}

		
			while(!stackOdd.empty())
			{
				Node *temp = stackOdd.top();
				cout<<temp->data<<" ";
				stackOdd.pop();

				if(temp->right)
					stackEven.push(temp->right);

				if(temp->left)
					stackEven.push(temp->left);
			}
	}


}

void printtree(Node *temp)
{
	if (temp != NULL)
	{
	printtree(temp->right);
	cout<<temp->data<<" ";
	printtree(temp->left);
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

	zig_zag(root);
	return 0;
}