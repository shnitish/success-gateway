
// Using recursion
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
 SinglyLinkedListNode* result = NULL; 
     
    if (head1 == NULL) 
        return(head2); 
    else if (head2 == NULL) 
        return(head1); 
     
    if (head1->data <= head2->data) 
    { 
        result = head1; 
        result->next = mergeLists(head1->next, head2); 
    } 
    else
    { 
        result = head2; 
        result->next = mergeLists(head1, head2->next); 
    } 
    return(result); 
}

/* Using Extra nodes head and tail
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *head = NULL;
    SinglyLinkedListNode *end = NULL;
    
    if(head1->data < head2->data)
    {
        head = head1;
        end = head1;
        head1 = head1->next;
        end->next = NULL;
    }
    else
    {
        head = head2;
        end = head2;
        head2 = head2->next;
        end->next = NULL;
    }
    
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            end->next = head1;
            end = head1;
            head1 = head1->next;
            end->next = NULL;
        }
        else
        {
            end->next = head2;
            end = head2;
            head2 = head2->next;
            end->next = NULL;
        }
        
    }
    
    if(head1)
        end->next = head1;

    if(head2)
        end->next = head2;
    
    return head;
}
*/

