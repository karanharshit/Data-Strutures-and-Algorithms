class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    vector<Node*> v;
    Node * bToDLL(Node *root)
    {
        // your code here
        v.clear();
        inorder(root);
        Node *head = v[0];
        Node *prev= v[0];
        for(int i=1;i<v.size();i++){
            prev->right=v[i];
            v[i]->left=prev;
            prev=v[i];
        }
        prev->right=NULL;
        return head;
    }
    
    void inorder(Node *root)
    {
        if(root==NULL) return;
        
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
};
