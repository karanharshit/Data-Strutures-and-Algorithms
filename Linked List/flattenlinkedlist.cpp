Node *flatten(Node *root)
{
   Node *backw=root;
   Node *forw=root;
   forw=forw->next;
   Node *head;
   while(forw!=NULL){
       Node *p=backw;
       Node *q=forw;
       if(p->data<q->data){
           backw=p;
           p=p->bottom;
       }
       else{
           backw=q;
           q=q->bottom;
       }
       Node *temp=backw;
   
       while(p&&q){
           if(p->data<q->data){
               temp->bottom=p;
               temp=p;
               p=p->bottom;
           }
           else{
               temp->bottom=q;
               temp=q;
               q=q->bottom;
           }
       }
       while(p!=NULL){
           temp->bottom=p;
           temp=p;
           p=p->bottom;
       }
       while(q!=NULL){
           temp->bottom=q;
           temp=q;
           q=q->bottom;
       }
       forw=forw->next;
   }
   return backw;
}
