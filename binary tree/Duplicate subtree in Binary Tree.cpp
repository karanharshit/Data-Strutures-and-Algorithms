unordered_map<string, int> mp;

string solve(Node *root){
    if(root==NULL) return "$";
    
    string s="";
    if(root->left==NULL&&root->right==NULL){
        s=s+to_string(root->data);
        return s;
    }
    
    s=s+to_string(root->data);
    s=s+solve(root->left);
    s=s+solve(root->right);
    mp[s]++;
    
    return s;
}

bool dupSub(Node *root)
{
    bool ans=false;
    mp.clear();
    solve(root);
    for(auto x:mp){
       // cout<<x.first<<" "<<x.second<<"haha"<<endl;
        if(x.second>=2){
            ans=true;
        }
    }
    return ans;
}
