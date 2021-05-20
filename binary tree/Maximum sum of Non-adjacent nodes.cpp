vector<int> helper(Node *root){
    if(root==NULL){
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        return v;
    }
    else{
        vector<int> sum1, sum2;
        sum1=helper(root->left);
        sum2=helper(root->right);
        
        vector<int> sum;
        
        //including root
        int x=sum1[1]+sum2[1]+root->data;
        
        //not including
        int y=max(sum1[0],sum1[1])+max(sum2[0],sum2[1]);
        
        sum.push_back(x);
        sum.push_back(y);
        
        return sum;
    }
}

int getMaxSum(Node *root) 
{
    vector<int> v=helper(root);
    return max(v[0],v[1]);
}
