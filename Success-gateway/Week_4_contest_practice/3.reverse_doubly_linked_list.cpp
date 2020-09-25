// swap the prev and next pointers and then
// change the head pointer.
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {

    DoublyLinkedListNode *temp = head;
    DoublyLinkedListNode *cur = head;
    
    
    while(cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    
    if( temp != NULL)
    {
        head = temp->prev;
    }
    return head;
}