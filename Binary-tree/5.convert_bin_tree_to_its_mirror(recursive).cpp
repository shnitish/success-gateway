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

void convertMirror(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		convertMirror(root->left);
		convertMirror(root->right);

		Node *temp;

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void in_iterative(Node *root)
{
	unordered_map <Node *, int> count;

	stack <Node *> s;

	s.push(root);

	while(s.size() > 0)
	{
		Node *cur = s.top();

		if (cur == NULL)
		{
			s.pop();
			continue;
		}

		if (count[cur] == 0)
		{
			s.push(cur->left);
		}

		else if (count[cur] == 1)
		{
			cout<<cur->data<<" ";
		}

		else if (count[cur] == 2)
		{
			s.push(cur->right);
		}

		else
		{
			s.pop();
		}

		count[cur]++;
	}
}


int main()
{
	Node *root = createNode(50);
	root->left = createNode(25);
	root->right = createNode(75);
	root->left->left = createNode(12);
	root->left->right = createNode(37);
	root->right->left = createNode(62);
	root->right->right = createNode(18); 
    

    in_iterative(root);
    cout<<'\n';
    convertMirror(root);
    in_iterative(root);
	return 0;
}