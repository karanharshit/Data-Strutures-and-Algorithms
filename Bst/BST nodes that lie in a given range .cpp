int ans;

void helper(Node *root, int l, int h){
    if(root==NULL) return;
    
    if(root->data>=l&&root->data<=h){
        ans++;
    }
    
    if(root->data>l){
        helper(root->left,l,h);
    }
    if(root->data<h){
        helper(root->right,l,h);
    }
}

int getCount(Node *root, int l, int h)
{
    ans=0;
    helper(root,l,h);
    return ans;
}
