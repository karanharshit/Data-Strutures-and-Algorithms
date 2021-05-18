void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* p=NULL;
    Node* s=NULL;
    while(root->key!=key){
        // if(!root->left&&!root->right){
        //     break;
        // }
        if(key<root->key&&root->left){
            s=root;
            root=root->left;
        }
        else if(root->key<key&&root->right){
            p=root;
            root=root->right;
        }
        else{
            break;
        }}
        if(root->key==key){
            if(root->left){
                Node *temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                pre=temp;
            }
            else if(!root->left){
                pre=p;
            }
            
            if(root->right){
                Node*temp=root->right;
                while(temp->left){
                    temp=temp->left;
                }
                suc=temp;
            }
            
            else if(!root->right){
                suc=s;
            }
        }
        else{
            if(root->key<key){
                suc=s;
                pre=root;
            }
            else if(root->key>key){
                pre=p;
                suc=root;
            }
        }    
}
