  public:
     Node *helper(int pre[], int &index, int key, int min, int max, int n){
        if(index>=n) return NULL;
        
        Node *root=NULL;
        if(key> min && key<max){
            root= new Node(key);
            index++;
            
            root->left = helper(pre,index,pre[index],min,key,n);
            root->right = helper(pre,index,pre[index],key,1e9,n);
        }
        return root;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
       int index=0;
       Node *root =helper(pre,index,pre[0],-1e9,1e9,n);
       return root;
    }
