// TO calculate the length of the linked lists
int length(SinglyLinkedListNode *head)
{
    int count = 0;
    
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Using length of the linked lists and placing the pointer on the node
// such that from that point both the linked list have same length.
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    
    while(len1 > len2)
    {
        --len1;
        head1 = head1->next;
    }
    
    while(len2 > len1)
    {
        --len2;
        head2 = head2->next;
    }
    
    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1->data;
        }
        
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}