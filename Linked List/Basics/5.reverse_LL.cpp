/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// Iterative
// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    if(head == NULL)
        return NULL;
        
    Node *prev = NULL;
    Node *curr = head;
    
    while(curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}


// Recursive version of the iterative soln w
class Solution {
public:
    
    ListNode* helper(ListNode *curr, ListNode *prev)
    {
        // when curr becomes null, we (prev) 
        // will be on the end of the LL which will be the new head
        if(curr == NULL) return prev;
        
        ListNode *next = curr->next;
        curr->next = prev;
        
        return helper(next, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *node = helper(head, NULL);
        
        return node;
    }
};

// Recursive reverse 2
struct Node* reverseList(struct Node *head)
{
    // base case 
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *newHead = reverseList(head->next);
    // newHead will have the head of the newly reverse linked list except
    // first node still pointing to the tail of the new list or the second node

    Node *newTail = head->next;
    newTail->next = head;
    head->next = NULL;
    
    return newHead;
}