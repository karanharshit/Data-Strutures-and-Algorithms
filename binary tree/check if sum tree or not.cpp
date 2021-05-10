class Solution
{
    public:
    bool ans=true;
    bool isSumTree(Node* root)
    {
        sumTree(root);
        return ans;
    }
    
    int sumTree(Node *root)
    {
        if(root==NULL) return 0;
        
        if(root->left==NULL&&root->right==NULL) return root->data;
        
        if(ans==false) return 0;
        
        int old= root->data;
        int sum=sumTree(root->left)+sumTree(root->right);
        if(sum!=root->data){
            ans=false;
        }
        return sum+root->data;
    }
};
