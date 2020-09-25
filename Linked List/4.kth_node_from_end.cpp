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

// using 2 pointer approach
void kthNode(int key)
{
	Node *slow = head;
	Node *fast = head;
	Node *prev = head;

	int count = 0;

	for (int i = 1; i < key; ++i)
	{
		fast = fast->next;
	}

	while(fast->next != NULL)
	{
		slow = slow->next;
		count++;
		fast = fast->next;
	}

	for (int i = 1; i < count; ++i)
	{
		prev = prev->next;
	}
 	
 	prev->next = slow->next;
 	free(slow);

}

int main()
{	
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	printList();
	cout<<endl;
	kthNode(3);		// Should remove 6
	printList();
	return 0;
}