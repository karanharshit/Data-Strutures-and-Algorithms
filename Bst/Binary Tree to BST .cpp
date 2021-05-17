class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> ans;
    int index=0;
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        ans.clear();
        index=0;
        helper(root);
        sort(ans.begin(),ans.end());
        solver(root);
        return root;
    }
    
    void helper(Node *root){
        if(root==NULL) return;
        
        helper(root->left);
        ans.push_back(root->data);
        helper(root->right);
    }
    
    void solver(Node *root){
        if(root==NULL) return;
        
        solver(root->left);
        root->data=ans[index];
        index++;
        solver(root->right);
    }
};
