bool ans;

void helper(Node *root, int l, int h){
    if(root==NULL) return;
    
    if(h==l){
        ans=true;
        // cout<<root->data<<" "<<"haha"<<endl;
        return;
    }
    
    helper(root->left,l,(root->data)-1);
    helper(root->right,(root->data)+1,h);
}

bool isDeadEnd(Node *root)
{
    ans=false;
    int l=1,h=1e9;
    helper(root,l,h);
    return ans;
    //Your code here
}
