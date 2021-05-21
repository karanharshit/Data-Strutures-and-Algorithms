bool helper(Node *root, int l, int h){
    if(root==NULL) return true;

    return (root->data>l)&&(root->data<h)&&(helper(root->left,l,root->data))&&(helper(root->right,root->data,h));
}

int size(Node *root){
    if(root==NULL) return 0;
    
    return 1+size(root->left)+size(root->right);
}

int largestBst(Node *root)
{
	if(helper(root,-1e9,1e9)) return size(root);
	
	int l=largestBst(root->left);
	int r=largestBst(root->right);
	return max(l,r);
}
