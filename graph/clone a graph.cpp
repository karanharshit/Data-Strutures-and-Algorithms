class Solution {
public:
    void dfs(Node* copy, Node* node, vector<Node*> &vis){
        vis[(copy->val)]=copy;
        for(auto x:node->neighbors){
            if(vis[(x->val)]==NULL){
                Node * copy1 = new Node(x->val);
                copy->neighbors.push_back(copy1);
                dfs(copy1, x, vis);
            }
            else{
                (copy->neighbors).push_back(vis[(x->val)]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        vector<Node*> vis(1000, NULL);

        Node * copy = new Node(node->val);
        dfs(copy, node, vis);
        return copy;
    }
};
