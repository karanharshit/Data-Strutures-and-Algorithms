void reverselist(Node* &head){
    Node *prev=NULL;
    Node *curr=head;
    Node *fut=NULL;
    while(curr!=NULL){
        fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
    }
    head=prev;
}


Node *compute(Node *head)
{
    reverselist(head);
    Node *temp=head;
    Node *prev=head;
    int max=temp->data;
    temp=temp->next;
    while(temp!=NULL){
        if(temp->data>=max){
            max=temp->data;
            temp=temp->next;
            prev=prev->next;
        }
        else{
            temp=temp->next;
            prev->next=temp;
        }
    }
    reverselist(head);
    return head;
}
