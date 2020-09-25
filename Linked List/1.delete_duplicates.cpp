#include <iostream>
#include <unordered_set>

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

void printList(Node *head)
{	
	Node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
}


// 0(n^2) solution using two loops
void delDuplicateLoop(Node *head)
{
	Node *cur = head;
	Node *nxt;
	Node *dup;

	while(cur != NULL && cur->next != NULL)
	{	
		nxt = cur;
		while(nxt->next != NULL)
		{
			if (cur->data == nxt->next->data)
			{
				dup = nxt->next;
				nxt->next = nxt->next->next;
				free(dup);
			}

			else
			{
				nxt = nxt->next;
			}
		}
		cur = cur->next;
	}
}

// Hashing O(n)
void delDuplicateHash(Node *head)
{
	unordered_set <int> hash;
	Node *cur = head;
	Node *temp;

	while(cur != NULL)
	{
		if (hash.find(cur->data) != hash.end())
		{
			temp->next = cur->next;
			free(cur);
		}
		else
		{
			hash.insert(cur->data);
			temp = cur;
		}
	cur = temp->next;
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
	delDuplicateHash(head);

	printList(head);
	return 0;
}