vector<int> postOrder(Node* node) {
    // code here
    stack<Node*> s1;
    stack<Node*> s2;
    Node* node1=NULL;
    Node* node2=NULL;
    while(!s1.empty()||node!=NULL){
        if(s2.empty()){
            s1.push(node);
        }
        else if(node1||node2){
            if(node1){
                s1.push(node1);
            }
            if(node2){
                s1.push(node2);
            }
        }
        else if(s1.empty()){
            break;
        }
        Node* temp=s1.top();
        s1.pop();
        s2.push(temp);
        temp=s2.top();
        node1=temp->left;
        node2=temp->right;
    }
    vector<int> ans;
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}
