class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    //bool ans=true;
    bool isBST(Node* root) 
    {
        // Your code here
        bool ans;  
        int min=-1e9;
        int max=1e9;
        ans=helper(root,min,max);
        return ans;
    }
    
    bool helper(Node* root, int min, int max){
        if(root==NULL) return true;
        
        return (root->data>min)&&(root->data<max)&&(helper(root->left,min,root->data))&&(helper(root->right,root->data,max));
    }
};
