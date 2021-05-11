unordered_map<string, int> mp;

string helper(Node *root){
    if(root==NULL) return "$";
    
    string s="";
    if(root->left==NULL&&root->right==NULL){
        s=s+to_string(root->data);
        mp[s]++;
        return s;
    }
    
    // string s="";
    s=to_string(root->data);
    s=s+" "+helper(root->left);
    s=s+" "+helper(root->right);
    mp[s]++;
    return s;
}

void printAllDups(Node* root)
{
    mp.clear();
    helper(root);
    int flag=0;
    vector<string> s;
    for(auto x:mp){
         //cout<<x.first<<" "<<x.second<<"haha"<<endl;
        if(x.second>=2){
            flag=1;
            int i=0;
            string ans="";
            while(i<x.first.length()&&x.first[i]!=32){
                ans=ans+x.first[i];
                i++;
            }
            s.push_back(ans);
            //cout<<ans<<" ";
        }
    }
    sort(s.begin(), s.end());
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    if(flag==0){
        cout<<"-1";
    }
}
