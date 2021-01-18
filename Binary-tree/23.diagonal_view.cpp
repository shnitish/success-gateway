#include <bits/stdc++.h>

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

void fillMap(Node *root, int dist, map <int, vector <int>> &map)
{
    if(root == NULL)
        return;
    
    map[dist].push_back(root->data);

    fillMap(root->left, dist + 1, map);
    fillMap(root->right, dist, map);
}

void diagonalView(Node *root)
{
    map <int, vector <int>> map;
    fillMap(root, 0, map);

    for(auto i: map)
    {
        vector <int> v = i.second;
        for(auto i: v)
            cout<<i<<" ";
        cout<<endl;
    }
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

	diagonalView(root);
	return 0;
}