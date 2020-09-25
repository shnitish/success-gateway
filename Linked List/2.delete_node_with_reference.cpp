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

void insert(int data)
{	
	Node *temp = createNode(data);
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

// Normal delete
void deleteNode(Node *head, int key)
{
	Node *temp, *prev;
	temp = head;

	if (temp->data == key)
	{
		head = temp->next;
		free(temp);
		return;
	}

	while(temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
	free(temp);
}

// delete node with a reference
void deleteRef(Node *refPtr)
{
	if (refPtr->next == NULL)
	{
		return;
	}
	else
	{
		Node *temp;
		temp = refPtr->next;
		refPtr->data = temp->data;
		refPtr->next = temp->next;
		free(temp);
	}
}

void printList()
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
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	deleteRef(head->next->next);
	printList();
	return 0;
}