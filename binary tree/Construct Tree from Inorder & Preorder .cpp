class Solution{
    public:
    int p=0;
    Node* build(int in[], int pre[], int l, int h){
        if(h-l<=0) return NULL;
        
        Node *temp= new Node(pre[p]);

        // temp->data=pre[l];
        // temp->left=NULL;
        // temp->right=NULL;
        
        int index;
        for(int i=l;i<h;i++){
            if(in[i]==pre[p]){
                index=i;
                break;
            }
        }
        p++;
        //cout<<index<<" "<<"haha"<<endl;
        temp->left=build(in,pre,l,index);
        temp->right=build(in,pre,index+1,h);
        return temp;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
       Node *root = build(in,pre,0,n);
       return root;
    }
};
