vector<Node*> v;

void inorder(Node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    v.push_back(root);
    inorder(root->right);
}

Node* helper(int l, int h){
    if(h<l) return NULL;
    
    int mid = (l + h)/2;
    Node* root = new Node(v[mid]->data);
    
    root->left=helper(l,mid-1);
    root->right=helper(mid+1,h);
    return root;
}

Node* buildBalancedTree(Node* root)
{
    v.clear();
    inorder(root);
    Node *root1=helper(0,v.size()-1);
    return root1;
}
