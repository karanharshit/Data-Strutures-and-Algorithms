#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct compare {
    bool operator()(struct Node* p1, struct Node* p2)
    {
        return p1->data > p2->data;
    }
};
 
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
          (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data
    new_node->data = new_data;
 
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// Function to print nodes in a given doubly linked list
void printList(struct Node* head)
{
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


struct Node* sortAKSortedDLL(struct Node* head, int k){
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node *temp=head;
    int count=0;
    Node *prev =NULL;
    Node *newHead;
    while(temp!=NULL){
        pq.push(temp);
        count++;
        if(count==k+1){
            Node * n= pq.top();
            pq.pop();
            if(prev==NULL){
                newHead=n;
                prev=newHead;
                prev->prev=NULL;
            }
            else{
                n->prev=prev;
                prev->next=n;
                prev=prev->next;
            }
            count--;
        }
        temp=temp->next;
    }

    while(!pq.empty()){
         Node * n= pq.top();
         pq.pop();
         n->prev=prev;
         prev->next=n;
         prev=prev->next;
    }
    prev->next=NULL;
    return newHead;
}

int main()
{
    struct Node* head = NULL;
 
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    printList(head);
 
    // sort the biotonic DLL
    head = sortAKSortedDLL(head, k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
}
