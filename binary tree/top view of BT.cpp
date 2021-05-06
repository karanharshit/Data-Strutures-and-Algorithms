    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> lv;
    
    void printGivenLevel(Node* root, int level)
    {
        if (root == NULL)
            return;
        
        lv[root->data]=level;
   
        printGivenLevel(root->left, level+1);
        printGivenLevel(root->right, level+1);
    }

    void verticalOrder(Node *root, int hd){
        if(root==NULL) return;
        
        mp[hd].push_back(root->data);
        
        verticalOrder(root->left, hd-1);
        verticalOrder(root->right, hd+1);
    }
    
    vector<int> topView(Node *root)
    {
        printGivenLevel(root, 1);
        vector<int> ans;
        int hd=0;
        verticalOrder(root, hd);

        int min=1e9, max=-1e9;
        for (auto x:mp)
        {
            if(x.first>max){
                max=x.first;
            }
            
            if(x.first<min){
                min=x.first;
            }
        }
        
        for(int i=min;i<=max;i++){
            for (auto x:mp){
                if(x.first==i){
                    int minlev=1e9;
                    int curr;
                    for (int i=0; i<x.second.size(); i++){
                        if(lv[x.second[i]]<minlev){
                            minlev=lv[x.second[i]];
                            curr=x.second[i];
                        }
                    }
                    ans.push_back(curr);
                }
            }
        }

        return ans;
    }
