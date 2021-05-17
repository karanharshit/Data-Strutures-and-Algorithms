unordered_map<int, int> mp;
    
void helper(Node* root){
    if(root==NULL) return;
        
    if(root->left!=NULL){
        mp[root->left->data]=root->data;
    }
    if(root->right!=NULL){
        mp[root->right->data]=root->data;
    }
        
    helper(root->left);
    helper(root->right);
}
    
Node* search(Node* root, int x){
    if(root==NULL) return 0;
    if(root->data==x) return root;
    
    Node* temp=search(root->left,x);
    if(temp!=NULL) return temp;
    
    temp=search(root->right,x);
    return temp;
        
}

int findDist(Node* root, int a, int b) {
    mp.clear();
    helper(root);
        
    int x=a, y=b;
    vector<int> v1, v2;
    while(x!=0){
        v1.push_back(x);
        x=mp[x];
    }
            
    while(y!=0){
        v2.push_back(y);
        y=mp[y];
    }
    
    unordered_map<int, int> map;
    for(int i=0;i<v1.size();i++){
        map[v1[i]]++;
    }
            
    for(int i=0;i<v2.size();i++){
        map[v2[i]]++;
    }
    
    int ans=0;
    for(int i=0;i<v1.size();i++){
        if(map[v1[i]]==2){
            //data=v1[i];
            ans=ans+i;
            break;
        }
    }
    
    for(int i=0;i<v2.size();i++){
        if(map[v2[i]]==2){
            //data=v1[i];
            ans=ans+i;
            break;
        }
    }
    
    return ans;
}
