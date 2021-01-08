#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void insert(Node* &head, int value){
    Node *a=new Node();
    a->data=value;
    a->next=NULL;
    if(head==NULL){
        head=a;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=a;
}

void insertfront(Node* &head, int value, int position){
    Node *a=new Node();
    a->data=value;
    a->next=NULL;

    Node *temp=head;
    while(temp->data!=position){
        temp=temp->next;
    }
    Node *temp1=temp->next;
    temp->next=a;
    a->next=temp1;
}

void inserthead(Node* &head, int value){
    Node *a= new Node();
    a->data=value;
    a->next= head;
    head=a;
}

void deletenode(Node* &head, int value){
    Node* temp=head;
    Node *temp1=head;
    if(temp1->data==value){
        temp=temp1->next;
        head=temp;
        delete temp1;
    }

    else{
    temp1=temp->next;


    while(temp1->data!=value){
        temp1=temp1->next;
        temp=temp->next;
    }
    Node *after;
    after=temp1->next;
    temp->next=after;

    delete temp1;}
}

void display(Node* head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

    cout<<"NULL"<<endl;
}

void deletelist(Node* &head){
    Node *curr=head;
    Node *next=head;
    while(curr!=NULL){
        next=curr->next;
        free(curr);
        curr=next;
    }
    head=NULL;
}

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


int main(){
    Node *head=NULL;

    insert(head,3);
    insert(head,4);
    insert(head,5);
    insertfront(head,6,3);
    inserthead(head,7);
    insert(head,8);
    deletenode(head,8);
    display(head);
    deletelist(head);
    display(head);
}
