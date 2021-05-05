int maxlevel=0;

void printGivenLevel(vector<int> &ans,Node* root, int level)
{
    if (root == NULL)
        return;
        
    if(level>maxlevel){
        ans.push_back(root->data);
        maxlevel=level;
    }
   
    printGivenLevel(ans,root->right, level+1);
    printGivenLevel(ans,root->left, level+1);
}


vector<int> rightView(Node *root)
{
    maxlevel=0;
    vector<int> ans;
    printGivenLevel(ans,root, 1);
    return ans;
}
