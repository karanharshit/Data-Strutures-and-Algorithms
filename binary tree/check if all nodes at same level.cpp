class Solution{
  public:
    /*You are required to complete this method*/
    bool ans=true;
    
    int solve(Node *root){
        if(root==NULL) return 0;
        
        if(ans==false) return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        if(l!=0&&r!=0&&l!=r){
            ans=false;
        }
        
        int ans=1+max(l,r);
        return ans;
    }
    
    bool check(Node *root)
    {
        ans=true;
        int x=solve(root);
        return ans;
    }
};
