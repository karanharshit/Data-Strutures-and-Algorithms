int c=0;
int k=0;
vector<float> ans;
void inordercount(Node *root){
    if(root==NULL) return;
    
    inordercount(root->left);
    // v.push_back(root->data);
    c++;
    inordercount(root->right);
}

void inorder(Node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    // v.push_back(root->data);
    if(k==(c/2)-1){
        ans.push_back(root->data);
    }
    if(k==c/2){
        ans.push_back(root->data);
    }
    
    k++;
    inorder(root->right);
}

float findMedian(struct Node *root)
{
    c=0;
    k=0;
    ans.clear();
    inordercount(root);
    inorder(root);
    if(c%2!=0){
        return ans[1];
    }
    else{
        return (ans[0]+ans[1])/2;
    }
}

