// Simply used hashing to find duplicate values of the nodes.
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    
    unordered_set<int> hash;
    
    SinglyLinkedListNode *cur = head;
    SinglyLinkedListNode *temp;
    
    while(cur != NULL)
    {
        if(hash.find(cur->data) != hash.end())
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
    return head; 
}