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
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void leftView(Node *root)
{   
    if(root == NULL)
        return;

    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if(i == 0)
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
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->right->right = createNode(5);

    leftView(root);
    return 0;
}