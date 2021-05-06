vector<int> ans;
vector<int> ansrev;
int flag=0;

void printGivenLevel(Node* root, int level)
{
    
    if (root == NULL)
        return;
    if (level == 1){
        ansrev.push_back(root->data);
    }
        //cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
    
int height(struct Node* node){
    if(node==NULL){
        return 0;
    }
    
    else{
        int h1=height(node->left);
        int h2=height(node->right);
        int ans=1+max(h1,h2);
        return ans;
    }
}

vector<int> zigZagTraversal(Node* root)
{
    ans.clear();
    flag=0;
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        ansrev.clear();
        printGivenLevel(root, i);
        if(flag==1){
            reverse(ansrev.begin(), ansrev.end());
            flag=0;
        }
        else if(flag==0){
            flag=1;
        }
        ans.insert(ans.end(), ansrev.begin(), ansrev.end());
    }
    return ans;
}
