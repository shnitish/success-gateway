#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;	
};

class LinkedList
{
	private:
	Node *head;

	public:

	LinkedList()
	{
		head = NULL;
	}

Node *createNode(int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	return newnode;
}

void insertBeg(int data)
{
	Node *temp = createNode(data);
	temp->next = head;
	head = temp;
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

void deletehead()
{
	Node *temp = head;
	head = head->next;
	delete(temp);

}

void deleteElement(int data)
{
	Node *temp = head->next;
	Node *prev = head;

	while(temp->data != data)
	{
		temp = temp->next;
		prev = prev->next;
	}

	Node *t = temp;
	prev->next = temp->next;
	delete(t);
}

void printList()
{	
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
};

int main()
{	
	LinkedList s;

	s.insertNode(11);
	s.insertNode(12);
	s.insertNode(11);
	s.insertNode(11);
	s.insertNode(12);
	s.insertNode(11);
	s.insertNode(10);
	s.insertNode(9);
	s.insertNode(8);
	s.deleteElement(10);

	s.printList();
	return 0;
}