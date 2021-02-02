/*
Mutilpy Linked List as whole with a single digit k inplace
Josh Technology group online test question

TC = O(n)
Sc = O(1)
*/
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

            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL, *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void multiply()
    {
        reverse();
        Node *curr = head;
        int carry = 0;

        while (curr != NULL)
        {
            int res = curr->data * 5 + carry;
            curr->data = res % 10;
            carry = res / 10;
            curr = curr->next;
        }

        // if carry is remaining
        // create newnode to add carry to LL
        if (carry != 0)
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = createNode(carry);
            carry = 0;
        }
        reverse();

        // print LL
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList s;

    s.insertNode(1);
    s.insertNode(2);
    s.insertNode(7);
    s.insertNode(3);
    s.multiply();

    return 0;
}