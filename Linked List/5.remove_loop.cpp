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


void printList()
{
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
}

void removeLoop(Node *head)
{
	Node *slow = head;
	Node *fast = head;

	while(slow && fast && fast->data)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	cout<<slow->data<<endl;
	cout<<fast->data<<endl;

	slow->next = head;

	while(slow->next != fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
  }

int main()
{	
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	// insert(7);
	// insert(8);
	// 1   2	 3	   4	 5 		6	  		1		2	 	3
	head->next->next->next->next->next->next = head->next->next;
	removeLoop(head);
	printList();
	return 0;
}