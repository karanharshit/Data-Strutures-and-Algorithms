Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 


Node* mergeSort(Node* head) {
    Node* a; 
    Node* b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return head; 
    } 
  
    Node* fast; 
    Node* slow; 
    slow = head; 
    fast = head->next; 
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    a = head; 
    b = slow->next; 
    slow->next = NULL;
  
    a=mergeSort(a); 
    b=mergeSort(b); 
  
    
    head = SortedMerge(a, b);
    return head;
}
