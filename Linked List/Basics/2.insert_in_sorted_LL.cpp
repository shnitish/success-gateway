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

void printList(Node *head)
{	
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
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

void insertSorted(Node *head, int k)
{
    Node *newNode = createNode(k);
    if(head == NULL)
        printList(newNode);

    if(k < head->data)
    {   
       newNode->next = head;

       printList(newNode);
    }

    else
    {
    Node *temp = head;
    while(temp->next != NULL && temp->next->data < k)
        temp = temp->next;
    
    Node *newNode = createNode(k);
    newNode->next = temp->next;
    temp->next = newNode;

    printList(head);
    }
}

int main()
{	
	insertNode(10);
	insertNode(20);
	insertNode(30);
	insertNode(50);
	insertNode(60);
	insertNode(70);

	insertSorted(head, 0);
	return 0;
}