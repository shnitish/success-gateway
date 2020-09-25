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

void insertNodeFront(int data)
{
	Node *temp;
	temp = createNode(data);
	temp->next = head;

	head = temp;
}

void insertNodeAt(Node *prev, int data)
{
	if (prev == NULL)
	{
		return;
	}

	Node *temp = createNode(data);
	temp->next = prev->next;
	prev->next = temp;
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
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNodeFront(4);
	insertNodeAt(head->next,5);

	printList(head);
	return 0;
}