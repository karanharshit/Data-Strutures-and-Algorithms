bool ans=true;
int height(Node *root){
    if(root==NULL) return 0;
    
    int h1=height(root->left);
    int h2=height(root->right);
    //cout<<h1<<" "<<h2<<"haha"<<endl;
    if(abs(h1-h2)>1){
        ans=false;
    }
    int anss=1+max(h1,h2);
    
    return anss;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    ans=true;
    int val=height(root);
    // int val1=height(root->left);
    // int val2=height(root->right);
    // cout<<val1<<" "<<val2<<"hehe"<<endl;
    return ans;
}
