vector<node*> v;

void inorder(struct node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    v.push_back(root);
    inorder(root->right);
}

void populateNext(struct node* p)
{
    v.clear();
    inorder(p);
    // sort(v.begin(), v.end(), compare);
    for(int i=0;i<v.size()-1;i++){
        v[i]->next=v[i+1];
        //  cout<<v[i]->data<<" ";
    }
    // cout<<endl;
// Your code goes here

}
