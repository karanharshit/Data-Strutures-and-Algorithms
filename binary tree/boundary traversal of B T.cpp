vector<int> ans;

void leaftravel(Node *root){
    if(root==NULL) return;
    
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
    }
    
    else{
        leaftravel(root->left);
        leaftravel(root->right);
    }
}

vector <int> printBoundary(Node *root)
{
     ans.clear();
     Node *temp=root;
     ans.push_back(temp->data);
     if(root->left!=NULL){
     while(temp->left!=NULL||temp->right!=NULL){
         if(temp->left!=NULL){
             temp=temp->left;
         }
         else{
             temp=temp->right;
         }
         ans.push_back(temp->data);
     }
     ans.pop_back();
     }
     
     leaftravel(root);
     
     if(root->right!=NULL){
     ans.pop_back();
     vector<int> ans1;
     temp=root;
     temp=temp->right;
     ans1.push_back(temp->data);
     while(temp->right!=NULL||temp->left!=NULL){
         if(temp->right!=NULL){
             temp=temp->right;
         }
         else{
             temp=temp->left;
         }
         ans1.push_back(temp->data);
     }
     reverse(ans1.begin(), ans1.end());
     ans.insert(ans.end(), ans1.begin(), ans1.end());
     }
     return ans;
}
