int SumTree(Node *node){
        if(node==NULL) return 0;
        
        int old= node->data;
        node->data = SumTree(node->left)+SumTree(node->right);
        return old+node->data;
    }
  
    void toSumTree(Node *node)
    {
       SumTree(node);
    }
