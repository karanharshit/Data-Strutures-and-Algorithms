int height(Node *root){
    if(root==NULL) return 0;
    
    int l= height(root->left);
    int r= height(root->right);
    return 1+max(l,r);
}

int helper(Node *root){
    if(root==NULL) return 0;
    
    int ans=0;
    ans=ans+root->data;
    if(height(root->left)>height(root->right)){
        ans=ans+helper(root->left);
    }
    else if(height(root->left)==height(root->right)){
        ans=ans+max(helper(root->right),helper(root->left));
    }
    else{
        ans=ans+helper(root->right);
    }
    //cout<<ans<<"haha"<<endl;
    return ans;
}


int sumOfLongRootToLeafPath(Node* root)
{
    //ans=0;
    int ans=helper(root);
    return ans;
	// Code here
}
