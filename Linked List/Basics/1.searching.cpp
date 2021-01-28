#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;	
};

Node *head = NULL;

Node *createNode(int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	return newnode;
}

void insertNode(int data)
{
	Node *temp;
	temp = createNode(data);
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}

	else
	{
		Node *t = head;

		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}

}

int searchIterative(Node *head, int k)
{
    Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        if(temp->data != k)
            {
                temp = temp->next;
                c++;
            } 
        else
            return c + 1;
    }
    return -1;    
}

int searchRecursive(Node *head, int k)
{
    if(head == NULL)
        return -1;

    if(head->data == k)
        return 1;

    else
    {
        int res = searchRecursive(head->next, k);

        if(res == -1)
            return -1;

        else
            return (res + 1);
    }
    
}

void printList(Node *head)
{	
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
}

int main()
{	
	insertNode(10);
	insertNode(12);
	insertNode(11);
	insertNode(11);
	insertNode(12);
	insertNode(11);
	insertNode(10);

    cout<<searchIterative(head, 11);
    // cout<<searchRecursive(head, 11);

	return 0;
}