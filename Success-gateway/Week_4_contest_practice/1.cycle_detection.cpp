/*
Given a pointer to the head of a linked list, 
determine if it contains a cycle. If it does, return 1. Otherwise, return 0.
*/


SinglyLinkedListNode {
     int data;
     SinglyLinkedListNode* next;
 };

// Floyd Cycle detection algorithm
// Using fast and slow pointers
bool has_cycle(SinglyLinkedListNode* head) {

    SinglyLinkedListNode *slow, *fast;
    
    slow = head;
    fast = head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return 1;
    }
    return 0;
    
}